/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 10:39:36 by meckhard          #+#    #+#             */
/*   Updated: 2016/05/21 10:39:45 by meckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			cmp;
	unsigned char	*ptr;

	cmp = 0;
	ptr = (unsigned char *)b;
	while (cmp < len)
	{
		ptr[cmp] = (unsigned char)c;
		cmp++;
	}
	return (b);
}
