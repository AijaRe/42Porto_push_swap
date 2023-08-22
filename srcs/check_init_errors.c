#include "push_swap.h"

static int	check_non_numeric(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (argv[i][j] == '\0')
            return 1;
		while (argv[i][j] != '\0') 
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

static int	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_intcmp(ft_atol(argv[i]), ft_atol(argv[j])) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	out_of_int_range(int argc, char **argv)
{
	long num;
	int	i;

	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int check_init_errors(int argc, char **argv)
{
	if(check_non_numeric(argc, argv) == 1)
		ft_exit_error();
	if(check_duplicates(argc, argv) == 1)
		ft_exit_error();
	if(out_of_int_range(argc, argv) == 1)
		ft_exit_error();
	return (0);
}