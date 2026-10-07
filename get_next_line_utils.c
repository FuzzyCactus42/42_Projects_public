#include "get_next_line.h"

char    *ft_strdup(const char *s)
{
        char    *str;
        int             i;

        i = 0;
        while (s[i] != '\0')
                i++;
        str = malloc((i + 1) * sizeof(char));
        if (str == NULL)
                return ("");
        i = 0;
        while (s[i] != '\0')
        {
                str[i] = s[i];
                i++;
        }
        str[i] = '\0';
        return (str);
}

char *ft_trim_lines(char *s)
{
    char    *p;
    char    *temp;
    int i;

    i = 0;
    p = malloc (ft_strlen(s) + 1);
    while (s[i] != '\n')
    {
        p[i] = s[i];
        i++;
    }
    p[i++] = '\0';
    temp = ft_strdup(s + i);
    free(s);
    s = ft_strdup(temp + i);
    return (p);
}


size_t	ft_strlen_endl(const char *s)
{
	size_t	i;  

	i = 0;
	while (!(s[i] == '\n' || s[i] == '\0'))//the defferance
	{
		i++;
	}
	return (i);
}
size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
        size_t  src_len;
        size_t  i;

        src_len = ft_strlen(src);
        if (size == 0)
                return (src_len);
        i = 0;
        while (src[i] != '\0' && i < size - 1)
        {
                dst[i] = src[i];
                i++;
        }
        dst[i] = '\0';
        return (src_len);
}
size_t ft_strlen(const char *s)
{
	size_t	i;  

	i = 0;
	while (s[i] != '\0')//the defferance
	{
		i++;
	}
	return (i);
}
