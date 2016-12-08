/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 11:07:00 by meckhard          #+#    #+#             */
/*   Updated: 2016/05/21 11:07:03 by meckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;

    i = 0;
	ptr = ft_strdup(s);
	while (ptr[i] != 0)
	{
		ptr[i] = f(i, ptr[i]);
		i++;
	}
	return (ptr);
}
