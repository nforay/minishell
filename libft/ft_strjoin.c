/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:15:33 by mbourand          #+#    #+#             */
/*   Updated: 2020/09/12 16:35:28 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		s1_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	i = -1;
	if (!(res = (char*)malloc(sizeof(char) * (s1_len + ft_strlen(s2) + 1))))
		exit(1);
	while (s1[++i])
		res[i] = s1[i];
	i = -1;
	while (s2[++i])
		res[s1_len + i] = s2[i];
	res[s1_len + i] = 0;
	return (res);
}
