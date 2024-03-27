#define PM_IMPLEMENTATION (1)

#include <prettymsgs.h>

int main(void)
{
	int   a = 52239;
	float b = 1095.04;
	pm_debug("This is a debug message: %d, %f\n", a, b);
}
