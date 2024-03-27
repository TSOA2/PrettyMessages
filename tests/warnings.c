#define PM_IMPLEMENTATION (1)

#include <prettymsgs.h>

int main(void)
{
	int   a = 3259;
	float b = 352.02401;

	pm_warn("This is a warning... very bad.\n");
	pm_warn("Another warning coming right after the last one.\n");
	pm_warn("Hey, here's some numbers: %d, %f\n", a, b);
}

