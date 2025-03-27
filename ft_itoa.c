/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:08:59 by acornil           #+#    #+#             */
/*   Updated: 2022/02/04 16:37:03 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_counter(int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		counter ++;
	}
	return (counter);
}

static int	factor_counter(int n)
{
	int	factor;

	factor = 1;
	while (n >= 10)
	{
		factor *= 10;
		n /= 10;
	}
	return (factor);
}

static void	fill_str(char *str, int factor, int n, int negative)
{
	int	i;

	i = 0;
	if (negative)
	{
		str[i] = '-';
		i ++;
	}
	while (factor != 0)
	{
		str[i] = (n / factor) + '0';
		n %= factor;
		factor /= 10;
		i ++;
	}
}

char	*ft_itoa(int n)
{
	int		ndigits;
	int		factor;
	char	*str;
	int		negative;

	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	negative = 0;
	ndigits = digit_counter(n);
	if (n < 0)
	{
		ndigits ++;
		n *= -1;
		negative = 1;
	}
	factor = factor_counter(n);
	str = malloc(ndigits + 1 * sizeof(char));
	if (!str)
		return (NULL);
	fill_str(str, factor, n, negative);
	str[ndigits] = '\0';
	return (str);
}
