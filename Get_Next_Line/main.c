/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 22:07:52 by btvildia          #+#    #+#             */
/*   Updated: 2023/12/15 14:10:35 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

size_t	mine_ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_nline(char *s, int c)
{
	c = (char)c;
	while (1)
	{
		if (!s)
		{
			return (0);
		}
		if (*s == c)
		{
			return ((char *)s);
		}
		if (*s == '\0')
		{
			break ;
		}
		s++;
	}
	return (NULL);
}

char	*mine_ft_strjoin(char *s1, char *s2)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	i;
	char			*a;

	i = -1;
	x = mine_ft_strlen(s1);
	y = mine_ft_strlen(s2);
	a = malloc(x + y + 1);
	if (!a)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[++i] != '\0')
			a[i] = s1[i];
	}
	i = 0;
	while (s2[i] != '\0')
	{
		a[x + i] = s2[i];
		i++;
	}
	a[x + i] = '\0';
	return (a);
}

char	*mine_ft_strjoin_null(char *s2)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	i;
	char			*a;

	i = 0;
	x = 0;
	y = mine_ft_strlen((char *)s2);
	a = malloc(x + y + 1);
	if (!a)
		return (NULL);
	a[i] = '\0';
	while (s2[i] != '\0')
	{
		a[x + i] = s2[i];
		i++;
	}
	a[x + i] = '\0';
	return (a);
}

char	*ft_reallocate(char *s1, char *s2)
{
	char	*str;

	if (!s1)
		str = mine_ft_strjoin_null(s2);
	else
		str = mine_ft_strjoin(s1, s2);
	free(s1);
	s1 = str;
	return (s1);
}

char	*mine_read_full(int fd, char *line)
{
	char	*buff;
	ssize_t	byte;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	byte = 1;
	while (!ft_nline(line, '\n') && byte > 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte < 0)
		{
			free(buff);
			free(line);
			return (NULL);
		}
		buff[byte] = '\0';
		line = ft_reallocate(line, buff);
	}
	free(buff);
	return (line);
}

char	*mine_ft_save(char *buff)
{
	int		i;
	char	*line;
	int		j;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	line = malloc(sizeof(char) * (mine_ft_strlen(buff) - i));
	if (!line)
		return (free(buff), NULL);
	i++;
	while (buff[i])
	{
		line[j++] = buff[i++];
	}
	line[j] = '\0';
	free(buff);
	return (line);
}

char	*mine_get_first_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*mine_get_next_line(int fd)
{
	static char	*fline;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fline = mine_read_full(fd, fline);
	if (!fline)
		return (NULL);
	line = mine_get_first_line(fline);
	fline = mine_ft_save(fline);
	return (line);
}

int	check_Norm(const char *filename)
{
	char	command[256];
	FILE	*fp;
	char	buffer[128];
	int		errorFound;

	snprintf(command, sizeof(command), "norminette %s", filename);
	fp = popen(command, "r");
	errorFound = 0;
	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		printf("%s", buffer);
		if (strstr(buffer, "Error") != NULL)
		{
			errorFound = 1;
		}
	}
	if (errorFound)
	{
		printf(RED "❌ NORM: [ERROR]\n" RESET);
	}
	else
	{
		printf(GREEN "✅ NORM: [OK]\n" RESET);
	}
	pclose(fp);
	return (errorFound ? EXIT_FAILURE : EXIT_SUCCESS);
}

int	check_basic(void)
{
	int		answer;
	int		fd;
    int fd1;
	fd = open("text.txt", O_RDONLY);
    fd1 = open("text.txt", O_RDONLY);
	char	*a[] = {mine_get_next_line(fd), mine_get_next_line(fd), mine_get_next_line(fd),
			mine_get_next_line(fd), mine_get_next_line(fd), mine_get_next_line(fd)};
	char	*b[] = {get_next_line(fd1), get_next_line(fd1), get_next_line(fd1),
			get_next_line(fd1), get_next_line(fd1), get_next_line(fd1)};
	int		len;

	answer = 1;
	usleep(100000);
	len = sizeof(b) / sizeof(b[1]);
	printf(YELLOW"\n__________[BASIC_INPUT]__________\n"RESET);
	for (int i = 0; i < len - 1; i++)
	{
		if (strcmp(a[i], b[i]) == 0)
		{
			usleep(50000);
            printf("%s", a[i]);
			printf(GREEN"✅[OK]\n" RESET);
            printf("%s", b[i]);
            printf(GREEN"✅[OK]\n" RESET);
		}
		else
		{
            usleep(50000);
            printf("%s", a[i]);
			printf(RED"\n❌[KO]" RESET);
            printf("%s", b[i]);
            printf(RED"\n❌[KO]" RESET);
			answer = 0;
		}
	}
    if(a[5] == NULL)
    {
        usleep(50000);
        printf("%s", NULL);
		printf(GREEN"✅[OK]\n" RESET);
        printf("%s", NULL);
        printf(GREEN"✅[OK]\n" RESET);
    }
	printf("\n");
	if (answer == 1)
	{
		usleep(50000);
		printf(GREEN "✅  [CHECK] \n" RESET);
	}
	else
	{
		usleep(50000);
		printf(RED "❌  [ERROR] \n" RESET);
	}
	return (answer);
}

int	check_nline(void)
{
    	int		answer;
	int		fd;
    int fd1;
	fd = open("nline.txt", O_RDONLY);
    fd1 = open("nline.txt", O_RDONLY);
	char	*a[] = {mine_get_next_line(fd), mine_get_next_line(fd), mine_get_next_line(fd),
			mine_get_next_line(fd), mine_get_next_line(fd), mine_get_next_line(fd)};
	char	*b[] = {get_next_line(fd1), get_next_line(fd1), get_next_line(fd1),
			get_next_line(fd1), get_next_line(fd1), get_next_line(fd1)};
	int		len;

	answer = 1;
	usleep(100000);
	len = sizeof(b) / sizeof(b[1]);
	printf(YELLOW"\n__________[NLINE]__________\n"RESET);
	for (int i = 0; i < len - 1; i++)
	{
		if (strcmp(a[i], b[i]) == 0)
		{
			usleep(50000);
			printf(GREEN"[CHECK]✅[OK]\n" RESET);
		}
		else
		{
            usleep(50000);
            printf("%s", a[i]);
			printf(RED"[CHECK]❌[KO]\n" RESET);
            printf("%s", b[i]);
            printf(RED"[CHECK]❌[KO]\n" RESET);
			answer = 0;
		}
	}
    if(a[5] == NULL)
    {
        usleep(50000);
        printf("%s", NULL);
		printf(GREEN"✅[OK]\n" RESET);
        printf("%s", NULL);
        printf(GREEN"✅[OK]\n" RESET);
    }
	printf("\n");
	if (answer == 1)
	{
		usleep(50000);
		printf(GREEN "✅  [CHECK] \n" RESET);
	}
	else
	{
		usleep(50000);
		printf(RED "❌  [ERROR] \n" RESET);
	}
	printf("\n");
	return (answer);
}

int	main(void)
{
	char		failed_functions[1024];
	const char	*files[] = {"get_next_line.c", "get_next_line.h",
			"get_next_line_utils.c", "get_next_line_bonus.c",
			"get_next_line_bonus.h", "get_next_line_utils_bonus.c"};
	int			overallStatus;
	int			status;
	const char	*filename;

	overallStatus = EXIT_SUCCESS;
	for (size_t i = 0; i < sizeof(files) / sizeof(files[0]); i++)
	{
		filename = files[i];
		status = check_Norm(filename);
		if (status == EXIT_FAILURE)
		{
			overallStatus = EXIT_FAILURE;
		}
	}
	!check_basic() && strcat(failed_functions, "basic_check ");
    !check_nline() && strcat(failed_functions, "nline ");
	if (overallStatus == EXIT_SUCCESS)
	{
		printf(GREEN "✅ [All files passed norminette checks]\n" RESET);
	}
	else
	{
		printf(RED "❌ [One or more files failed norminette checks]\n" RESET);
	}
	if (mine_ft_strlen(failed_functions) > 5)
	{
		printf(RED "❌ [One or more files failed in tests]\n" RESET);
		printf(RED "\nFailed functions: [ %s ]\n\n", failed_functions);
	}
	else
	{
		printf(GREEN "✅ [All files passed tests]\n" RESET);
	}
	printf("\n");
	return (overallStatus);
}
