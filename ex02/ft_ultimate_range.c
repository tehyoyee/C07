#include <stdlib.h>

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
