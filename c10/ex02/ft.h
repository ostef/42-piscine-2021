/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:12:16 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/21 22:02:30 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>

int		ft_atoiv(char *str, int *result);
int		ft_min(int a, int b);

int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	*ft_memcpy(void *dest, void *src, int n);

extern char	*g_program_name;

void	ft_print(char *str);
void	ft_print_errno(void);
void	ft_print_file_errno(char *filename);
void	ft_print_error(char *errstr, char *arg);
void	ft_print_usage(void);

#endif
