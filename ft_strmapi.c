/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:38:24 by acornil           #+#    #+#             */
/*   Updated: 2022/01/24 13:20:35 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*res;
	unsigned int	i;

	if (!s || (!s && !f))
		return (NULL);
	else if (!f)
		return ((char *)s);
	len = ft_strlen(s);
	res = malloc(len + 1 * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = f(i, s[i]);
		i ++;
	}
	res[i] = '\0';
	return (res);
}
