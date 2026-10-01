#include "ft_printf.h"

int    ft_hps_arg(const char **counter)
{
    (*counter)++;
    write(1, "%", 1);
    return (1);
}
