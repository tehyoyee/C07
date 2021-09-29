/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:58:51 by taehykim          #+#    #+#             */
/*   Updated: 2021/09/27 21:49:48 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		check_same_sign(char *base);
int		str_len(char *base);
int		find_number(char c, char *base);
int		deci_count(long long result, int base_len);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_putnbr_base(int nbr, char *base, int sign, int base_len);
char	*memory_allo_zero(int size, char *base_to, int base_len);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	result;
	int			sign;
	int			base_len;

	sign = 1;
	result = 0;
	base_len = str_len(base_from);
	if (check_same_sign(base_from) || !(*base_from) || base_len == 1)
		return (0);
	while (*nbr == ' ' || (9 <= *nbr && *nbr <= 13))
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	while (*nbr)
	{
		if (find_number(*nbr, base_from) >= 0)
			result = result * base_len + find_number(*nbr, base_from);
		nbr++;
	}
	return (ft_putnbr_base(result, base_to, sign, str_len(base_to)));
}

char	*ft_putnbr_base(int result, char *base_to, int sign, int base_len)
{
	char	*ret;
	int		size;

	size = deci_count(result, base_len);
	if (check_same_sign(base_to) || !(*base_to) || base_len == 1)
		return (0);
	if (result == 0)
		ret = memory_allo_zero(1, base_to, base_len);
	else
	{
		if (sign == -1)
			size++;
		ret = (char *)malloc(sizeof(char) * size + 1);
		ret[size] = '\0';
		while (result > 0)
		{
			ret[--size] = base_to[result % base_len];
			result /= base_len;
		}
		if (sign == -1)
			ret[0] = '-';
	}
	return (ret);
}
char	*memory_allo_zero(int size, char *base_to, int base_len)
{
	char	*ret;
	
	size = 1;
	ret = (char *)malloc(sizeof(char) * size + 1);
	ret[0] = '0';
	ret[size] = '\0';
	return (ret);
}

int	main(void)
{
	char *base_from = "01";
	char *base_to = "0123456789abcdef";
	char *nbr = "   -+	11111";

	printf("%s", ft_convert_base(nbr, base_from, base_to));
}