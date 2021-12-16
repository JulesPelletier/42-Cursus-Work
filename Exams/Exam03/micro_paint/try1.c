#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_zone
{
    int width;
    int height;
    char backgrond;
} 				t_zone;

typedef struct	s_cercle
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	color;
} 				t_cercle;

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_exit(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int	free_all(FILE *file, char *draw)
{
	fclose(file);
	if (draw)
		free(draw);
	return (1);
}
