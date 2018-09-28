/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolomo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:58:22 by csolomo           #+#    #+#             */
/*   Updated: 2018/06/04 15:05:03 by csolomo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*fresh;

	i = 0;
	fresh = (char *)malloc(sizeof(char) * (len + 1));
	if (fresh == NULL)
		return (NULL);
	if (s == NULL)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		fresh[i] = s[start];
		i++;
		start++;
	}
	fresh[i] = '\0';
	return (fresh);
}
