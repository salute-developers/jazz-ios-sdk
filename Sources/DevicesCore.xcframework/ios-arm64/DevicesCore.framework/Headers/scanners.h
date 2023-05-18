#include "cmark.h"
#include "chunk.h"

#ifdef __cplusplus
extern "C" {
#endif

bufsize_t sddc__scan_at(bufsize_t (*scanner)(const unsigned char *), cmark_chunk *c,
                   bufsize_t offset);
bufsize_t sddc__scan_scheme(const unsigned char *p);
bufsize_t sddc__scan_autolink_uri(const unsigned char *p);
bufsize_t sddc__scan_autolink_email(const unsigned char *p);
bufsize_t sddc__scan_html_tag(const unsigned char *p);
bufsize_t sddc__scan_html_block_start(const unsigned char *p);
bufsize_t sddc__scan_html_block_start_7(const unsigned char *p);
bufsize_t sddc__scan_html_block_end_1(const unsigned char *p);
bufsize_t sddc__scan_html_block_end_2(const unsigned char *p);
bufsize_t sddc__scan_html_block_end_3(const unsigned char *p);
bufsize_t sddc__scan_html_block_end_4(const unsigned char *p);
bufsize_t sddc__scan_html_block_end_5(const unsigned char *p);
bufsize_t sddc__scan_link_title(const unsigned char *p);
bufsize_t sddc__scan_spacechars(const unsigned char *p);
bufsize_t sddc__scan_atx_heading_start(const unsigned char *p);
bufsize_t sddc__scan_setext_heading_line(const unsigned char *p);
bufsize_t sddc__scan_open_code_fence(const unsigned char *p);
bufsize_t sddc__scan_close_code_fence(const unsigned char *p);
bufsize_t sddc__scan_entity(const unsigned char *p);
bufsize_t sddc__scan_dangerous_url(const unsigned char *p);

#define scan_scheme(c, n) sddc__scan_at(&sddc__scan_scheme, c, n)
#define scan_autolink_uri(c, n) sddc__scan_at(&sddc__scan_autolink_uri, c, n)
#define scan_autolink_email(c, n) sddc__scan_at(&sddc__scan_autolink_email, c, n)
#define scan_html_tag(c, n) sddc__scan_at(&sddc__scan_html_tag, c, n)
#define scan_html_block_start(c, n) sddc__scan_at(&sddc__scan_html_block_start, c, n)
#define scan_html_block_start_7(c, n) sddc__scan_at(&sddc__scan_html_block_start_7, c, n)
#define scan_html_block_end_1(c, n) sddc__scan_at(&sddc__scan_html_block_end_1, c, n)
#define scan_html_block_end_2(c, n) sddc__scan_at(&sddc__scan_html_block_end_2, c, n)
#define scan_html_block_end_3(c, n) sddc__scan_at(&sddc__scan_html_block_end_3, c, n)
#define scan_html_block_end_4(c, n) sddc__scan_at(&sddc__scan_html_block_end_4, c, n)
#define scan_html_block_end_5(c, n) sddc__scan_at(&sddc__scan_html_block_end_5, c, n)
#define scan_link_title(c, n) sddc__scan_at(&sddc__scan_link_title, c, n)
#define scan_spacechars(c, n) sddc__scan_at(&sddc__scan_spacechars, c, n)
#define scan_atx_heading_start(c, n) sddc__scan_at(&sddc__scan_atx_heading_start, c, n)
#define scan_setext_heading_line(c, n)                                         \
  sddc__scan_at(&sddc__scan_setext_heading_line, c, n)
#define scan_open_code_fence(c, n) sddc__scan_at(&sddc__scan_open_code_fence, c, n)
#define scan_close_code_fence(c, n) sddc__scan_at(&sddc__scan_close_code_fence, c, n)
#define scan_entity(c, n) sddc__scan_at(&sddc__scan_entity, c, n)
#define scan_dangerous_url(c, n) sddc__scan_at(&sddc__scan_dangerous_url, c, n)

#ifdef __cplusplus
}
#endif
