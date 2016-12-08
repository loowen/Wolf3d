/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 09:45:51 by meckhard          #+#    #+#             */
/*   Updated: 2016/06/04 09:45:52 by meckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define LL_INT long long int
# define ULL_INT unsigned long long int

typedef	struct		s_flags
{
	int		has_flags;
	int		plus;
	int		minus;
	int		zero;
	int		hash;
	int		space;
	int		prec;
	int		ip;
	int		padding;
	char	pad;
}					t_flags;

typedef struct		s_mods
{
	int	has_mod;
	int	ln;
	int	sht;
	int	u_sign;
	int	zee;
	int	jay;
}					t_mods;

int					ft_printf(const char *format, ...);
int					is_pflag(char c);
int					is_pmodifier(char c);
int					is_psigned(char c);
int					is_pnumeric(char c);
int					ft_out(char type, char *out, t_flags fl);
char				*convert(long long num, int base, int hex_upper);
char				*convert_uns(ULL_INT num, int base, int hex_upper);
char				*ft_check(const char *str, t_mods md, va_list *args);
char				*ft_check_mod(const char *str, t_mods md, va_list *args);
char				*convert_uns_l(LL_INT num, int base, int hex_upper);
t_flags				init_flags(void);
t_mods				init_mods(void);

#endif
