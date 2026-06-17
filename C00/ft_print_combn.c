#include <unistd.h>
#include <stdio.h>

void	ft_increment(char *combs, int *index, int n)
{
	if (combs[*index] > '9')
	{
		combs[*index]--;
		(*index)--;
		while (combs[*index] >= combs[*index + 1] - 1)
			(*index)--;
		combs[*index]++;
		while (combs[++(*index)])
			combs[*index] = combs[*index - 1] + 1;
	}
	write(1, combs, n);
	if (combs[0] < '9' - n + 1)
		write(1, ", ", 2);
	*index = n - 1;
	combs[*index]++;
}

void	ft_print_combn(int n)
{
	char	*digits;
	char	combs[9];
	int		index;
	int		iterates;

	iterates = 0;
	index = 0;
	digits = "0123456789";
	if (n > 0 && n < 10)
	{
		while (index < n)
		{
			combs[index] = digits[index];
			index++;
		}
		if (index < 9)
			combs[index] = 0;
		index = n - 1;
		while (combs[0] < '9' - n + 1)
			ft_increment(combs, &index, n);
		if (n == 1)
			write(1, combs, n);
	}
}

int main()
{
	ft_print_combn(1);
	write(1, "\n", 1);
	ft_print_combn(2);
	write(1, "\n", 1);
	ft_print_combn(3);
	write(1, "\n", 1);
	ft_print_combn(4);
	write(1, "\n", 1);
	ft_print_combn(5);
	write(1, "\n", 1);
	ft_print_combn(6);
	write(1, "\n", 1);
	ft_print_combn(7);
	write(1, "\n", 1);
	ft_print_combn(8);
	write(1, "\n", 1);
	ft_print_combn(9);
}