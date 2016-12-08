/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 10:30:02 by meckhard          #+#    #+#             */
/*   Updated: 2016/05/21 10:31:04 by meckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	int						i;
	unsigned char			*tmps1;
	const unsigned char		*tmps2;

	i = 0;
	tmps1 = s1;
	tmps2 = s2;
	while (n > 0)
	{
		tmps1[i] = tmps2[i];
		if (tmps1[i] == (unsigned char)c)
			return (s1 + 1 + i);
		i++;
		n--;
	}
	return (NULL);
}
