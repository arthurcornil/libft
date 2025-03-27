/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:33:35 by acornil           #+#    #+#             */
/*   Updated: 2022/01/26 14:22:40 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	i;
	char	*newstr;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if ((start + len) > slen)
		len = slen - start;
	if (start > slen)
		len = 0;
	newstr = malloc(len + 1 * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < len && start <= slen)
	{
		newstr[i] = s[start];
		start ++;
		i ++;
	}
	newstr[i] = '\0';
	return (newstr);
}
