#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int num;

	num = 0;
	while (*str++)
		num++;
	return (num);
}

char *ft_strcat(char *dest, char *src)
{
	while (*dest)
		dest++;
	while (*src)
		*(dest++) = *(src++);
	*dest = '\0';
	return (dest);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	char *ret;
	char *ptr;
	int ret_len;
	int i;

	i = 0;
	ret_len = 0;
	if (size == 0)
	{
		ret = (char *)malloc(1);
		ret = "\0";
		return (ret);
	}
	while (i < size)
		ret_len += ft_strlen(strs[i++]);
	ret_len = ret_len + (size - 1) * ft_strlen(sep);
	ret = (char *)malloc(sizeof(char) * (ret_len + 1));
	i = 0;
	ptr = ret;
	ptr = ft_strcat(ptr, strs[i]);
	while(++i < size)
	{
		ptr = ft_strcat(ptr, sep);
		ptr = ft_strcat(ptr, strs[i]);
	}
	ptr[ret_len] = '\0';
	return (ret);
}

int	main(void)
{
	int	a;
	char *arr[6] = {"ab", "ba", "ab", "ba" ,"ab", "ba"};
	printf("%s", ft_strjoin(6, arr, "YY"));
}
