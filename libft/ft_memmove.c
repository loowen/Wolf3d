/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 10:38:20 by meckhard          #+#    #+#             */
/*   Updated: 2016/05/21 10:38:25 by meckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*ss1;
	const char	*ss2;
	char		tmp[n];
	size_t		i;

	i = 0;
	ss1 = (char *)s1;
	ss2 = (const char *)s2;
	while (i < n)
	{
		tmp[i] = ss2[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		ss1[i] = tmp[i];
		i++;
	}
	return (s1);
}
