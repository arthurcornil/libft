/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:12:29 by acornil           #+#    #+#             */
/*   Updated: 2022/02/07 01:47:54 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getstart(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == NULL)
			return (i);
		i ++;
	}
	return (i);
}

static int	getend(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strrchr(set, s1[len - i - 1]) == NULL)
			return (len - i);
		i ++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*newstr;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = getstart(s1, set);
	end = getend(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	newstr = malloc((end - start + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, (char *)s1 + start, end - start + 1);
	return (newstr);
}
