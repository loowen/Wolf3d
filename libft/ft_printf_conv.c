/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 09:47:19 by meckhard          #+#    #+#             */
/*   Updated: 2016/06/18 14:31:05 by meckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*convert(long int num, int base, int hex_upper)
{
	static char	buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		*--ptr = '0';
	while (num != 0)
	{
		if (hex_upper)
			*--ptr = "0123456789ABCDEF"[num % base];
		else
			*--ptr = "0123456789abcdef"[num % base];
		num /= base;
	}
	return (ptr);
}

char	*convert_uns(unsigned int num, int base, int hex_upper)
{
	static char	buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		*--ptr = '0';
	while (num != 0)
	{
		if (hex_upper)
			*--ptr = "0123456789ABCDEF"[num % base];
		else
			*--ptr = "0123456789abcdef"[num % base];
		num /= base;
	}
	return (ptr);
}

char	*convert_uns_l(unsigned long long num, int base, int hex_upper)
{
	static char	buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		*--ptr = '0';
	while (num != 0)
	{
		if (hex_upper)
			*--ptr = "0123456789ABCDEF"[num % base];
		else
			*--ptr = "0123456789abcdef"[num % base];
		num /= base;
	}
	return (ptr);
}
