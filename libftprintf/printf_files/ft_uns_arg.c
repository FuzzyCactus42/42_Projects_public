#include "ft_printf.h"
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
static void	ft_putnbr(unsigned int nb)
{
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

static int count_len(unsigned int n)
{
    unsigned int len;
    
    len = 0;
    while (n)
    {
        len++;
        n = n / 10;
    }
    return (len);
}

unsigned int    ft_uns_arg(const char **counter, va_list *args)
{
    unsigned int  s;
    s = (unsigned int)va_arg(*args, unsigned int);
    (*counter)++;
    ft_putnbr(s);
    s = count_len (s);
    return (s);
}
