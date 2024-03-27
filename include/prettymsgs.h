#ifndef PRETTY_MESSAGES_HEADER
#define PRETTY_MESSAGES_HEADER

#ifdef PM_IMPLEMENTATION

/*
 * TODO
 * Simplify this
 */

#if defined(__clang__)

#define PM_FUNCTION_NAME __PRETTY_FUNCTION__

/*
 * TODO
 * Apple Clang is a bit confusing, but fix it in the future.
 */

#ifdef __APPLE__

#define pm_debug_likely(x) (x)
#define pm_debug_unlikely(x) (x)

#else

#if __has_builtin(__builtin_expect)
#define pm_debug_likely(x) __builtin_expect(!!(x), 1)
#define pm_debug_unlikely(x) __bulitin_expect(!!(x), 0)
#else
#define pm_debug_likely(x) (x)
#define pm_debug_unlikely(x) (x)
#endif // __has_builtin(__builtin_expect)

#endif // defined(__APPLE__)

#elif defined(__GNUC__)
#define PM_FUNCTION_NAME __PRETTY_FUNCTION__

#define pm_debug_likely(x) __builtin_expect(!!(x), 1)
#define pm_debug_unlikely(x) __builtin_expect(!!(x), 0)

#else

#define pm_debug_likely(x) (x)
#define pm_debug_unlikely(x) (x)

#endif // defined(__clang__)

#if defined(_MSC_VER) || defined(_MSC_FULL_VER)
#define PM_FUNCTION_NAME __FUNCSIG__
#endif // defined(_MSC_VER) || defined(_MSC_FULL_VER)

#ifndef PM_FUNCTION_NAME
#define PM_FUNCTION_NAME __FUNCTION__
#endif // PM_FUNCTION_NAME

#ifndef PM_FPRINTF_FUNCTION
#include <stdio.h>
#define PM_FPRINTF_FUNCTION fprintf
#endif // PM_FPRINTF_FUNCTION

#ifndef PM_STDERR_FILE_DESC
#define PM_STDERR_FILE_DESC stderr
#endif // PM_STDERR_FILE_DESC

#ifndef PM_EXIT_FUNCTION
#include <stdlib.h>
#define PM_EXIT_FUNCTION exit
#endif // PM_EXIT_FUNCTION

#ifndef PM_EXIT_FAILURE
#define PM_EXIT_FAILURE (EXIT_FAILURE)
#endif // PM_EXIT_FAILURE

#ifndef PM_RESET_COLOR
#define PM_RESET_COLOR "\033[39m\033[49m"
#endif // PM_RESET_COLOR
#ifndef PM_ERROR_COLOR
#define PM_ERROR_COLOR "\033[38;5;124m" // Red
#endif // PM_ERROR_COLOR
#ifndef PM_WARN_COLOR
#define PM_WARN_COLOR  "\033[38;5;214m" // Orange
#endif // PM_WARN_COLOR
#ifndef PM_DEBUG_COLOR
#define PM_DEBUG_COLOR "\033[38;5;27m"  // Blue
#endif // PM_DEBUG_COLOR
#ifndef PM_INFO_COLOR
#define PM_INFO_COLOR  "\033[38;5;66m"  // Bluish-grey
#endif // PM_INFO_COLOR

#ifndef PM_ERROR_MSG
#define PM_ERROR_MSG   PM_ERROR_COLOR "[ERROR]"  PM_RESET_COLOR ": "
#endif // PM_ERROR_MSG
#ifndef PM_WARN_MSG
#define PM_WARN_MSG    PM_WARN_COLOR  "[WARN]"   PM_RESET_COLOR ": "
#endif // PM_WARN_MSG
#ifndef PM_DEBUG_MSG
#define PM_DEBUG_MSG   PM_DEBUG_COLOR "[DEBUG]"  PM_RESET_COLOR ": "
#endif // PM_DEBUG_MSG
#ifndef PM_INFO_MSG
#define PM_INFO_MSG    PM_INFO_COLOR  "[INFO]"   PM_RESET_COLOR ": "
#endif // PM_INFO_MSG
#ifndef PM_ASSERT_MSG
#define PM_ASSERT_MSG  PM_ERROR_COLOR "[ASSERT]" PM_RESET_COLOR ": "
#endif // PM_ASSERT_MSG


