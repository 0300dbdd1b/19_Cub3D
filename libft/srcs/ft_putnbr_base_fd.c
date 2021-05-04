#include "libft.h"

void	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	long int	i;

	i = nbr;
	if (ft_check_base(base) != 0)
	{
		if (i < 0)
		{
			ft_putchar_fd('-', fd);
			i = i * (-1);
		}
		if (i >= (int)ft_strlen(base))
		{
			ft_putnbr_base_fd(i / (int)ft_strlen(base), base, fd);
			ft_putnbr_base_fd(i % (int)ft_strlen(base), base, fd);
		}
		else
			ft_putchar_fd(base[i % (int)ft_strlen(base)], fd);
	}
}
