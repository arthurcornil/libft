/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:09:27 by acornil           #+#    #+#             */
/*   Updated: 2022/01/26 13:59:34 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	char			*start_newstr;
	char			*newstr;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = malloc(len + 1 * sizeof(char));
	if (!newstr)
		return (NULL);
	start_newstr = newstr;
	while (*s1)
	{
		*newstr = *s1;
		newstr ++;
		s1 ++;
	}
	while (*s2)
	{
		*newstr = *s2;
		newstr ++;
		s2 ++;
	}
	*newstr = '\0';
	return (start_newstr);
}
