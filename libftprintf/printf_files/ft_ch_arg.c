#include "ft_printf.h"

int    ft_ch_arg(const char **counter, va_list *args)
{
    char    s;

    s = (unsigned char)(va_arg(*args, int));
    write(1, &s, 1);
    (*counter)++;
    return (1);
}