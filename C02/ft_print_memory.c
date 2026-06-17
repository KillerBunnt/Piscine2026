/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdexmun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:24:13 by thdexmun          #+#    #+#             */
/*   Updated: 2026/06/17 16:19:26 by thdexmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_print_hex(int *dec, int size);

void	ft_print_val_hex(char c)
{
	int	dec;

	dec = (int)c;
	ft_print_hex(&dec, 1);
}

void	ft_print_val(char *str, unsigned int size)
{
	unsigned int	index;
	unsigned int	count;

	index = 0;
	count = 0;
	write(1, " ", 1);
	if (str[0] && size == 0)
		size = 16;
	while (index < size && count < 16)
	{
		if (str[index] >= ' ' && str[index] <= '~')
			write(1, &(str[index]), 1);
		else
			write(1, ".", 1);
		index++;
	}
	write(1, "\n", 1);
}

void	ft_print_hex(int *dec, int size)
{
	char	*hex;
	char	out[2];
	int		index;
	int		store;

	hex = "0123456789abcdef";
	index = 0;
	store = 0;
	while (index < size)
	{
		store = dec[index];
		out[0] = hex[store / 16];
		out[1] = hex[store % 16];
		write(1, out, 2);
		index++;
	}
}

void	ft_print_addr(unsigned long long addr)
{
	int		full_addr[8];
	int		index;

	index = 7;
	while (addr)
	{
		full_addr[index] = addr & 255;
		addr >>= 8;
		index--;
	}
	while (index >= 0)
		full_addr[index--] = 0;
	ft_print_hex(full_addr, 8);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		count;
	unsigned int		index;
	unsigned int		inner_index;
	char				*str;

	index = 0;
	str = (char *)addr;
	while (index < size)
	{
		count = 0;
		ft_print_addr((unsigned long long)(&(addr[index])));
		write(1, ":", 1);
		inner_index = index;
		while (count < 16)
		{
			if (count++ % 2 == 0)
				write(1, " ", 1);
			if (index < size)
				ft_print_val_hex(str[index++]);
			else
				write(1, "  ", 2);
		}
		ft_print_val(&(str[inner_index]), index % 16);
	}
	return (addr);
}

int main()
{
	char *str = "Bonjour les aminches	\n	c␇ est fou	tout	ce qu on peut faire avec	\n\nprint_memory\n\n\n	lol.lol\n ";
	ft_print_memory((void *)str, 92);
}

