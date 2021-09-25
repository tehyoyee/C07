/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:36:06 by taehykim          #+#    #+#             */
/*   Updated: 2021/09/25 19:43:17 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*arr;

	i = 0;
	while (src[i])
	{
		i++;
	}
	arr = (char *)malloc(sizeof(char) * i + 1);
	arr[i] = '\0';
	i--;
	while (i >= 0)
	{
		arr[i] = src[i];
		i--;
	}
	return (arr);
}

int	main(void)
{
	printf("%s", ft_strdup("asdf"));
}
