#include "minitalk.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

void	ft_putstr(char *string)
{
	while (*string)
	{
		write(1, &(*string), 1);
		string++;
	}
}

void	put_spaces(int number)
{
	int	i;

	i = 0;
	if (number == 0)
		i = 1;
	else
	{
		while (number)
		{
			number /= 10;
			i++;
		}
	}
	i = 8 - i;
	while (i)
	{
		write(1, " ", 1);
		i--;
	}
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	nbr;
	unsigned long	overflow;

	nbr = 0;
	sign = 1;
	i = 0;
	overflow = 922337203685477580;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((nbr > overflow || (nbr == overflow
					&& str[i] > '7')) && sign == 1)
			return (-1);
		else if ((nbr > overflow || (nbr == overflow
					&& str[i] > '8')) && sign == -1)
			return (0);
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	return (nbr * sign);
}

void	message(int type)
{
	if (type == 1)
		write(1, RED"✘✘✘ You entered wrong number of arguments! ✘✘✘\n"
			CLR_RESET, 68);
	else if (type == 2)
		write(1, RED"✘✘✘ Wrong PID detected! ✘✘✘\n"CLR_RESET, 49);
	else if (type == 3)
		write(1, RED"✘✘✘ Sigaction function failed! ✘✘✘\n"CLR_RESET, 56);
	else if (type == 4)
		write(1, RED"✘✘✘ Kill function failed! ✘✘✘\n"CLR_RESET, 51);
	exit(1);
}
