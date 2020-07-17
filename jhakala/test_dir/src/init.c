/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:18:17 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/17 17:30:27 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	default_values(char **av, t_mem *mem)
{
	mem->av = av;
	mem->dump = -1;
	mem->n_player = 0;
	mem->player = NULL;
	mem->game = NULL;
}

t_mem	*ft_init(int ac, char **av)
{
	t_mem	*mem;

	mem = (t_mem*)malloc(sizeof(t_mem));
	default_values(av, mem);
	if (parse_av(ac, av, mem) == 1)
	{
		free_memory(mem);
		return (NULL);
	}
	
	return (mem);
}