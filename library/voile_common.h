/**
 * @file voile_common.h
 * @author Jimmy Wang
 * @brief Common denpence for voile library
 * @version alpha-20240215
 */
#ifndef __VOILE_COMMON_H__
#define __VOILE_COMMON_H__

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

    // Unclassified failure
    failure = 1,

    // Function is called with incorrect parameters
    inputRangeError = 2,

    // Function is unsupport, or devicelist set uncorrect
    hardwareUnsupportedError = 3

} voile_errorno_t;

/**
 * @brief Storage error number
 *
 * @ingroup voile-errorno
 *
 */
extern voile_errorno_t voile_errorno;

#endif // !__VOILE_COMMON_H__
