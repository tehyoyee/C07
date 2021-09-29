/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:44:49 by taehykim          #+#    #+#             */
/*   Updated: 2021/09/27 21:50:54 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
char	*ft_make_result(int size, int total_size, char **strs, char *sep);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	while (*dest)
		dest++;
	while (*src)
		*(dest++) = *(src++);
	*dest = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_size;
	int		i;

	if (size == 0)
		return ((char*)malloc(sizeof(char)));
	if (size < 0)
		return (0);
	i = 0;
	total_size = 0;
	while (i < size)
	{
		total_size += ft_strlen(strs[i]);
		i++;
	}
	total_size += ft_strlen(sep) * (size - 1);

	return (ft_make_result(size, total_size, strs, sep));
}

char	*ft_make_result(int size, int total_size, char **strs, char *sep)
{
	char *arr;
	char *cat;
	int	i;
	
	arr = (char *)malloc(sizeof(char) * (total_size + 1));
	i = 0;
	cat = arr;
	while (i < size)
	{
		cat = ft_strcat(cat, strs[i]);
		if (i != size - 1)
			cat = ft_strcat(cat, sep);
		i++;
	}
	cat[total_size] = '\0';
	return (arr);
}

int	main(void)
{
	char *arr[6] = {"abccds", "bsdfga", "sdfab", "sdfba" ,"ab", "ba"};
	printf("%s", ft_strjoin(6, arr, "YY"));
}