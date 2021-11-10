#pragma once

#include <assert.h>
#include <string.h>

void clean(char const * src, char* dst) {
    while(*src) {
        if(*src == '0' || *src == '1') {
            *dst = *src;
            dst++;
        }
        src++;
    }
    strcpy(dst, src);
}

unsigned int b(char const * bitmask) {
    unsigned int result = 0;
    char cleaned[80];
    clean(bitmask, cleaned);
    size_t bitmask_length = strlen(cleaned);
    for(int i=0; i < bitmask_length; i++)
    {
        unsigned int ix = bitmask_length - i - 1;
        unsigned int value = 1 << i;
        if(cleaned[ix] == '1') {
            result += value;
        }
    }
    return result;
}

void test_bitmask() {
    assert(1 == b("1"));
    assert(1 == b("01"));
    assert(2 == b("10"));
    assert(255 == b("11111111"));
    assert(255 == b("1111'1111"));
    assert(0xFFFF == b("1111'1111'1111'1111"));
    assert(0xFFFD == b("1111'1111'1111'1101"));
}
