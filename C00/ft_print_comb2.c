#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putdigits(int dig1, int dig2)
{
	char	*digits;

	digits = "0123456789";
	ft_putchar(digits[dig1]);
	ft_putchar(digits[dig2]);
}

void	ft_print_comb2(void)
{
	int		dig1;
	int		dig2;

	dig1 = 0;
	dig2 = 1;
	while (dig1 <= 98)
	{
		while (dig2 <= 99)
		{
			ft_putdigits(dig1 / 10, dig1 % 10);
			write(1, " ", 1);
			ft_putdigits(dig2 / 10, dig2 % 10);
			if (dig1 == 98 && dig2 == 99)
				return ;
			write(1, ", ", 2);
			dig2++;
		}
		dig1++;
		dig2 = dig1 + 1;
	}
}

// int main()
// {
// 	ft_print_comb2();
// }