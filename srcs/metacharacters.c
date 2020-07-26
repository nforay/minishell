/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metacharacters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 02:47:57 by mbourand          #+#    #+#             */
/*   Updated: 2020/07/26 02:47:57 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_blank(char c)
{
	return (c == ' ' || c == '\t');
}

int		is_quote(char c)
{
	return (c == '\"' || c == '\'');
}