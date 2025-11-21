#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char    *get_next_line(int fd);
char	*build_storage(char *storage, char *buffer, size_t bytes);
char	*fix_storage(char *storage, ssize_t bytes);
char	*print_new_line(char *storage);
char	*free_all(char *ptr);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char *ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
