/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:58:40 by btvildia          #+#    #+#             */
/*   Updated: 2023/12/16 20:18:18 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define RESET "\x1b[0m"

int	check_size(void)
{
	int	answer;

	int a[14] = {printf("hello"),
					printf("%s", "hello"),
					printf("%d", 256),
					printf("%d", -256),
					printf("%x", 25672),
					printf("%X", 154433),
					printf("hello"
						"world"),
					printf("%s %s", "Hello", "World"),
					printf("%s %d", "Hello my friends", -41231),
					printf("%s %d %x", "Hello", 52, 12344),
					printf("%s %X", "HELLO my friends", 0),
					printf("%s %X %x", "HELLO my friends", 0, 0),
					printf("%X %x %s", 0, 0, "HELLO my friendsssssadas"),
					printf("%d %X %s", 25435, 2112333, "HELLO friendsss")};
	int b[14] = {ft_printf("hello"),
					ft_printf("%s", "hello"),
					ft_printf("%d", 256),
					ft_printf("%d", -256),
					ft_printf("%x", 25672),
					ft_printf("%X", 154433),
					ft_printf("hello"
							"world"),
					ft_printf("%s %s", "Hello", "World"),
					ft_printf("%s %d", "Hello my friends", -41231),
					ft_printf("%s %d %x", "Hello", 52, 12344),
					ft_printf("%s %X", "HELLO my friends", 0),
					ft_printf("%s %X %x", "HELLO my friends", 0, 0),
					ft_printf("%X %x %s", 0, 0, "HELLO my friendsssssadas"),
					ft_printf("%d %X %s", 25435, 2112333, "HELLO friendsss")};
	answer = 1;
	usleep(100000);
	printf(YELLOW "\n|====SIZE====|\n" RESET);
	for (unsigned long i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		if (a[i] == b[i])
		{
			usleep(50000);
			printf(BLUE "%d" RESET, a[i]);
			printf(GREEN "\n✅[ORIGINAL]" RESET);
			printf("%d", a[i]);
			printf(GREEN "\n✅[FT_PRINT]" RESET);
			printf("%d", b[i]);
			printf("\n");
		}
		else
		{
			usleep(50000);
			printf(BLUE "%d" RESET, a[i]);
			printf(GREEN "\n✅[ORIGINAL]" RESET);
			printf("%d", a[i]);
			printf(RED "\n❌[FT_PRINT]" RESET);
			printf(RED "%d" RESET, b[i]);
			printf("\n");
			answer = 0;
		}
	}
	printf("\n");
	return (answer);
}

int	main(void)
{
	char	failed_functions[1024];

	!check_size() && strcat(failed_functions, "size_check ");
	if (strlen(failed_functions) > 5)
	{
		printf(RED "❌ [One or more files failed in tests]\n" RESET);
		printf(RED "\nFailed tests: [ %s ]\n\n", failed_functions);
	}
	else
	{
		printf(GREEN "✅ [All tests passed]\n" RESET);
	}
	printf("\n");
	return (0);
}
