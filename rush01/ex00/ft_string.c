/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:16:45 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/12 20:19:04 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

void	*ft_memcpy(void *dest, void *src, t_ui n)
{
	t_ui	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i += 1;
	}
	return (dest);
}
