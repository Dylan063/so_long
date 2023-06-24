/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:48:53 by dravaono          #+#    #+#             */
/*   Updated: 2023/04/13 18:48:59 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	incountnbr(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n < 0)
		count ++;
	if (!n)
		return (1);
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_putinnbr(unsigned int n)
{
	unsigned int	count;

	count = incountnbr(n);
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n > 9)
	{
		ft_putinnbr(n / 10);
		ft_putinnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (count);
}
