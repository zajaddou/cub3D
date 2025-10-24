/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:16:19 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/23 12:16:49 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	sreach_ptr(void **list, void *ptr, int max)
{
	int i;

	i = -1;
	while (++i <= max)
		if (list[i] == ptr)
			return (i);
	return (-1);
}

void	ft_free(void *ptr, int flag)
{
	static void *list[INT32_MAX];
	static int max;
	int	p;
	
	p = sreach_ptr(list, ptr, max);

	if (ptr && (flag == 0) && (p == -1))
		list[max++] = ptr;
	if (ptr && (flag == 1) && (p != -1))
	{
		free(list[p]);
		list[p] = NULL;
	}
	while ((!ptr && flag == 1) && (max-- > 0))
	{
		free(list[max]);
		list[max] = NULL;
	}
}
