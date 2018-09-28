/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolomo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:36:34 by csolomo           #+#    #+#             */
/*   Updated: 2018/06/05 12:19:04 by csolomo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	newlen;

	if (!s1 || !s2)
		return (NULL);
	newlen = ft_strlen(s1) + ft_strlen(s2);
	newstr = ft_strnew(newlen);
	if (newstr == NULL)
	{
		return (NULL);
	}
	ft_strcpy(newstr, s1);
	ft_strcat(newstr, s2);
	return (newstr);
}
