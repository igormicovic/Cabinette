#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

# define RED "\x1b[31m"
# define BLUE "\x1b[34m"
# define RESET "\x1b[0m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define PURPLE "\x1b[35m"

typedef struct s_node
{
	int	*a;
	int	*b;
	int	a_size;
	int	b_size;
}		t_node;

void	error1(int *a);
void	s_a1(t_node *node);
void	p_a1(t_node *node);
void	r_a1(t_node *node);
void	s_b1(t_node *node);
void	p_b1(t_node *node);
void	r_b1(t_node *node);
void	ft_error11(char *a);
void	ft_put1nbr(int nb);
int		ft_count1(char *a);
void	ft_put1char(char a);
int		ft_strlen1(char *a);
void	r_r_a11(t_node *node);
void	r_r_b11(t_node *node);
char	**ft_split1(char *a);
int		ft_atoi1(const char *str);
void	sorting1(t_node *a, int size, char **av);
void	if_doubles1(int *a, int size);
void	display_algo1(int *x, int check);
char	*ft_strncpy1(char *s1, char *s2, int n);
int		if_sorted1(int *a, int size, int order);
char	**ft_put1(char **c, char *a, int i, int j);
char	**ft_put1(char **c, char *a, int i, int j);

void	s_a1(t_node *node)
{
	int	i;

	if (node->a_size == 0 || node->a_size == 1)
		return ;
	i = 0;
	i = node->a[0];
	node->a[0] = node->a[1];
	node->a[1] = i;
}

void	p_a1(t_node *node)
{
	int	i;

	if (node->b_size)
	{
		node->a_size++;
		i = node->a_size;
		while (i > 0)
		{
			node->a[i] = node->a[i - 1];
			i--;
		}
		node->a[0] = node->b[0];
		i = 0;
		node->b_size--;
		while (i < node->b_size)
		{
			node->b[i] = node->b[i + 1];
			i++;
		}
	}
	else
		return ;
}

void	r_a1(t_node *node)
{
	int	j;
	int	i;

	if (node->a_size == 0 || node->a_size == 1)
		return ;
	i = 0;
	j = node->a[i];
	i++;
	while (i < node->a_size)
	{
		node->a[i - 1] = node->a[i];
		i++;
	}
	node->a[i - 1] = j;
}

void	r_r_a11(t_node *node)
{
	int	j;
	int	i;

	if (node->a_size == 0 || node->a_size == 1)
		return ;
	i = node->a_size - 1;
	j = node->a[i];
	while (i)
	{
		node->a[i] = node->a[i - 1];
		i--;
	}
	node->a[i] = j;
}

void	s_b1(t_node *node)
{
	int	i;

	if (node->b_size == 0 || node->b_size == 1)
		return ;
	i = 0;
	i = node->b[0];
	node->b[0] = node->b[1];
	node->b[1] = i;
}

void	p_b1(t_node *node)
{
	int	i;

	if (node->a_size)
	{
		node->b_size++;
		i = node->b_size;
		while (i > 0)
		{
			node->b[i] = node->b[i - 1];
			i--;
		}
		node->b[0] = node->a[0];
		i = 0;
		node->a_size--;
		while (i < node->a_size)
		{
			node->a[i] = node->a[i + 1];
			i++;
		}
	}
	else
		return ;
}

void	r_b1(t_node *node)
{
	int	j;
	int	i;

	if (node->b_size == 0 || node->b_size == 1)
		return ;
	i = 0;
	j = node->b[i];
	i++;
	while (i < node->b_size)
	{
		node->b[i - 1] = node->b[i];
		i++;
	}
	node->b[i - 1] = j;
}

void	r_r_b11(t_node *node)
{
	int	tmp;
	int	i;

	if (node->b_size == 0 || node->b_size == 1)
		return ;
	i = node->b_size - 1;
	tmp = node->b[i];
	while (i)
	{
		node->b[i] = node->b[i - 1];
		i--;
	}
	node->b[i] = tmp;
}

void	error1(int *a)
{
	free(a);
	printf("Error1\n");
	exit(1);
}

