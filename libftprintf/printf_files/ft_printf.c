#include "ft_printf.h"


static size_t	fft_strlen(const char *s)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '%')
			{
				counter++;
				i++;
			}
		else
			i += 2;
	}	
	return (counter);
}
void	handle_format(size_t *total_printed, va_list *args, const char *s)
{

}
int ft_printf(const char *s, ...)
{
	size_t	total_printed;
	va_list args;
	
	va_start(args, s);
	helper_fun(&total_printed, &args, s);
	va_end(args);
	return (total_printed);
}
