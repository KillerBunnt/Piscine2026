/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdexmun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 17:27:42 by thdexmun          #+#    #+#             */
/*   Updated: 2026/06/19 18:04:30 by thdexmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*skip_whites(char *str)
{
	int		index;
	int		skip_index;
	int		con;
	char	*whites;

	index = 0;
	whites = " \t\n\v\f\r";
	while (str[index])
	{
		con = 0;
		skip_index = 0;
		while (whites[skip_index])
		{
			if (str[index] == whites[skip_index])
				con = 1;
			skip_index++;
		}
		if (!con)
			break ;
		index++;
	}
	return (&(str[index]));
}

void	init_set_sign(char *str, int *out, unsigned int *index)
{
	out[0] = 0;
	out[1] = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			out[1] = -1;
		(*index)++;
	}
}

int	ft_atoi(const char *str)
{
	char			*skipped;
	unsigned int	index;
	int				out[2];

	index = 0;
	skipped = skip_whites((char *)str);
	init_set_sign(skipped, out, &index);
	while (skipped[index])
	{
		if (skipped[index] >= '0' && skipped[index] <= '9')
			out[0] = out[0] * 10 + (skipped[index] - '0');
		else
			break ;
		index++;
	}
	out[0] *= out[1];
	return (out[0]);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *s1 = "1234567890";
	char *s2 = "+1234567890";
	char *s3 = "-1234567890";
	char *s4 = "-1234567890 ";
	char *s5 = " +1234567890 ";
	char *s6 = " -1234\n567890 ";
	char *s7 = "        -1234567890         ";
	char *s8 = "-1234567890         ";
	char *s9 = "                 1234567890";
	char *s10 = "";

	printf("original s1:	%d\n", atoi(s1));
	printf("ft_atoi s1:	%d\n", ft_atoi(s1));
	printf("original s2:	%d\n", atoi(s2));
	printf("ft_atoi s2:	%d\n", ft_atoi(s2));
	printf("original s3:	%d\n", atoi(s3));
	printf("ft_atoi s3:	%d\n", ft_atoi(s3));
	printf("original s4:	%d\n", atoi(s4));
	printf("ft_atoi s4:	%d\n", ft_atoi(s4));
	printf("original s5:	%d\n", atoi(s5));
	printf("ft_atoi s5:	%d\n", ft_atoi(s5));
	printf("original s6:	%d\n", atoi(s6));
	printf("ft_atoi s6:	%d\n", ft_atoi(s6));
	printf("original s7:	%d\n", atoi(s7));
	printf("ft_atoi s7:	%d\n", ft_atoi(s7));
	printf("original s8:	%d\n", atoi(s8));
	printf("ft_atoi s8:	%d\n", ft_atoi(s8));
	printf("original s9:	%d\n", atoi(s9));
	printf("ft_atoi s9:	%d\n", ft_atoi(s9));
	printf("original s10:	%d\n", atoi(s10));
	printf("ft_atoi s10:	%d\n", ft_atoi(s10));

}
*/
