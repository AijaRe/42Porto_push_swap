/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:12:55 by arepsa            #+#    #+#             */
/*   Updated: 2023/08/28 11:56:46 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_exit_error();
		nb = nb * 10;
		nb = nb + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}
