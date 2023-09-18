#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

typedef struct s_options
{
	int		n;
	char	**filenames;
	int		file_count;
	int		option_count;
	int		bytes;
}	t_options;

// display_lines.c
void	display_lines(t_options *options, int index);
void	display_stdin(int bytes);

// ft_hexdump.c
void	ft_hexdump(int argc, char **argv);

// ft_hexdump_func.c
void	display_hexdump_error(char *filename);


#endif
