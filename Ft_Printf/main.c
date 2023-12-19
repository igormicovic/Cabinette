/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:58:40 by btvildia          #+#    #+#             */
/*   Updated: 2023/12/19 13:29:59 by btvildia         ###   ########.fr       */
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

	int a[22] = {printf("hello"),
					printf("%s", "hello"),
					printf("%p", ""),
					printf("%p %p", "", ""),
					printf("%s %%", "hello"),
					printf("%d", 256),
					printf("%d", -256),
					printf("%x", 25672),
					printf("%X", 154433),
					printf("%p", (void *)0x12345678),
					printf("%p %p", (void *)0x12345678, (void *)0x12344444),
					printf("%u %u", -553, 553),
					printf("%u %u %u", -553, -553, -23123312),
					printf("hello"
						"world"),
					printf("%s %s", "Hello", "World"),
					printf("%s %d", "Hello my friends", -41231),
					printf("%s %d %x", "Hello", 52, 12344),
					printf("%s %X", "HELLO my friends", 0),
					printf("%s %X %x", "HELLO my friends", 0, 0),
					printf("%X %x %s", 0, 0, "HELLO my friendsssssadas"),
					printf("%d %X %s", 25435, 2112333, "HELLO friendsss"),
					printf("%d %p %s", 25435, (void *)0x12344444,
						"HELLO friendsss")};
	int b[22] = {ft_printf("hello"),
					ft_printf("%s", "hello"),
					ft_printf("%p", ""),
					ft_printf("%p %p", "", ""),
					ft_printf("%s %%", "hello"),
					ft_printf("%d", 256),
					ft_printf("%d", -256),
					ft_printf("%x", 25672),
					ft_printf("%X", 154433),
					ft_printf("%p", (void *)0x12345678),
					ft_printf("%p %p", (void *)0x12345678, (void *)0x12344444),
					ft_printf("%u %u", -553, 553),
					ft_printf("%u %u %u", -553, -553, -23123312),
					ft_printf("hello"
							"world"),
					ft_printf("%s %s", "Hello", "World"),
					ft_printf("%s %d", "Hello my friends", -41231),
					ft_printf("%s %d %x", "Hello", 52, 12344),
					ft_printf("%s %X", "HELLO my friends", 0),
					ft_printf("%s %X %x", "HELLO my friends", 0, 0),
					ft_printf("%X %x %s", 0, 0, "HELLO my friendsssssadas"),
					ft_printf("%d %X %s", 25435, 2112333, "HELLO friendsss"),
					ft_printf("%d %p %s", 25435, (void *)0x12344444,
						"HELLO friendsss")};
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

int	check_c(void)
{
	int	answer;
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;
	int	n;

	answer = 1;
	i = printf("%c", 'C');
	j = ft_printf("%c", 'C');
	k = printf("%c", '\0');
	l = ft_printf("%c", '\0');
	m = printf("%c", '\n');
	n = ft_printf("%c", '\n');
	printf(YELLOW "|====CHECK_C====|\n" RESET);
	if (i == j)
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%c", 'C');
		printf(GREEN "\n✅[FT_PRINT]" RESET);
		printf("%c", 'C');
		printf("\n");
	}
	else
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%c", 'C');
		printf(RED "\n❌[FT_PRINT]" RESET);
		printf(RED "%c" RESET, 'C');
		printf("\n");
	}
	if (j == k)
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%c", '\0');
		printf(GREEN "\n✅[FT_PRINT]" RESET);
		printf("%c", '\0');
		printf("\n");
	}
	else
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%c", '\0');
		printf(RED "\n❌[FT_PRINT]" RESET);
		printf(RED "%c" RESET, '\0');
		printf("\n");
	}
	if (m == n)
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%s", "Newline");
		printf(GREEN "\n✅[FT_PRINT]" RESET);
		printf("%s", "Newline");
		printf("\n");
	}
	else
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%s", "Newline");
		printf(RED "\n❌[FT_PRINT]" RESET);
		printf(RED "%s" RESET, "Newline");
		printf("\n");
	}
	printf("\n");
	return (answer);
}

