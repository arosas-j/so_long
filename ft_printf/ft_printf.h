/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:26:13 by arosas-j          #+#    #+#             */
/*   Updated: 2024/02/29 15:53:18 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
int		ft_print_arg(char format, va_list arg);
int		ft_format_p(unsigned long n);
int		ft_format_di(int n);
int		ft_format_u(unsigned int n);
int		ft_format_x(unsigned int n);
int		ft_format_upperx(unsigned int n);
int		ft_putchar(char a);
int		ft_putstr(char *str);
char	*ft_hexadecimal(unsigned long n);
char	*ft_itoa(int n);
char	*ft_uitoa(long int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);

#endif