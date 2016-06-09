/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:27:41 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/09 21:27:59 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

static void		init_parm(t_params *params)
{
	params->width = 0;
	params->precision = 0;
	params->lenght = 0;
	params->specifier = 0;
	params->count_flags = 0;
	params->flags = 0;
	params->neg = 0;

}

int			gest_flag(int pos, const char *str, t_params *params)
{
	int ret;

	ret = pos;
	ret += init_width(str, pos, params);
	ret += flags(str, pos, params);
	ret += space(str, pos, params);
	//ret += define_width(str, pos, params);
	if (ret > pos)
		gest_flag(ret, str, params);
	return (ret);
}

int			to_convert(const char *str, int *pos, t_params *params)
{
	int count_space;

	count_space = 0;
	if (str[*pos] != '%' && str[*pos])
		return (-1);
	*pos += 1;
	while (str[*pos])
	{
		*pos = gest_flag(*pos, str, params);
		if (str[*pos] == '.')
		{
			*pos += 1;
			while ((get_precision(str, *pos, params)) > 0)
			{
				*pos += 1;
				return (count_space +1);
			}
		}
		params->lenght = lenght_gest(str + *pos);
		if (params->lenght < 4)
			*pos += 1;
		if (params->lenght == 4 || params->lenght == 5)
			*pos += 2;
		params->specifier = specifier(str[*pos]);
		if (params->specifier != SPECIFIER)
			*pos += 1;
		else
			return (-1);
		return (1);
	}
	return(-1);
}

int 		print(const char *format, int *pos ,t_params *params)
{
	int ret;

	ret = 0;
	if (!format[*pos])
		return (0);
	if (!params->count_flags || params->flags == 't')
	{
		ft_putchar(format[*pos]);
		*pos += 1;
		return (1);
	}
	ret = params->count_flags - 1;
	ft_putchar(params->flags);
	if (params->specifier == SPECIFIER && params->flags != 't' && !params->neg)
		while (ret--)
		{
			ft_putchar(' ');
		}
	ft_putchar(format[*pos]);
	if (params->specifier == SPECIFIER && params->flags != 't' && params->neg)
		while (ret--)
		ft_putchar(' ');
	*pos += 1;
	return (params->count_flags);

}

int			ft_printf(const char *format, ...)
{
	int			i;
	int			ret;
	t_args		args;
	t_params	params;

	i = 0;
	ret = 0;
	va_start(args.ap, format);

	while (format[i])
	{
		init_parm(&params);
		if ((to_convert(format, &i, &params)) > 0)
			ret += my_printf(&params, &args);
		else
			ret += print(format, &i, &params);
	}
	va_end(args.ap);
	return(ret);
}
