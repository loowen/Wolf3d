/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 10:12:22 by meckhard          #+#    #+#             */
/*   Updated: 2016/05/21 10:13:30 by meckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			cmp;
	unsigned char	*ptr;

	cmp = 0;
	ptr = (unsigned char *)s;
	while (cmp < n && n > 0)
	{
		ptr[cmp] = 0;
		cmp++;
	}
}
