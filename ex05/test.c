#include <stdlib.h>
#include <stdio.h>

int		is_c_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int		get_word_cnt(char *str, char *charset)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (!is_c_in_charset(*str, charset))
		{
			cnt++;
			while (*str && !is_c_in_charset(*str, charset))
				str++;
		}
		if (*str)
			str++;
	}
	return (cnt);
}

void	ft_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (*src && i < n)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		len;

	res = (char **)malloc(sizeof(char *) * (get_word_cnt(str, charset) + 1));
	i = 0;
	while (*str)
	{
		if (!is_c_in_charset(*str, charset))
		{
			len = 0;
			while (*str && !is_c_in_charset(*str, charset))
			{
				str++;
				len++;
			}
			res[i] = (char *)malloc(len + 1);
			ft_strncpy(res[i++], str - len, len);
		}
		if (*str)
			str++;
	}
	res[i] = 0;
	return (res);
}

int main(void)
{
	char **arr;
	char *str = "showameathea money";
	char *charset = "ab";
	int	i;
	i = 0;
	arr = ft_split(str, charset);
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}