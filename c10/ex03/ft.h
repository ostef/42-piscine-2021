/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:41:18 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/22 19:50:51 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>

typedef struct s_file_reader
{
	char	**files;
	int		file_count;
	int		file_index;
	int		fd;
	int		same_line;
	char	prev_line[16];
	char	curr_line[16];
	int		valid_files;
}	t_file_reader;

int		ft_memcmp(void *p1, void *p2, int n);
void	*ft_memcpy(void *dest, void *src, int n);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

extern char	*g_program_name;

void	ft_print_errno(void);
void	ft_print_file_errno(char *filename);
void	ft_print_error(char *errstr, char *arg);
void	ft_print_hex(unsigned long n, int digits);
void	ft_init_reader(t_file_reader *reader, char **files, int count);
int		ft_read_next_block(t_file_reader *reader);
void	ft_next_file(t_file_reader *reader);

#endif
