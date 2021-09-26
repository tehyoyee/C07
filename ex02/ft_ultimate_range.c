#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_ultimate_range(int **range, int min, int max)
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
	*range = arr;
	return (len);
}

int		main(void)
{
	int	min;
	int	max;
	int	*range;
	int	a;

	min = 5;
	max = 10;
	a = ft_ultimate_range(&range, min, max);
	printf("%d", a);
}