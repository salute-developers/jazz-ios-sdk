//
//  GlobalStorages.h
//  RedPill
//
//  Created by Аветисян Гагик Арменович on 12.11.2023.
//
// copy-paste from `monolith-ios/browse/RedPill/RedPill`
// with c-prefix `sd_`

#ifndef GlobalStorages_h
#define GlobalStorages_h

#import <stdint.h>

// 32 байт должно хватить для адресации в файле строк до 4 Гб - бесконечный резерв
typedef uint32_t sd_str_index_t;

// Глобальные переменные для хранение буфера адресов и буфера строк.
extern sd_str_index_t *sd_rpl_addressesBuffer;
extern void *sd_rpl_stringsBuffer;

#endif /* GlobalStorages_h */
