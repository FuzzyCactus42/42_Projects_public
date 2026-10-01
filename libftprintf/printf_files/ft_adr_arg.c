#include "ft_printf.h"

static unsigned char	format(unsigned char f) // 10
{
	if (f % 16 == 10)
		return ('a');
	if (f % 16 == 11)
		return ('b');
	if (f % 16 == 12)
		return ('c');
	if (f % 16 == 13)
		return ('d');
	if (f % 16 == 14)
		return ('e');
	if (f % 16 == 15)
		return ('f');
	else
		return (f + '0');	
}

static void	write_hex(size_t hex_num, size_t num, size_t *counter1)
{
	unsigned char ch;

		hex_num = num % 16;
		num = num / 16;
		ch = format(hex_num);
		if (num != 0)
			write_hex(hex_num, num, counter1 );
		write(1, &ch, 1);
		(*counter1)++;
}

int    ft_adr_arg(const char **counter, va_list *args)
{
	unsigned int	num;
	size_t	hex_num;
	size_t	counter1;

	counter1 = 2;
	hex_num = 0;
	(*counter)++;
	num = (int)va_arg(*args, int);
	if (num == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2); 
	write_hex(hex_num, num, &counter1);
	return (counter1);
}