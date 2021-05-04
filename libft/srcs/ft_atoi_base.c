#include "libft.h"

static int	ft_search_index(char index, char *base)
{
	int	x;

	x = 0;
	while (base[x])
	{
		if (index == base[x])
			return (x);
		x++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	long int	neg;
	long int	nb;
	long int	x;

	neg = 1;
	x = 0;
	nb = 0;
	if (ft_check_base(base) != 0)
	{
		while (str[x] == '\t' || str[x] == '\v' || str[x] == '\n'
			 || str[x] == '\r' || str[x] == '\f' || str[x] == ' ')
			x++;
		while (str[x] == '-' || str[x] == '+')
		{
			if (str[x++] == '-')
				neg *= (-1);
		}
		while (str[x] && ft_search_index(str[x], base) != -1)
			nb = nb * ft_strlen(base) + ft_search_index(str[x++], base);
		nb *= neg;
		return ((int)nb);
	}
	return (0);
}
