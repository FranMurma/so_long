/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:42:13 by frmurcia          #+#    #+#             */
/*   Updated: 2022/11/05 17:50:55 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(va_list lst, char c)
{
	if (c == 'c')
		return (ft_print_char(va_arg(lst, int)));
	else if (c == 's')
		return (ft_print_s(va_arg(lst, char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(lst, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_bsten(va_arg(lst, int)));
	else if (c == 'u')
		return (ft_print_decu(va_arg(lst, unsigned int)));
	else if (c == 'x')
		return (ft_print_hex(va_arg(lst, unsigned int)));
	else if (c == 'X')
		return (ft_print_hexmay(va_arg(lst, unsigned int)));
	else if (c == '%')
	{
		if (write (1, "%", 1) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

static int	ft_printing(char const *s, va_list lst, int cont, int ret_tot)
{
	int	sub_ret;

	while (s[cont])
	{
		if (s[cont] == '%' && s[cont + 1])
		{
			sub_ret = ft_type(lst, s[cont + 1]);
			if (sub_ret == -1)
				return (-1);
			ret_tot = ret_tot + sub_ret;
			cont = cont + 2;
		}
		else
		{
			if (write (1, &s[cont], 1) == -1)
				return (-1);
			ret_tot++;
			cont++;
		}
	}
	return (ret_tot);
}

int	ft_printf(char const *s, ...)
{
	va_list	lst;
	int		cont;
	int		ret_tot;

	va_start(lst, s);
	cont = 0;
	ret_tot = 0;
	ret_tot = ft_printing(s, lst, cont, ret_tot);
	va_end(lst);
	return (ret_tot);
}
