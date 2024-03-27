# Pretty Messages

## About
A small and customizable header file that allows you to format the messages your program prints out. I developed this header for personal use, so not all code may be "clean".

## Example
```c
#include <prettymsgs.h>

int main(void)
{
    pm_info("This is an %s message.\n", "info");
    pm_debug("This is a %s message.\n", "debug");

    // pm_error and pm_assert will terminate the program.
    pm_error("This is an %s message.\n", "error");
    pm_assert(1 == 2);
}
```

## Usage

These macros must be defined before you include `prettymsgs.h`.

| Macro name | Description |
| --- | --- |
| `PM_IMPLEMENTATION` | Define this to use the macros listed below. |
| `PM_FUNCTION_NAME`  | Used internally by PrettyMessages, but use this to get the nearly portable name of your function. |
| `PM_FPRINTF_FUNCTION` | To use your own `fprintf` function, set this macro to your function. Default will include `stdio.h`. |
| `PM_STDERR_FILE_DESC` | To use your own `stderr` file descriptor (of type `FILE *`), set this macro to your descriptor. Default will be `stderr`. |
| `PM_EXIT_FUNCTION` | To use your own `exit` function, set this macro to your function. Default will include `stdlib.h`. |
| `PM_EXIT_FAILURE` | To use your own `EXIT_FAILURE` exit code, set this macro to your exit code. Default will be `EXIT_FAILURE`. |
| `PM_RESET_COLOR` | To use your own reset ANSI escape sequence, set this macro to your escape sequence. Default will be `\033[39m\033[49m`. |
| `PM_ERROR_COLOR` | To use your own reset ANSI escape sequence, set this macro to your escape sequence. Default will be `\033[38;5;124m`. |
| `PM_WARN_COLOR` | To use your own reset ANSI escape sequence, set this macro to your escape sequence. Default will be `\033[38;5;214m`. |
| `PM_DEBUG_COLOR` | To use your own reset ANSI escape sequence, set this macro to your escape sequence. Default will be `\033[38;5;27m`. |
| `PM_INFO_COLOR` | To use your own reset ANSI escape sequence, set this macro to your escape sequence. Default will be `\033[38;5;66m`. |
| `PM_ERROR_MSG` | To use a custom error message, set this macro to your error message. |
| `PM_WARN_MSG` | To use a custom warn message, set this macro to your warn message. |
| `PM_DEBUG_MSG` | To use a custom debug message, set this macro to your debug message. |
| `PM_INFO_MSG` | To use a custom info message, set this macro to your info message. |
| `PM_DISABLE_ALL_MSGS` | Define this to disable all messages. `pm_error` and `pm_assert` will still be able to terminate the program. |
| `PM_DISABLE_ERROR_MSG` | Define this to disable "error" messages. Error messages will still terminate the program. |
| `PM_DISABLE_WARN_MSG` | Define this to disable "warn" messages. |
| `PM_DISABLE_DEBUG_MSG` | Define this to disable "debug" messages. |
| `PM_DISABLE_INFO_MSG` | Define this to disable "info" messages. |
| `PM_DISABLE_ASSERT_MSG` | Define this to disable "assert" messages. Failed assertions will still terminate the program. |
