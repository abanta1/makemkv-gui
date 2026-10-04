/*
    Written by GuinpinSoft inc <oss@makemkv.com>

    This file is hereby placed into public domain,
    no copyright is claimed.

*/
#include <stdint.h>

typedef uint16_t    utf16_t;
typedef char        utf8_t;

size_t utf16toutf8len(const uint16_t *src_string);
size_t utf8toutf16len(const char *src_string);
size_t utf16toutf8(char *dst_string, size_t dst_len, const uint16_t *src_string, size_t src_len);
size_t utf8toutf16(uint16_t *dst_string, size_t dst_len, const char *src_string, size_t src_len);
size_t utf16len(const uint16_t *SrcString);