/******** ERRORS ********/
#if defined(PM_DISABLE_ERROR_MSG) || defined(PM_DISABLE_ALL_MSGS)

#define pm_error(m, ...) \
	do { \
		PM_EXIT_FUNCTION(PM_EXIT_FAILURE); \
	} while (0)

#else

#define pm_error(m, ...) \
	do { \
		(void) PM_FPRINTF_FUNCTION(PM_STDERR_FILE_DESC, PM_ERROR_MSG m, ##__VA_ARGS__); \
		PM_EXIT_FUNCTION(PM_EXIT_FAILURE); \
	} while (0)

#endif // defined(PM_DISABLE_ERROR_MSG) || defined(PM_DISABLE_ALL_MSGS)


/******** WARNINGS ********/
#if defined(PM_DISABLE_WARN_MSG) || defined(PM_DISABLE_ALL_MSGS)

#define pm_warn(m, ...) \
	do { \
		; \
	} while (0)

#else

#define pm_warn(m, ...) \
	do { \
		(void) PM_FPRINTF_FUNCTION(PM_STDERR_FILE_DESC, PM_WARN_MSG m, ##__VA_ARGS__); \
	} while (0)

#endif // defined(PM_DISABLE_WARN_MSG) || defined(PM_DISABLE_ALL_MSGS)


/******** DEBUG ********/
#if defined(PM_DISABLE_DEBUG_MSG) || defined(PM_DISABLE_ALL_MSGS)

#define pm_debug(m, ...) \
	do { \
		; \
	} while (0)

#else

#define pm_debug(m, ...) \
	do { \
		(void) PM_FPRINTF_FUNCTION(PM_STDERR_FILE_DESC, PM_DEBUG_MSG m, ##__VA_ARGS__); \
	} while (0)

#endif // defined(PM_DISABLE_DEBUG_MSG) || defined(PM_DISABLE_ALL_MSGS)


/******** INFO ********/
#if defined(PM_DISABLE_INFO_MSG) || defined(PM_DISABLE_ALL_MSGS)

#define pm_info(m, ...) \
	do { \
		; \
	} while (0)

#else

#define pm_info(m, ...) \
	do { \
		(void) PM_FPRINTF_FUNCTION(PM_STDERR_FILE_DESC, PM_INFO_MSG m, ##__VA_ARGS__); \
	} while (0)

#endif // defined(PM_DISABLE_INFO_MSG) || (PM_DISABLE_ALL_MSGS == 0)


/******** ASSERT ********/
#if defined(PM_DISABLE_ASSERT_MSG) || defined(PM_DISABLE_ALL_MSGS)

#define pm_assert(x) \
	do { \
		if (pm_debug_unlikely(!(x))) { \
			PM_EXIT_FUNCTION(PM_EXIT_FAILURE); \
		} \
	} while (0)

#else

#define pm_assert(x) \
	do { \
		if (pm_debug_unlikely(!(x))) { \
			(void) PM_FPRINTF_FUNCTION( \
				PM_STDERR_FILE_DESC, \
				PM_ASSERT_MSG \
				"Assertion failed: (%s)\n" \
				"\tFile: %s:%d, Function: %s\n" \
				,#x \
			   	,__FILE__ \
				,__LINE__ \
				,PM_FUNCTION_NAME\
			); \
			PM_EXIT_FUNCTION(PM_EXIT_FAILURE); \
		} \
	} while (0)

#endif // defined(PM_DISABLE_ASSERT_MSG) || defined(PM_DISABLE_ALL_MSGS)

#endif // defined(PM_IMPLEMENTATION)?

#endif // PRETTY_MESSAGES_HEADER
