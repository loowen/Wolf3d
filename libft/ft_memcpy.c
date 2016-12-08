/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 10:35:26 by meckhard          #+#    #+#             */
/*   Updated: 2016/05/21 10:35:31 by meckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*tmp;
	const char	*tmp2;
	size_t		i;

	i = 0;
	tmp = (char*)s1;
	tmp2 = (char*)s2;
	while (i < n)
	{
		tmp[i] = tmp2[i];
		i++;
	}
	return (s1);
}
