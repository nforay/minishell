/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:53:08 by mbourand          #+#    #+#             */
/*   Updated: 2020/09/04 15:56:15 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_nothing(void *ptr)
{
	(void)ptr;
}

void	free_token(void *ptr)
{
	t_token *token;

	if (!ptr)
		return ;
	token = (t_token*)ptr;
	ft_free(&(token->text));
	ft_memdel(&ptr);
}

void	free_shell(void)
{
	size_t	i;
	void	*cast;

	i = 0;
	cast = (void*)g_shell.commands;
	ft_free(&(g_shell.input));
	ft_lstclear(&(g_shell.tokens), &free_nothing);
	while (g_shell.commands[i])
		ft_lstclear(&(g_shell.commands[i++]), &free_token);
	ft_memdel(&cast);
	i = 0;
	cast = (void*)g_shell.path;
	ft_memdel(&cast);
}
