#include "stdio.h"

int	philo_atoi(char *s)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	if (s[i] == '+')
		i++;
	while (s[i]  >=  '0' && s[i] <= '9')
		r = r * 10 + (s[i++] - '0');
	if (s[i] != '\0')
		return (-1);
	return (r);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%d\n", philo_atoi(argv[1]));
	}	
}
