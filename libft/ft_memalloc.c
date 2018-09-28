/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolomo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:28:43 by csolomo           #+#    #+#             */
/*   Updated: 2018/06/04 16:36:12 by csolomo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *newmem;

	newmem = malloc(size);
	if (size > 2147483647)
		return (NULL);
	if (newmem == NULL)
		return (NULL);
	ft_bzero(newmem, size);
	return (newmem);
}
