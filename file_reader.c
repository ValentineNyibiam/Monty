#include "monty.h"

void file_reader(const char *file)
{
    int fd;
	off_t file_len;
	ssize_t ret;
	char *buff;

    /* Open the file */
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	/* Determine the length of the file */
	file_len = lseek(fd, 0, SEEK_END);
	if (file_len == -1)
	{
		printf("Error: Can't open file %s\n", file);
		close(fd);
		exit(EXIT_FAILURE);
	}

	/* Allocate memory for the buffer to read to */
	buff = malloc(file_len);
	if (buff == NULL)
	{
		printf("Error allocating memory");
		free(buff);
		close(fd);
		exit(EXIT_FAILURE);
	}

	/* Reset lseek to zero */
	lseek(fd, 0, SEEK_SET);

	/* Read the content of the file */
	ret = read(fd, buff, file_len);
	if (ret == -1)
	{
		free(buff);
		exit(EXIT_FAILURE);
	}
	buff[file_len] = '\0';
    close(fd);

    tokenize_by_newline(buff);
	free(buff);
}