#include "get_next_line.h"

char	*free_all(char *ptr)
{
	free(ptr);
	ptr = NULL;
	return (NULL);
}

char	*print_new_line(char *storage)
{
	char	*line;
	char	*ptr;
	size_t	len;

	if (!storage)
		return (NULL);
	ptr = ft_strchr(storage, '\n');
	if (!ptr)
	{
		line = ft_strdup(storage);
		if (!line)
			return (NULL);
		return (line);
	}
	len = ptr - storage;
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, storage, len + 2);
	return (line);
}

char	*fix_storage(char *storage, ssize_t bytes)
{
	char	*ptr;
	char	*temp;

	if (!storage)
		return (NULL);
	ptr = ft_strchr(storage, '\n');
	if (!ptr && (bytes == 0 || bytes < BUFFER_SIZE))
		return (free_all(storage));
	if (!ptr)
		return (storage);
	ptr++;
	temp = storage;
	storage = ft_strdup(ptr);
	free(temp);
	temp = NULL;
	return (storage);
}

char	*build_storage(char *storage, char *buffer, size_t bytes)
{
	char	*new_storage;
	char	*temp;

	buffer[bytes] = '\0';
	temp = storage;	
	new_storage = ft_strjoin(storage, buffer);
	free_all(temp);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t	bytes;

	if (fd < 0)
		return (NULL);
	while (!ft_strchr(storage, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free_all(storage));
		if (bytes == 0)
			break;
		storage = build_storage(storage, buffer, bytes);
		if (!storage)
			return (NULL);
	}
	line = print_new_line(storage);
	storage = fix_storage(storage, bytes);
	return (line);
}
