# include <unistd.h>
# include <stdlib.h>
char	*get_next_line(int fd);
char    *ft_trim_lines(char *s);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_endl(const char *s);
char    *ft_strdup(const char *s);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
#ifndef BUFFER_SIZE     
# define BUFFER_SIZE 42
#endif