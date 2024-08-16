/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:36:40 by kfouad            #+#    #+#             */
/*   Updated: 2022/10/12 22:10:51 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	index_size(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = index_size(n);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!n)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		j = 1;
		n = n * -1;
	}
	while (--i >= j)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
