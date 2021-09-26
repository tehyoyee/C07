#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;
	int	len;

	i = 0;
	len = max - min;
	if (len <= 0)
		return (0);
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	while (min < max)
	{
		arr[i++] = min++;
	}
	return (arr);
}


int main(void)
{
	int *arr;

	arr = ft_range(1,3);
	while (*arr)
		printf("%d ", *(arr++));
	printf("\n");
}
