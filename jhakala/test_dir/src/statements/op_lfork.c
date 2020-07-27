/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 11:55:15 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/26 20:18:49 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int    op_lfork(t_game *game, int place, t_carriage *c)
{
	int val;

    val = game->arena[place + 2] & 0xFF;
    val += (game->arena[place + 1] << 8);
//  ft_printf("     --%d--\n", val);
    new_carriage(&game->c_lst, place, c, game);
    game->c_lst->place += val;
    ft_printf(" P   %d | lfork %d | to (0x%04x)\n", c->id, val, game->c_lst->place);
    return (read_game_param(game->arena, place, 3, NULL));
}