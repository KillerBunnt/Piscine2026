unsigned int	ft_strlcat(char *dest, char *src, unsigned int nb)
{
	unsigned int	index_dest;
	unsigned int	index_src;
	unsigned int	dest_len;
	index_src = 0;
	index_dest = 0;
	while (dest[index_dest])
		index_dest++;
	if (index_dest > nb)
		return (nb + 1);
	while (src[index_src] && index_dest < nb)
	{
		dest[index_dest] = src[index_src];
		index_src++;
		index_dest++;
	}
	dest[index_dest] = 0;
	return (index_dest + );
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *src = "abcde";
	char *dest1 = malloc(30);
	char *dest2 = malloc(30);
	unsigned int nb = 10;

	strcpy(dest1, "cornorius");
	strcpy(dest2, "cornorius");

	printf("official:	%lu	%s\nmine:		%u	%s\n", strlcat(dest1, src, nb), dest1, ft_strlcat(dest2, src, nb), dest2);
}
