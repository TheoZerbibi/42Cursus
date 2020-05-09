#include "master/includes/ft_printf.h"

int main(void)
{
	ft_printf("(|%0*.*d|)",10, -3, -10);
	return (0);
}
