/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:09:03 by kfouad            #+#    #+#             */
/*   Updated: 2022/10/10 22:26:27 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s1;

	s1 = (char *)s;
	i = 0;
	while (i < n)
	{
		if (s1[i] == (char)c)
			return ((void *)&s1[i]);
		i++;
	}
	return (NULL);
}

//int main()
//{
//	char *str = "hello word";
//	int	i = -1;
//	printf("%s",ft_memchr(str, 'w', i));
//}
