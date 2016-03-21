#include "../inc/my_printf.h"


static void		init_parm(t_params *params)
{
	params->width = 0;
	params->precision = 0;
	params->lenght = 0;
	params->specifier = 0;
}

int			to_convert(const char *str, int pos, t_params *params)
{
	if (str[pos] != '%')
		return (pos);
	pos += 1;
	if (str[pos] == '%')
		return (pos);
	while ((flags(str, pos, params)) > 0)
		pos += 1;
	while ((init_width(str, pos, params)) > 0)
		pos += 1;
	if (str[pos] == '.')
	{
		pos += 1;
		while ((get_precision(str, pos, params)) > 0)
			pos += 1;
	}
	params->lenght = lenght_gest(str + pos);
	if (params->lenght < 6)
		pos += 1;
	if (params->lenght == 6 || params->lenght == 7)
		pos += 2;
	params->specifier = specifier(str[pos]);
	return (pos + 1);
}

int			my_printf(const char *format, ...)
{
	int		i;
	int		pos;
	t_args	args;
	t_params params;
	int tmp = 0;

	i = 0;
	pos = 0;
	va_start(args.ap, format);
	init_parm(&params);
	while (format[i])
	{
		tmp = i;
		if ((format[i] == '%') && (i = to_convert(format, i, &params)) > tmp)
			ft_printf(params, &args);
		else
		{
			ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args.ap);
	return(0);
}

int			main()
{
	my_printf("%d test\n", 32768);
	//printf("%d\n", 32768);
	return (0);
}
