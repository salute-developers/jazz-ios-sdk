#ifndef CMARK_CMARK_CTYPE_H
#define CMARK_CMARK_CTYPE_H

#ifdef __cplusplus
extern "C" {
#endif

/** Locale-independent versions of functions from ctype.h.
 * We want cmark to behave the same no matter what the system locale.
 */

int sddc_cmark_isspace(char c);

int sddc_cmark_ispunct(char c);

int sddc_cmark_isalnum(char c);

int sddc_cmark_isdigit(char c);

int sddc_cmark_isalpha(char c);

#ifdef __cplusplus
}
#endif

#endif
