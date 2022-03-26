/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 01:48:22 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/26 03:07:55 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <time.h>

int main(int ac, char **av)
{
	int	i;
	int	fd = open(av[1], O_RDONLY);
	char	*str;
	i = 0;
	clock_t t;
    t = clock();
	while (i < atoi(av[2]))
	{
		str = get_next_line(fd);
		printf("%s", str);
		if (str)
			free(str);
		i++;
	}
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\n\n~GNL() took %f secondes to execute and it produced %d lines.\n", time_taken, i - 1);
	close (fd);
	return (0);
}
