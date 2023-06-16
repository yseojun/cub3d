/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:31:34 by rolee             #+#    #+#             */
/*   Updated: 2023/01/12 15:04:41 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

char		*ft_itoa(int n);
char		**ft_split(const char *str);
char		*ft_strdup(const char *str);
char		*ft_strjoin(const char *s1, const char *s2);
size_t		ft_strlen(const char *str);
void		ft_putnbr_fd(int n, int fd);

#endif
