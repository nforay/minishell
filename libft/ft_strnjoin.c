/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 17:10:07 by mbourand          #+#    #+#             */
/*   Updated: 2020/09/12 16:36:50 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1)
		return (ft_strndup(s2, n));
	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len] && s2_len < n)
		s2_len++;
	if (!(res = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		exit(1);
	ft_strlcpy(res, s1, s1_len + s2_len + 1);
	ft_strlcpy(res + s1_len, s2, s2_len + 1);
	return (res);
}
