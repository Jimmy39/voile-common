/**
 * @file voile_common.h
 * @author Jimmy Wang
 * @brief Common part for voile library
 * @version alpha-20240219
 */
#ifndef __VOILE_COMMON_H__
#define __VOILE_COMMON_H__

#include "devicelist.h"

#include <stddef.h>
#include <stdint.h>

#define bool _Bool
#define inROM const

/**
 * @defgroup voile-errorno
 * @brief Reporting and retrieving error conditions
 *
 */

/**
 * @brief Define error number
 *
 * @ingroup voile-errorno
 *
 */
typedef enum {

    // With on error
    success = 0,

    // Unclassified warning
    warning = -1,

    // Hardware support is incomplete
    hardwareUnsupportedWarning = -2,

    // Unclassified error
    error = 1,

    // Function is called with incorrect parameters
    inputRangeError = 2,

    // You are using a feature not supported by the hardware, or configuration in devicelist.h is uncorrect
    hardwareUnsupportedError = 3

} voile_errorno_t;

/**
 * @brief Storage error number
 *
 * @ingroup voile-errorno
 *
 */
extern voile_errorno_t voile_errorno;

/**
 * @brief Define it to use alart output
 *
 * @ingroup voile-errorno
 *
 */
#ifndef microvoile_alart
#define microvoile_Valart(message)
#endif // !microvoile_alart

/**
 * @brief Trigger an error or warning
 *
 * @ingroup voile-errorno
 *
 */
#define microvoile_error(no, message) \
    do {                              \
        voile_errorno = no;           \
        microvoile_alart(message);    \
    } while (0)

/**
 * @brief Trigger an error or warning, can be ignored by ```__VOILE_IGNORE_WORNONG__```
 *
 * @ingroup voile-errorno
 *
 */
#ifdef __VOILE_IGNORE_WORNONG__
#define microvoile_warning(no, message)
#else
#define microvoile_warning(no, message) microvoile_error(no, message)
#endif

#endif // !__VOILE_COMMON_H__
