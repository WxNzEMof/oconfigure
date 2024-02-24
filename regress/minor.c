#include "../config.h"

#ifndef _WIN32
#include <sys/types.h>
#include COMPAT_MAJOR_MINOR_H

int
main(void)
{
	minor(0);
	return 0;
}
#else
int main(void) { return 0; }
#endif /* _WIN32 */
