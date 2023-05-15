//
//  StringsStorage.h
//  RedPill
//
//  Created by Аветисян Гагик Арменович on 12.11.2023.
//
// copy-paste from `monolith-ios/browse/RedPill/RedPill`
// with c-prefix `sd_`

#ifndef StringsStorage_h
#define StringsStorage_h

#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#import <Foundation/NSException.h>
#include "GlobalStorages.h"

// Копипаст NSCAssert, чтобы не зависить от NS_BLOCK_ASSERT, которые выставляется в конфигурации билда
// Не использую <assert.h>, потому что хз будет ли виден текст из них в крашах.
#define __PRAGMA_PUSH_NO_EXTRA_ARG_WARNINGS \
	_Pragma("clang diagnostic push") \
	_Pragma("clang diagnostic ignored \"-Wformat-extra-args\"")

#define __PRAGMA_POP_NO_EXTRA_ARG_WARNINGS _Pragma("clang diagnostic pop")
#define RPLPrecondition(condition, desc, ...) \
	do {				\
	__PRAGMA_PUSH_NO_EXTRA_ARG_WARNINGS \
	if (__builtin_expect(!(condition), 0)) {		\
		[[NSAssertionHandler currentHandler] handleFailureInFunction:(NSString * _Nonnull)@(__PRETTY_FUNCTION__) \
		file:@(__FILE_NAME__) \
			lineNumber:__LINE__ description:(desc), ##__VA_ARGS__]; \
	}				\
		__PRAGMA_POP_NO_EXTRA_ARG_WARNINGS \
	} while(0)

/*
 Есть два варианта получения доступа к файлу
 1) alloc буфера и read в него.
 2) mmap файла

 Теоретически:
 Плюсы варианта 1) в том что только один syscall read, но минус в том что проиходит alloc достаточно
 большого количества памяти, которая сразу вся не нужна и часть будет выгружена с физическокой RAM и
 снова доставаться по необходимости.
 Вариант 2) лишен минусов варианта 1), но потребует будет выполненно большее количество syscall read,
 так как считывания с диска будет происходить постранично по необходимости.

 Второй вариант интуитивнее кажется более выгодным, на практике так как файлы достаточно маленькие
 особой разницы нет, но первичная инициализация буферов чуть быстрее при варианте с mmap.
 */
static void sd_rpl_init_string_wrapper(const char *addressesPath, const char *stringsPath) {
	struct stat stat;
	int fd;
	int result;
	void *mapped;

	// ------ Чтение файла адресов ------ //
	fd = open(addressesPath, O_RDONLY);
	if (fd < 0)
	{
		RPLPrecondition(false, @"open addresses fail. errno = %d", errno);
	}

	result = fstat(fd, &stat);
	if (result < 0)
	{
		RPLPrecondition(false, @"stat addresses fail. errno = %d", errno);
	}
#if DEBUG || ADHOC
	RPLPrecondition(stat.st_size % 4 == 0, @"Скорее всего некорректный файл, так как он должен содержать массив uint16"
										   @" и соотвественно размер должен быть кратен 4");
#endif

	mapped = mmap(0, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (mapped == MAP_FAILED) {
		RPLPrecondition(false, @"stat addresses fail. errno = %d", errno);
	}
	sd_rpl_addressesBuffer = (sd_str_index_t *)mapped;
	// Файл не закрываем так как система сама будет по необходимости читать из файла постранично (механика mmap)

	// ------ Чтение файла строк ------ //
	fd = open(stringsPath, O_RDONLY);
	if (fd < 0)
	{
		RPLPrecondition(false, @"open strings fail. errno = %d", errno);
	}

#if DEBUG || ADHOC
	sd_str_index_t lastAddress = sd_rpl_addressesBuffer[stat.st_size/4 - 1];
#endif
	result = fstat(fd, &stat);
	if (result < 0)
	{
		RPLPrecondition(false, @"stat strings fail. errno = %d", errno);
	}
#if DEBUG || ADHOC
	RPLPrecondition(stat.st_size == lastAddress, @"Размер файла строк должен быть равен последнему адресу файла адрессов");
#endif

	mapped = mmap(0, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (mapped == MAP_FAILED) {
		RPLPrecondition(false, @"stat addresses fail. errno = %d", errno);
	}
	sd_rpl_stringsBuffer = mapped;
	// Файл не закрываем так как система сама будет по необходимости читать из файла постранично после mmap
}

static inline __attribute__((always_inline)) uint8_t *sd_rpl_get_strings_for_index(sd_str_index_t index, sd_str_index_t *length)
{
	#if DEBUG || ADHOC
	RPLPrecondition(sd_rpl_addressesBuffer != NULL, @"Не проинициализированы адресы");
	RPLPrecondition(sd_rpl_stringsBuffer != NULL, @"Не проинициализированы строки");
	#endif
	*length = sd_rpl_addressesBuffer[index + 1] - sd_rpl_addressesBuffer[index];
	return ( ((uint8_t *)sd_rpl_stringsBuffer) + sd_rpl_addressesBuffer[index] );
}

#endif /* StringsStorage_h */
