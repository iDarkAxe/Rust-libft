/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:45:21 by ppontet           #+#    #+#             */
/*   Updated: 2025/06/02 16:18:27 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "my_header.h"

void	do_on_argv(char **argv, uint32_t (*cmd)(uint32_t))
{
	size_t		index;
	size_t		letter;

	if (!argv)
		return ;
	index = 0;
	while (argv[index])
	{
		letter = 0;
		while (argv[index][letter])
		{
			printf("cmd of %c %u\n", argv[index][letter],
				cmd(argv[index][letter]));
			letter++;
		}
		index++;
		if (argv[index])
			printf("\n");
	}
}

int	main(int argc, char **argv)
{
	printf("sum is %u\n", addition(1, 2));
	if (argc == 1)
		return (0);
	printf("Test avec ft_isdigit\n");
	do_on_argv(&argv[1], ft_isdigit);
	printf("Test avec ft_isalnum\n");
	do_on_argv(&argv[1], ft_isalnum);
}
