#include "ft_printf.h"

int    ft_nbr_arg(const char **counter, va_list *args)
{
    int num_len;
    int i;

    i = va_arg(*args, int);
    ft_putnbr_fd(i, 1);
    num_len = ft_strlen(ft_itoa(i));
    (*counter)++;
    return (num_len);
}