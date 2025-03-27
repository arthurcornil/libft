/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:11:57 by acornil           #+#    #+#             */
/*   Updated: 2022/02/07 18:30:17 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_factor(int n)
{
	int	factor;

	factor = 1;
	while (n >= 10)
	{
		n /= 10;
		factor *= 10;
	}
	return (factor);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		factor;
	char	digit;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	factor = find_factor(n);
	while (factor != 0)
	{
		digit = (n / factor) + '0';
		write(fd, &digit, 1);
		n %= factor;
		factor /= 10;
	}
}
