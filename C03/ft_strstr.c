char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	index_str;
	unsigned int	index_find;
	unsigned int	store;
	index_str = 0;
	index_find = 0;

	if (!to_find[0])
		return (str);
	while (str[index_str])
	{
		store = index_str;
		while (to_find[index_find] && to_find[index_find] == str[index_str])
		{
			index_find++;
			index_str++;
		}
		if (!(to_find[index_find]))
			return (&(str[store]));
		else
			index_find = 0;
		index_find = 0;
		if (to_find[index_find] && to_find[index_find] == str[index_str])
			continue;
		index_str++;
	}
	return(0);
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *src = "hello fuckers";
	char *find = "\n";
	unsigned int nb = 10;

	printf("official:	%s\nmine:		%s\n", strstr(src, find), ft_strstr(src, find));
}
