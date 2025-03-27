/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:22:13 by acornil           #+#    #+#             */
/*   Updated: 2022/02/04 15:55:35 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	word_counter(char const *s, char c)
{
	unsigned int	nwords;

	nwords = 0;
	while (*s)
	{
		while (*s && *s == c)
			s ++;
		while (*s && *s != c)
			s ++;
		if (*(s - 1) != c)
			nwords ++;
	}
	return (nwords);
}

static unsigned int	*len_counter(char const *s, char c, unsigned int words)
{
	unsigned int	*lens;
	unsigned int	i;

	if (words == 0)
		return (NULL);
	lens = malloc(words * sizeof(unsigned int));
	if (!lens)
		return (NULL);
	i = 0;
	while (*s)
	{
		lens[i] = 0;
		while (*s && *s == c)
			s ++;
		while (*s && *s != c)
		{
			s ++;
			lens[i]++;
		}
		while (*s && *s == c)
			s ++;
		i ++;
	}
	return (lens);
}

static void	copywords(char const *s, char c, unsigned int *tab, char **strs)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (*s)
	{
		j = 0;
		while (*s && *s == c)
			s ++;
		while (*s && j < tab[i])
		{
			strs[i][j] = *s;
			s ++;
			j ++;
		}
		if (*s || (!*s && *(s - 1) != c))
		{
			strs[i][j] = '\0';
			i ++;
		}
	}
	strs[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char			**strs;
	unsigned int	nwords;
	unsigned int	*lenwords;
	unsigned int	i;

	if (!s)
		return (NULL);
	nwords = (word_counter(s, c));
	strs = malloc((nwords + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	lenwords = len_counter(s, c, nwords);
	i = 0;
	while (i < nwords)
	{
		strs[i] = malloc(lenwords[i] + 1 * sizeof(char));
		if (!strs[i])
			return (NULL);
		i ++;
	}
	copywords(s, c, lenwords, strs);
	free(lenwords);
	return (strs);
}
