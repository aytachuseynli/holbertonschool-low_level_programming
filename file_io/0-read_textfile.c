#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - prints text from a file
 * @filename: name of the file
 * @letters: number of characters to read
 *
 * Return: actual number of letters read, 0 if end of file
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (!filename || letters == 0)
		return (0);

	int file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);

	char *buf = malloc(letters);
	if (!buf)
	{
		close(file);
		return (0);
	}

	ssize_t length = read(file, buf, letters);

	if (length == -1 || write(STDOUT_FILENO, buf, length) != length)
	{
		free(buf);
		close(file);
		return (0);
	}

	free(buf);
	close(file);
	return (length);
}
