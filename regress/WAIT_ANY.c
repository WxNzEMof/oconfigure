#include "../config.h"

#ifndef _WIN32
#include <sys/wait.h>

int
main(void)
{
#ifdef WAIT_ANY
	return 0;
#else
	return 1;
#endif
}
#else
int main(void) { return 0; }
#endif /* _WIN32 */
