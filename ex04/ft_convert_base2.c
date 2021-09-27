/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:28:12 by taehykim          #+#    #+#             */
/*   Updated: 2021/09/27 21:46:21 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_same_sign(char *base)
{
    int i;
    int j;

    i = 0;
    while (base[i])
    {
        j = i + 1;
        while (base[j])
        {
            if (base[i] == base[j])
                return (1);
            j++;
        }
        i++;
    }
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
    return (0);
}

int	str_len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		i++;
	}
	return (i);
}

int	find_number(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	deci_count(long long result, int base_len)
{
	int	i;

	i = 0;
	while (result > 0)
	{
		result = result / base_len;
		i++;
	}
	return (i);
}
