#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	*digits;
	char	out[10];
	int		nbs;
	int		offset;

	offset = 9;
	digits = "0123456789";
	if (nb < 0)
		ft_putchar('-');
	while (nb / 10 != 0)
	{
		nbs = nb % 10;
		if (nbs < 0)
			nbs *= -1;
		out[offset] = digits[nbs];
		nb /= 10;
		offset--;
	}
	nbs = nb % 10;
	if (nbs < 0)
		nbs *= -1;
	out[offset] = digits[nbs];
	write(1, &out[offset], 10 - offset);
}

// int main()
// {
// 	ft_putnbr(-2147483648);
// 	ft_putchar('\n');
// 	ft_putnbr(2147483647);
// 	ft_putchar('\n');
// 	ft_putnbr(0);
// 	ft_putchar('\n');
// 	ft_putnbr(123123);
// 	ft_putchar('\n');
// 	ft_putnbr(-287323);
// 	ft_putchar('\n');
// }