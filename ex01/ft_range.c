#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;
	int	len;

	i = 0;
	if (max <= min)
		return (0);
	len = max - min;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	while (min < max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}

int	main(void)
{
	int *arr;
	int i;

	i = 0;
	arr = ft_range(3,5);
	while (arr[i])
	{
		printf("%d", arr[i]);
		i++;
	}
}