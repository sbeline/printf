#include "../includes/my_printf.h"

int     specifier_integer(t_params *params, t_args *args, t_tabvar *var)
{
	if (params->lenght > LENGHT)
	{
    	if (params->specifier != 5)
    	{
        	var->var_unsint = va_arg(args->ap, int);
        	ft_putnbr(var->var_unsint);
			return (ft_nbsize(var->var_unsint));
    	}
		else if (params->specifier == 5)
		{
			var->var_longlong= va_arg(args->ap, long long);
			ft_printlong(var->var_longlong);
			return (ft_lenghtlong(var->var_longlong));
		}
	}
	return (-1);
}

int     specifier_spint(t_params *params, t_args *args, t_tabvar *var)
{

    if (params->lenght > LENGHT)
    {
        var->var_unsint = (unsigned)va_arg(args->ap, int);
        if (params->specifier == 7 || params->specifier == 8)
            return (convert_octal(var->var_unsint, ft_strnb(&var->var_unsint)));
        else if (params->specifier == 11)
            return (convert_hx(var->var_unsint, ft_strnb(&var->var_unsint), 0));
		else if (params->specifier == 12)
			return (convert_hx(var->var_unsint, ft_strnb(&var->var_unsint), 1));
        else
			ft_putnbr(var->var_unsint);
		if (var->var_unsint == 0)
			return(1);
		return (ft_nbsize(var->var_unsint));
    }
	return (-1);
}

int     specifier_float(t_params *params, t_args *args, t_tabvar *var)
{

    if (params->lenght > LENGHT)
    {
        var->var_double = va_arg(args->ap, double);
    }
    return (ft_nbsize(var->var_double));
}


int		print_add(t_params *params, t_args *args, t_tabvar *var)
{
	void 	*p;
	(void)params;
	(void)var;
	p = va_arg(args->ap, void *);
	return (ft_print_memory(p, sizeof(&p)));
}
