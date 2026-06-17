/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdexmun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:55:55 by thdexmun          #+#    #+#             */
/*   Updated: 2026/06/10 16:07:16 by thdexmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//note to dex: complete this and the rest. this is c00 ex05

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_increment(int *a, int *b, int *c, int mode)
{
	if (mode == 1)
	{
		(*b)++;
		*c = *b + 1;
	}
	else
	{
		(*a)++;
		*b = *a + 1;
		*c = *b + 1;
	}
}

int	ft_writedigs(int a, int b, int c)
{
	char	*digits;

	digits = "0123456789";
	ft_putchar(digits[a]);
	ft_putchar(digits[b]);
	ft_putchar(digits[c]);
	if (a == b - 1 && b == c - 1 && c == 9)
		return (1);
	write (1, ", ", 2);
	return (0);
}

void	ft_print_comb(void)
{
	int		dig_i1;
	int		dig_i2;
	int		dig_i3;

	dig_i1 = 0;
	dig_i2 = 1;
	dig_i3 = 2;
	while (dig_i1 <= 7)
	{
		while (dig_i2 <= 8)
		{
			while (dig_i3 <= 9)
			{
				if (ft_writedigs(dig_i1, dig_i2, dig_i3))
					return ;
				dig_i3++;
			}
			ft_increment(&dig_i1, &dig_i2, &dig_i3, 1);
		}
		ft_increment(&dig_i1, &dig_i2, &dig_i3, 2);
	}
}

// int main()
// {
// 	ft_print_comb();
// }