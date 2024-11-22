/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 03:48:13 by mtaleb            #+#    #+#             */
/*   Updated: 2024/11/20 18:37:54 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_format(const char *format, va_list args,  t_flag *params)
{
	char *ptr;
	ptr = 0;
	// csuxXdip
	// 123456789
	//ft_strdup((char []){(char)va_arg(args, int)});
	if (++(params->specifier) && format[0]  == 's')
		ptr = ft_precision(params, ft_strdup(va_arg(args, char *)));	
	else if (++(params->specifier) && format[0] == 'u')
		ptr = ft_precision(params, ft_unsigned_itoa(va_arg(args, unsigned int)));
	else if (++(params->specifier) && format[0]  == 'x')
		ptr = ft_precision(params, ft_hexa(va_arg(args, unsigned int), "0123456789abcdef", params));
	else if (++(params->specifier) && format[0]  == 'X')
		ptr = ft_precision(params, ft_hexa(va_arg(args, unsigned int), "0123456789ABCDEF", params));	
	else if(++(params->specifier) && format[0]  == 'd')
		ptr = ft_precision(params, ft_itoa(va_arg(args, int)));
	else if(++(params->specifier) && format[0]  == 'i')
		ptr = ft_precision(params, ft_itoa(va_arg(args, int)));
	else if (++(params->specifier) && format[0]  == 'p')
		ptr = ft_precision(params, ft_printmemory(va_arg(args, void *)));
	else if (format[0] == '%')
	{
		params->specifier = 1;
		ft_putchar('%');
	}
	return (ptr);
}