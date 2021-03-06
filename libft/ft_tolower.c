/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolomo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:18:29 by csolomo           #+#    #+#             */
/*   Updated: 2018/06/04 15:16:03 by csolomo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned int	a;
	int				dif;

	a = (unsigned int)c;
	dif = 'A' - 'a';
	if (c >= 'A' && c <= 'Z')
	{
		a = a - dif;
	}
	return (a);
}
