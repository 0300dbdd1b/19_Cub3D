#include "libft.h"

void	ft_putstr(char *str)
{
	if (str != NULL)
		write(1, str, ft_strlen(str));
}
