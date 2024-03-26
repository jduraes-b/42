/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:38:28 by jduraes-          #+#    #+#             */
/*   Updated: 2024/03/25 19:32:33 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	enemycheck(t_data *gamestate)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (gamestate->map[++i])
	{
		j = -1;
		while (gamestate->map[i][++j])
		{
			if (gamestate->map[i][j] == 'D')
			{
				gamestate->enemycount++;
				newenemy(i, j, gamestate);
			}
		}
	}
	return (1);
}

void	newenemy(int i, int j, t_data *gamestate)
{
	t_enemy		*enemy;

	enemy = (t_enemy *)ft_calloc(1, sizeof(t_enemy));
	if (gamestate->enemycount == 1)
	{
		gamestate->enemy = enemy;
		gamestate->enemy->root = enemy;
	}
	else
	{
		while (gamestate->enemy->next != NULL)
			gamestate->enemy = gamestate->enemy->next;
		gamestate->enemy->next = enemy;
	
	}
	gamestate->enemy->nr = gamestate->enemycount;
	gamestate->enemy->opposition->x = i;
	gamestate->enemy->opposition->y = j;
	gamestate->enemy->next = NULL;
}
