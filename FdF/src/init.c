/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:52:04 by ggavryly          #+#    #+#             */
/*   Updated: 2019/03/05 17:52:06 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

t_dt	*new_dot(int x, int y)
{
	t_dt *new;

	new = (t_dt *)malloc(sizeof(t_dt));


}

t_dt	*init_point(const char *line, int x, int y)
{
	t_dt	*new_point;
	t_dt	*prev;
	int		i;

	i = 0;
	while (line[i])
	{
		if (IS_SPC(line[i]))
			i++;

		i++;
	}
	new_point = (t_dt *)malloc(sizeof(t_dt));



}
