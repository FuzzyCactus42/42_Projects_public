#include "ft_printf.h"

int    ft_str_arg(const char **counter, va_list *args)
{
    char    *s1;
    int     len;

    s1 = va_arg(*args, char *);
    
    if (!s1)
        s1 = "(null)";

    len = ft_strlen(s1);
    write(1, s1, len);
    (*counter)++;
    return (len);
}