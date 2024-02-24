#include <sys/stat.h>

#ifndef _WIN32

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int
mkfifoat(int fd, const char *path, mode_t mode)
{
	int	er, curfd = -1, newfd = -1;

	/* Get our current directory then switch to the given one. */

	if (fd != AT_FDCWD) {
		if ((curfd = open(".", O_RDONLY | O_DIRECTORY, 0)) == -1)
			return -1;
		if (fchdir(fd) == -1)
			goto out;
	}

	if ((newfd = mkfifo(path, mode)) == -1)
		goto out;

	/* This leaves the fifo if it fails. */

	if (curfd != -1 && fchdir(curfd) == -1)
		goto out;
	if (curfd != -1)
		close(curfd);

	return newfd;
out:
	/* Ignore errors in close(2). */

	er = errno;
	if (curfd != -1)
		fchdir(curfd);
	if (curfd != -1)
		close(curfd);
	if (newfd != -1)
		close(newfd);
	errno = er;
	return -1;
}

#endif /* _WIN32 */
