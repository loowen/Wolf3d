/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 11:13:42 by meckhard          #+#    #+#             */
/*   Updated: 2016/05/21 11:13:47 by meckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*fct;

	fct = NULL;
	while (*s)
	{
		if (*s == (char)c)
			fct = (char *)s;
		s++;
	}
	if (*s == (char)c)
		fct = (char *)s;
	return (fct);
}