void	if_doubles1(int *a, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (a[i] == a[j])
				error1(a);
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	if_sorted1(int *a, int size, int order)
{
	int	i;

	i = 1;
	if (order == 0)
	{
		while (i < size)
		{
			if (a[i - 1] > a[i])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		while (i < size)
		{
			if (a[i - 1] < a[i])
				return (0);
			i++;
		}
		return (1);
	}
}

void	ft_put1char(char a)
{
	write(1, &a, 1);
}

int	ft_strlen1(char *a)
{
	int	i;

	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

void	ft_put1nbr(int nb)
{
	if (nb < 0)
	{
		ft_put1char('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_put1nbr(nb / 10);
	ft_put1char((nb % 10) + '0');
}

char	*ft_strncpy1(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	ft_atoi1(const char *str)
{
	long	i;
	long	x;
	int		s;

	i = 0;
	x = 0;
	s = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error11("Error1");
		x = x * 10 + (str[i] - '0');
		i++;
	}
	if (x > 2147483648)
		ft_error11("Error1");
	return (x * s);
}

void	ft_error11(char *a)
{
	printf("%s\n", a);
	exit(1);
}

int	ft_count1(char *a)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (a[i])
	{
		while (a[i] && a[i] == ' ')
			i++;
		if (a[i])
			j++;
		while (a[i] && a[i] != ' ')
			i++;
	}
	return (j);
}

char	**ft_put1(char **c, char *a, int i, int j)
{
	int	x;

	x = 0;
	while (a[i])
	{
		while (a[i] && a[i] == ' ')
			i++;
		j = i;
		while (a[i] && a[i] != ' ')
			i++;
		if (i > j)
		{
			c[x] = malloc(sizeof(char) * (i - j) + 1);
			ft_strncpy1(c[x], &a[j], i - j);
			x++;
		}
	}
	c[x] = NULL;
	return (c);
}

char	**ft_split1(char *a)
{
	int		i;
	int		j;
	char	**c;

	i = 0;
	j = ft_count1(a);
	c = malloc(sizeof(char *) * j + 1);
	i = 0;
	j = 0;
	c = ft_put1(c, a, i, j);
	return (c);
}

char	*put_dot(int x)
{
	int		i;
	char	*a;
	int		j;

	a = malloc(sizeof(char) * 101);
	j = 0;
	i = -50;
	while (x >= i)
	{
		a[j] = '.';
		j++;
		x--;
	}
	return (a);
}

void	display_algo1(int *x, int check)
{
	char	**c;
	int		i;

	i = 0;
	c = malloc(sizeof(char *) * 101);
	while (i < 101)
	{
		c[i] = put_dot(x[i]);
		i++;
	}
	i = 0;
	if (check == 1)
	{
		while (i < 101)
		{
			printf(GREEN "%s\n" RESET, c[i]);
			i++;
		}
	}
	else
	{
		while (i < 101)
		{
			printf(RED "%s\n" RESET, c[i]);
			i++;
		}
	}
	usleep(25000);
	free(c);
}

void	sorting1(t_node *node, int size, char **av)
{
	int i = 0;
	while(av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
	i = 0;
	while(if_sorted1(node->a, size, 0) == 0 && av[i])
	{
		i++;
		if(strcmp(av[i], "pa") == 0)
		{
			p_a1(node);
			display_algo1(node->a, 0);
		}
		else if(strcmp(av[i], "pb") == 0)
		{
			p_b1(node);
			display_algo1(node->a, 0);
		}
		else if(strcmp(av[i], "sa") == 0)
		{
			s_a1(node);
			display_algo1(node->a, 0);
		}
		else if(strcmp(av[i], "sb") == 0)
		{
			s_b1(node);
			display_algo1(node->a, 0);
		}
		else if(strcmp(av[i], "ra") == 0)
		{
			r_a1(node);
			display_algo1(node->a, 0);
		}
		else if(strcmp(av[i], "rb") == 0)
		{
			r_b1(node);
			display_algo1(node->a, 0);
		}
		else if(strcmp(av[i], "rra") == 0)
		{
			r_r_a11(node);
			display_algo1(node->a, 0);
		}
		else if(strcmp(av[i], "rrb") == 0)
		{
			r_r_b11(node);
			display_algo1(node->a, 0);
		}
		else if(strcmp(av[i], "ss") == 0)
		{
			s_a1(node);
			s_b1(node);
			display_algo1(node->a, 0);
		}
		else if(strcmp(av[i], "rr") == 0)
		{
			r_a1(node);
			r_b1(node);
			display_algo1(node->a, 0);
		}
		else if(strcmp(av[i], "rrr") == 0)
		{
			r_r_a11(node);
			r_r_b11(node);
			display_algo1(node->a, 0);
		}
		else
		{
			printf("Error1\n");
			exit(1);
		}
	}
}

int	main(int ac, char **av)
{
	int			i;
	t_node		node;
	int			x[101] = {-48, -46, 0, 50, 17, 44, -2, -24, -25, 27, -6, -23, 10, -30, -7, 26, -42, 41, 8, -13, 46, 39, 42, -22, -14, -35, -44, -40, 2, 24, 15, -36, 30, 34, 37, 38, -19, 16, -50, -43, -45, 7, 13, -31, 18, -27, -47, 32, -34, 22, 23, 25, 19, -12, 40, -21, -20, 11, 9, -11, -28, -32, 47, -15, 45, 29, 14, -5, 20, -29, 21, 6, -10, 28, 33, -26, -41, -16, 36, 1, 12, 35, 43, 49, 4, -1, 5, 31, -49, -9, -38, -17, 3, -4, 48, -39, -18, -8, -33, -3, -37};
	int			st;

	node.a = malloc(sizeof(int) * 101);
	node.b = malloc(sizeof(int) * 101);
	node.a_size = 101;
	node.b_size = 0;
	i = 0;
	st = EXIT_SUCCESS;
	while (i < 101)
	{
		node.a[i] = x[i];
		i++;
	}

	printf(GREEN "\n[RANDOM DIFFERENT NUMBER VALUES]\n" RESET);
	display_algo1(node.a, 0);
	usleep(2500000);
	sorting1(&node, 101, av);
	display_algo1(node.a, 1);
	if (st == EXIT_SUCCESS)
	{
		printf(GREEN "✅ [All files passed tests]\n" RESET);
	}
	else
	{
		printf(RED "❌ [One or more files failed in tests]\n" RESET);
	}
	printf("\n");
	return (st);
}