int	check_s(void)
{
	int	answer;
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;
	int	n;

	answer = 1;
	i = printf("Hello world");
	j = ft_printf("Hello world");
	k = printf("%s", "hello \0, world");
	l = ft_printf("%s", "hello \0, world");
	m = printf("%s", NULL);
	n = ft_printf("%s", NULL);
	printf("\n");
	printf(YELLOW "\n|====CHECK_S====|\n" RESET);
	if (i == j)
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("Hello world");
		printf(GREEN "\n✅[FT_PRINT]" RESET);
		printf("Hello world");
		printf("\n");
	}
	else
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("Hello world");
		printf(RED "\n❌[FT_PRINT]" RESET);
		printf(RED "%s" RESET, "Hello world");
		printf("\n");
	}
	if (k)
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%s", "hello \0, world");
		printf(GREEN "\n✅[FT_PRINT]" RESET);
		printf("%s", "hello \0, world");
		printf("\n");
	}
	else
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%s", "hello \0, world");
		printf(RED "\n❌[FT_PRINT]" RESET);
		printf(RED "%s" RESET, "helo world");
		printf("\n");
	}
	if (m == n)
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%s", NULL);
		printf(GREEN "\n✅[FT_PRINT]" RESET);
		printf("%s", NULL);
		printf("\n");
	}
	else
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%s", NULL);
		printf(RED "\n❌[FT_PRINT]" RESET);
		printf(RED "%s" RESET, NULL);
		printf("\n");
	}
	printf("\n");
	return (answer);
}

int	check_p(void)
{
	int	answer;
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;
	int	n;

	answer = 1;
	i = printf("%p", (void *)0x12345678);
	j = ft_printf("%p", (void *)0x12345678);
	k = printf("%p %p", (void *)0x12345678, (void *)0x12344444);
	l = ft_printf("%p %p", (void *)0x12345678, (void *)0x12344444);
	m = printf("%p", "");
	n = ft_printf("%p"
					"");
	printf("\n");
	printf(YELLOW "\n|====CHECK_P====|\n" RESET);
	if (i == j)
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%p", (void *)0x12345678);
		printf(GREEN "\n✅[FT_PRINT]" RESET);
		printf("%p", (void *)0x12345678);
		printf("\n");
	}
	else
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%p", (void *)0x12345678);
		printf(RED "\n❌[FT_PRINT]" RESET);
		printf(RED "%p" RESET, (void *)0x12345678);
		printf("\n");
	}
	if (k)
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%p %p", (void *)0x12345678, (void *)0x12344444);
		printf(GREEN "\n✅[FT_PRINT]" RESET);
		printf("%p %p", (void *)0x12345678, (void *)0x12344444);
		printf("\n");
	}
	else
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%p %p", (void *)0x12345678, (void *)0x12344444);
		printf(RED "\n❌[FT_PRINT]" RESET);
		printf(RED "%p %p" RESET, (void *)0x12345678, (void *)0x12344444);
		printf("\n");
	}
	if (n)
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%p", "");
		printf(GREEN "\n✅[FT_PRINT]" RESET);
		printf("%p", "");
		printf("\n");
	}
	else
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%p", "");
		printf(RED "\n❌[FT_PRINT]" RESET);
		printf(RED "%p" RESET, "");
		printf("\n");
	}
	printf("\n");
	return (answer);
}

int	check_d(void)
{
	int	answer;
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;
	int	n;

	answer = 1;
	i = printf("%d", 12345);
	j = ft_printf("%d", 12345);
	k = printf("%d %d", 12345, -12345);
	l = ft_printf("%d %d", 12345, -12345);
	m = printf("%d", -2147483647);
	n = ft_printf("%d", -2147483647);
	printf("\n");
	printf(YELLOW "\n|====CHECK_D====|\n" RESET);
	if (i == j)
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%d", 12345);
		printf(GREEN "\n✅[FT_PRINT]" RESET);
		printf("%d", 12345);
		printf("\n");
	}
	else
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%d", 12345);
		printf(RED "\n❌[FT_PRINT]" RESET);
		printf(RED "%d" RESET, 12345);
		printf("\n");
	}
	if (k)
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%d %d", 12345, -12345);
		printf(GREEN "\n✅[FT_PRINT]" RESET);
		printf("%d %d", 12345, -12345);
		printf("\n");
	}
	else
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%d %d", 12345, -12345);
		printf(RED "\n❌[FT_PRINT]" RESET);
		printf(RED "%d %d" RESET, 12345, -12345);
		printf("\n");
	}
	if (n)
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%d", -2147483647);
		printf(GREEN "\n✅[FT_PRINT]" RESET);
		printf("%d", -2147483647);
		printf("\n");
	}
	else
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%d", -2147483647);
		printf(RED "\n❌[FT_PRINT]" RESET);
		printf(RED "%d" RESET, -2147483647);
		printf("\n");
	}
	printf("\n");
	return (answer);
}

