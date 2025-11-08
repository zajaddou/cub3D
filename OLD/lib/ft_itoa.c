/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:13:41 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/04 13:13:43 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_min(void)
{
	char	*result;

	result = (char *)malloc(12);
	if (!result)
		return (NULL);
	ft_strlcpy(result, "-2147483648", 12);
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		sign;

	sign = (n < 0);
	if (n == -2147483648)
		return (ft_min());
	len = ft_len(n) + sign;
	if (sign)
		n = -n;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len-- > sign)
	{
		result[len] = (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		result[0] = '-';
	return (result);
}
