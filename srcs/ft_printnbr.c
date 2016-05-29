/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 17:09:02 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/29 16:12:31 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int		printnbr(int nb, t_params *params)
{
	int ret;

	ret = 0;
	if (params->flags == '+' && nb > 0)
	{
		ft_putchar('+');
		ret++;
	}
	if ((int)ft_nbsize(nb) > params->count_flags)
	{
		ft_putnbr(nb);
		return (ft_nbsize(nb) + ret);
	}
	if (params->flags == '0' || params->flags == ' ')
		return (space_print(params, nb) + ret);
	return (0);
}