int	check_x(void)
{
	int	answer;
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;
	int	n;

	answer = 1;
	i = printf("%x", 12345);
	j = ft_printf("%x", 12345);
	k = printf("%x %x", 12345, -12345);
	l = ft_printf("%x %x", 12345, -12345);
	m = printf("%x", -2147483647);
	n = ft_printf("%x", -2147483647);
	printf("\n");
	printf(YELLOW "\n|====CHECK_X(LOW)====|\n" RESET);
	if (i == j)
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%x", 12345);
		printf(GREEN "\n✅[FT_PRINT]" RESET);
		printf("%x", 12345);
		printf("\n");
	}
	else
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%x", 12345);
		printf(RED "\n❌[FT_PRINT]" RESET);
		printf(RED "%x" RESET, 12345);
		printf("\n");
	}
	if (k)
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%x %x", 12345, -12345);
		printf(GREEN "\n✅[FT_PRINT]" RESET);
		printf("%x %x", 12345, -12345);
		printf("\n");
	}
	else
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%x %x", 12345, -12345);
		printf(RED "\n❌[FT_PRINT]" RESET);
		printf(RED "%x %x" RESET, 12345, -12345);
		printf("\n");
	}
	if (n)
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%x", -2147483647);
		printf(GREEN "\n✅[FT_PRINT]" RESET);
		printf("%x", -2147483647);
		printf("\n");
	}
	else
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%x", -2147483647);
		printf(RED "\n❌[FT_PRINT]" RESET);
		printf(RED "%x" RESET, -2147483647);
		printf("\n");
	}
	printf("\n");
	return (answer);
}

int	check_X(void)
{
	int	answer;
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;
	int	n;

	answer = 1;
	i = printf("%X", 22543);
	j = ft_printf("%X", 22543);
	k = printf("%X %X", 22543, -22543);
	l = ft_printf("%X %X", 22543, -22543);
	m = printf("%X", -2147483647);
	n = ft_printf("%X", -2147483647);
	printf("\n");
	printf(YELLOW "\n|====CHECK_X(UP)====|\n" RESET);
	if (i == j)
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%X", 22543);
		printf(GREEN "\n✅[FT_PRINT]" RESET);
		printf("%X", 22543);
		printf("\n");
	}
	else
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%X", 22543);
		printf(RED "\n❌[FT_PRINT]" RESET);
		printf(RED "%X" RESET, 22543);
		printf("\n");
	}
	if (k)
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%X %X", 22543, -22543);
		printf(GREEN "\n✅[FT_PRINT]" RESET);
		printf("%X %X", 22543, -22543);
		printf("\n");
	}
	else
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%X %X", 22543, -22543);
		printf(RED "\n❌[FT_PRINT]" RESET);
		printf(RED "%X %X" RESET, 22543, -22543);
		printf("\n");
	}
	if (n)
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%X", -2147483647);
		printf(GREEN "\n✅[FT_PRINT]" RESET);
		printf("%X", -2147483647);
		printf("\n");
	}
	else
	{
		usleep(50000);
		printf(BLUE "%d" RESET, 1);
		printf(GREEN "\n✅[ORIGINAL]" RESET);
		printf("%X", -2147483647);
		printf(RED "\n❌[FT_PRINT]" RESET);
		printf(RED "%X" RESET, -2147483647);
		printf("\n");
	}
	printf("\n");
	return (answer);
}

int	main(void)
{
	char	failed_functions[1024];

	!check_size() && strcat(failed_functions, "size_check ");
	!check_c() && strcat(failed_functions, "C_check ");
	!check_s() && strcat(failed_functions, "S_check ");
	!check_p() && strcat(failed_functions, "P_check ");
	!check_d() && strcat(failed_functions, "D_check ");
	!check_x() && strcat(failed_functions, "X(low)_check ");
	!check_X() && strcat(failed_functions, "X(up)_check ");
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
