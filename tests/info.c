#define PM_IMPLEMENTATION (1)

#include <prettymsgs.h>

int main(void)
{
	int   a = 59;
	float b = 195.0325;

	pm_info("This is a test info message.\n");
	pm_info("This is an info message with some numbers: %d, %f\n", a, b);
}
