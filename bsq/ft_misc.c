/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:53:55 by cben-bar          #+#    #+#             */
/*   Updated: 2021/09/22 01:59:26 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

t_rect	ft_rect(int x1, int y1, int x2, int y2)
{
	t_rect	result;

	result.x1 = x1;
	result.y1 = y1;
	result.x2 = x2;
	result.y2 = y2;
	return (result);
}

int	ft_rect_width(t_rect rect)
{
	return (rect.x2 - rect.x1);
}

int	ft_rect_height(t_rect rect)
{
	return (rect.y2 - rect.y1);
}

t_bool	ft_is_printable(char c)
{
	return (c >= ' ' && c <= '~');
}
