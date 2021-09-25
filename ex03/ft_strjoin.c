/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:44:49 by taehykim          #+#    #+#             */
/*   Updated: 2021/09/25 21:12:55 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char 	*ft_strjoin(int size, char **strs, char *sep)		//size 문자열개수
{
	int		total_size;
	int		i;
	char	*arr;
	char	*cat;

	i = 0;
	while (i < size)
		total_size += ft_strlen(strs[i++]);
	total_size += ft_strlen(sep) * (size - 1);
	arr = (char *)malloc(sizeof(char) * total_size + 1);
	i = 0;
	while (i < size - 1)
	{
		strs[i] = ft_strcat(strs[i], sep);
		i++;
	}
	i = 0;
	while (strs[0][i])
	{
		printf("%c", strs[0][i]);
		i++;
	}

	printf("%d\n", total_size);
	return (0);
}

int	main(void)
{
	int	a;
	char *arr[6] = {"asdf", "asdf", "Sdfg", "asdf" ,"asdg", "sdf"};
	ft_strjoin(6, arr, "ab");
}
