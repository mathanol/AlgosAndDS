#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[]) {

	const char *f_name = "mmap.c";
	struct stat sbuf;
	int fd, offset, pagesize, i;
	char *data;

	if (argc != 2) {
		fprintf(stderr, "usage: %s <offset\n", argv[0]);
		return 1;
	}

	if ((fd = open(f_name, O_RDONLY)) == -1) {
		perror("open");
		return 1;
	};

	if (stat(f_name, &sbuf) == -1) {
		perror("stat");
		return 1;
	}

	offset = atoi(argv[1]);
	if (offset < 0 || offset > sbuf.st_size - 1) {
		fprintf(stderr, "Invlaid offset specified. Valid = [0,%lld]\n", sbuf.st_size - 1);
		return 0;
	}

	pagesize = getpagesize();
	data = mmap((caddr_t)0, sbuf.st_size, PROT_READ, MAP_SHARED, fd, 0);

	if (data == (caddr_t)(-1)) {
		perror("mmap failed");
		return 1;
	}

	printf("byte at offset %d is '%c'\n", offset, data[offset]);

	if (munmap(data, pagesize) == -1) {
		perror("munmap failed");
		return 1;
	}
	return 0;
}
