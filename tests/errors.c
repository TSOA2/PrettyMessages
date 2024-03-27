#define PM_IMPLEMENTATION (1)

#include <prettymsgs.h>

int main(void)
{
	int   a = 5293;
	float b = 1259.01;

	pm_error("Uh oh, here's an integer: %d, here's a float: %f\n", a, b);
}

