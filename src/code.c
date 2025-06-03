/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:45:21 by ppontet           #+#    #+#             */
/*   Updated: 2025/06/03 11:36:39 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	do_on_argv(char **argv, uint32_t (*cmd)(uint32_t), const char *name)
{
	size_t		index;
	size_t		letter;

	if (!argv || !argv[0])
		return ;
	index = 0;
	printf("Test avec %s\n", name);
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
	char	*str;

	(void)argc;
	str = "Je suis une chaine";
	do_on_argv(&argv[1], ft_isdigit, "ft_isdigit");
	do_on_argv(&argv[1], ft_isalnum, "ft_isalnum");
	printf("longueur de str %s = %zu", str, ft_strlen(str));
}
