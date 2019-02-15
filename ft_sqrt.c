/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacnijim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 19:52:22 by pacnijim          #+#    #+#             */
/*   Updated: 2017/01/27 08:33:18 by pacnijim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int		n;

	n = 1;
	while (n <= 46340)
	{
		if (n * n == nb)
			return (n);
		n++;
	}
	return (1);
}
