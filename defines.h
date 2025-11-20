#ifndef _DEFINES_H_
#define _DEFINES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>     ///< Standard input/output library
#if defined(__C51__)
typedef unsigned char       uint8_t;
typedef signed char         int8_t;
typedef unsigned short      uint16_t;
typedef signed short        int16_t;
typedef unsigned long       uint32_t;
typedef signed long         int32_t;

#define bool _Bool
#define true 1
#define false 0
typedef unsigned char _Bool;
#else
#include <stdint.h>    ///< Standard integer types
#include <stdbool.h>   ///< Boolean type and values
#endif

#define SHA1_BUFFER_SIZE                         		20  // Size of the buffer used for SHA1 (if used)
#ifndef NULL
#define NULL ((void *)0)
#endif
#ifndef ext
#define ext
#endif

#if defined(__CC_ARM)
    /** 
     * @brief Inline keyword for ARM Compiler.
     */
    #define __ARIES_SDK_INLINE                         __inline

    /**
     * @brief Static inline keyword for ARM Compiler.
     */
    #define __ARIES_SDK_STATIC_INLINE                  static __inline
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
    /** 
     * @brief Inline keyword for ARM Compiler version 6.1 and above.
     */
    #define __ARIES_SDK_INLINE                         __inline

    /**
     * @brief Static inline keyword for ARM Compiler version 6.1 and above.
     */
    #define __ARIES_SDK_STATIC_INLINE                  static __inline
#elif defined ( __GNUC__ )
    /** 
     * @brief Inline keyword for GNU Compiler.
     */
    #define __ARIES_SDK_INLINE                        inline

    /**
     * @brief Static inline keyword for GNU Compiler.
     */
    #define __ARIES_SDK_STATIC_INLINE                 static inline
#elif defined ( __C51__ )
    /** 
     * @brief Inline keyword for Keil C51 Compiler.
     */
    #define __ARIES_SDK_INLINE                         

    /**
     * @brief Static inline keyword for Keil C51 Compiler.
     */
    #define __ARIES_SDK_STATIC_INLINE                  
#else
    /**
     * @brief Fallback definition for inline keyword if no known compiler is detected.
     */
    #define __ARIES_SDK_INLINE

    /**
     * @brief Fallback definition for static inline keyword if no known compiler is detected.
     */
    #define __ARIES_SDK_STATIC_INLINE
#endif

/**
 * @brief Extracts the 0th byte (least significant byte) from a word.
 * 
 * @param d Word from which to extract the byte.
 * @return The least significant byte of the word.
 */
#define BYTE0(d)                                    ((BYTE)(d))

/**
 * @brief Extracts the 1st byte from a word.
 * 
 * @param d Word from which to extract the byte.
 * @return The second least significant byte of the word.
 */
#define BYTE1(d)                                    ((BYTE)((d) >> 8))

/**
 * @brief Extracts the 2nd byte from a word.
 * 
 * @param d Word from which to extract the byte.
 * @return The third least significant byte of the word.
 */
#define BYTE2(d)                                    ((BYTE)((d) >> 16))

/**
 * @brief Extracts the 3rd byte (most significant byte in a 32-bit word) from a word.
 * 
 * @param d Word from which to extract the byte.
 * @return The most significant byte of the word.
 */
#define BYTE3(d)                                    ((BYTE)((d) >> 24))

/**
 * @brief Marks a variable as unused to suppress compiler warnings.
 * 
 * @param x The variable to be marked as unused.
 * 
 * This macro is used when you need to declare a variable that is intentionally unused 
 * in your code, for instance, when implementing functions with specific signatures 
 * where not all parameters are used. It assigns the variable to itself, effectively 
 * ensuring the variable is considered 'used' by the compiler.
 */
#define UNUSED(x)                                   ((x) = (x))

/**
 * @brief Swaps the bytes of a 16-bit value.
 * 
 * @param value Value to swap the bytes of.
 * @return The value with its bytes swapped.
 */
#define SWAP_BYTES_16(value)                        (((value) << 8) | ((value) >> 8))

/**
 * @brief Swaps the bytes of a 32-bit value.
 * 
 * @param value Value to swap the bytes of.
 * @return The value with its bytes swapped.
 */
#define SWAP_BYTES_32(value)                        ( \
                                                        (((value) << 24) & 0xFF000000) | \
                                                        (((value) << 8)  & 0x00FF0000) | \
                                                        (((value) >> 8)  & 0x0000FF00) | \
                                                        (((value) >> 24) & 0x000000FF)   \
                                                    )

/**
 * @brief Swaps the bytes of a 16-bit value.
 * 
 * @param value Value to swap the bytes of.
 * @return The value with its bytes swapped.
 */
#define SWAP_BYTES(value)                           ( \
                                                        (sizeof(value) == 2) ? SWAP_BYTES_16(value) : \
                                                        (sizeof(value) == 4) ? SWAP_BYTES_32(value) : (value) \
                                                    )

#ifdef __cplusplus
}
#endif
#endif // _DEFINES_H_
