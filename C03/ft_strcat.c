char	*ft_strcat(char *dest, char *src)
{
	unsigned int	index_dest;
	unsigned int	index_src;

	index_src = 0;
	index_dest = 0;
	while (dest[index_dest])
		index_dest++;
	while (src[index_src])
	{
		dest[index_dest] = src[index_src];
		index_src++;
		index_dest++;
	}
	dest[index_dest] = 0;
	return (dest);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *src = "hello\0 fuckers";
	char *dest1 = malloc(30);
	char *dest2 = malloc(30);

	strcpy(dest1, "true as shit");
	strcpy(dest2, "true as shit");

	printf("official:	%s\nmine:		%s\n", strcat(dest1, src), ft_strcat(dest2, src));
}
*/