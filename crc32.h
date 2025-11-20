
#ifndef _CRC32_H_
#define _CRC32_H_

#if defined(__C51__)
#include "defines.h"
#else
#include <stdint.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__C51__)
uint32_t crc32(uint32_t crc, uint32_t addr, uint32_t len);
#else
uint32_t crc32(uint32_t crc, const uint8_t *buf, uint32_t len);
#endif

#ifdef __cplusplus
}
#endif

#endif //_CRC32_H_
