/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktayabal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:50:48 by ktayabal          #+#    #+#             */
/*   Updated: 2025/02/22 09:50:50 by ktayabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// enqueue function
void	enqueue(t_queue *q, t_point *point)
{
	t_point_list	*new;

	new = (t_point_list *)malloc(sizeof(t_point_list));
	if (!new)
		return ;
	new->point = point;
	new->next = NULL;
	if (!q->rear)
	{
		q->front = new;
		q->rear = new;
	}
	else
	{
		q->rear->next = new;
		q->rear = new;
	}
}

// dequeue function
t_point	*dequeue(t_queue *q)
{
	t_point_list	*tmp;
	t_point			*point;

	if (!q->front)
		return (NULL);
	tmp = q->front;
	q->front = q->front->next;
	if (!q->front)
		q->rear = NULL;
	point = tmp->point;
	free(tmp);
	return (point);
}

// new_point function
t_point	*new_point(int x, int y)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	return (point);
}

// flood_fill function
int	flood_fill(char **map, t_point *player, int rows, int columns)
{
	t_queue		q;
	t_point		*point;
	int			i;
	int			j;

	q.front = NULL;
	q.rear = NULL;
	enqueue(&q, player);
	while (q.front)
	{
		point = dequeue(&q);
		i = point->x;
		j = point->y;
		if (i > 0 && map[i - 1][j] != '1')
		{
			if (map[i - 1][j] == 'E')
				return (1);
			enqueue(&q, new_point(i - 1, j));
			map[i - 1][j] = '1';
		}
		if (i < rows - 1 && map[i + 1][j] != '1')
		{
			if (map[i + 1][j] == 'E')
				return (1);
			enqueue(&q, new_point(i + 1, j));
			map[i + 1][j] = '1';
		}
		if (j > 0 && map[i][j - 1] != '1')
		{
			if (map[i][j - 1] == 'E')
				return (1);
			enqueue(&q, new_point(i, j - 1));
			map[i][j - 1] = '1';
		}
		if (j < columns - 1 && map[i][j + 1] != '1')
		{
			if (map[i][j + 1] == 'E')
				return (1);
			enqueue(&q, new_point(i, j + 1));
			map[i][j + 1] = '1';
		}
	}
	return (0);
}


