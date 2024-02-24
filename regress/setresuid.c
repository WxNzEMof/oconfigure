#include "../config.h"

#ifndef _WIN32
#include <sys/types.h>
#include <unistd.h>

int
main(void)
{
	uid_t uid = getuid();

	if (setresuid(uid, uid, uid) == -1)
		return 1;
	return 0;
}
#else
int main(void) { return 0; }
#endif /* _WIN32 */
