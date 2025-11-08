/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:57:15 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/11 12:16:05 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;
	long	before;

	sign = 1;
	result = 0;
	while (*str != '\0' && ((*str >= 9 && *str <= 13) || (*str == 32)))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		before = result;
		result = result * 10 + (*str - '0');
		if (result / 10 != before && sign == 1)
			return (-1);
		if (result / 10 != before && sign == -1)
			return (0);
		str++;
	}
	return ((result * sign));
}
