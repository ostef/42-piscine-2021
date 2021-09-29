#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

static int	ft_read_line()
{
	char	buffer[10000];

	return (read (0, buffer, 10000));
}

int	main()
{
	char	c;
	int		step;
	int		n;
	char	empty;
	char	obst;
	char	fill;

	n = 0;
	step = 0;
	while (1)
	{
		if (read (0, &c, 1) == 0)
			break ;
		if (step == 0)
		{
			if (c >= '0' && c <= '9')
			{
				n *= 10;
				n += c - '0';
			}
			else
				step += 1;
		}
		if (step == 1)
		{
			empty = c;
			step += 1;
		}
		else if (step == 2)
		{
			obst = c;
			step += 1;
		}
		else if (step == 3)
		{
			fill = c;
			printf ("Read fill char %c.\n", fill);
			break ;
		}
	}
	printf ("%d %c %c %c\n", n, empty, obst, fill);
	int i = 0;
	int	width = 0;
	int	len = 0;
	while (i < n)
	{
		len = ft_read_line ();
		printf ("len = %d\n", len);
		if (!width)
			width = len - 1;
		if (len + 1 != width)
			break;
	}
}
