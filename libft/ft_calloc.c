/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:56:35 by kfouad            #+#    #+#             */
/*   Updated: 2022/10/10 22:36:14 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	r;

	r = count * size;
	p = malloc(r);
	if (p == 0)
		return (0);
	else
		ft_bzero(p, r);
	return (p);
}
