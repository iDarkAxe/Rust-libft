/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:45:21 by ppontet           #+#    #+#             */
/*   Updated: 2025/06/02 15:45:21 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "my_header.h"

int	main(int argc, char **argv, char **envp)
{
	size_t		index;
	size_t		letter;
	uint32_t	sum;

	sum = addition(1, 2);
	printf("sum is %u\n", sum);

	if (argc == 1)
		return (0);
	index = 1;
	while (argv[index])
	{
		letter = 0;
		while (argv[index][letter])
		{
			printf("isalnum of %c %u\n", argv[index][letter],
				ft_isalnum(argv[index][letter]));
			letter++;
		}
		index++;
		if (argv[index])
			printf("\n");
	}

	index = 1;
	while (argv[index])
	{
		letter = 0;
		while (argv[index][letter])
		{
			printf("isdigit of %c %u\n", argv[index][letter],
				ft_isdigit(argv[index][letter]));
			letter++;
		}
		index++;
		if (argv[index])
			printf("\n");
	}
}
