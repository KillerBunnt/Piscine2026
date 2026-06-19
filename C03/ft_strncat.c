char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	index_dest;
	unsigned int	index_src;

	index_src = 0;
	index_dest = 0;
	while (dest[index_dest])
		index_dest++;
	while (src[index_src] && index_src < nb)
	{
		dest[index_dest] = src[index_src];
		index_src++;
		index_dest++;
	}
	dest[index_dest] = 0;
	return (dest);
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *src = "hello fuckers";
	char *dest1 = malloc(30);
	char *dest2 = malloc(30);
	unsigned int nb = 10;

	strcpy(dest1, "true as shit");
	strcpy(dest2, "true as shit");

	printf("official:	%s\nmine:		%s\n", strncat(dest1, src, nb), ft_strncat(dest2, src, nb));
}
