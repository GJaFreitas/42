#include "../minishell.h"

// Display prompt and read the next line given to it
char	*prompt(char *buf)
{
	char	cwd[CWD_BUFFER];

	buf = NULL;
	if (!getcwd(cwd, CWD_BUFFER))
		perror("getcwd() error\n");
	ft_printf("%s »", cwd);
	buf = get_next_line(1);
	if (feof(stdin))
		ft_printf("[EOF]\n");
	else
		perror("Buffer too small, EOF not reached\n");
	ft_printf("String: %s\n", buf);
	return (buf);
}

int	main(int argc, char **argv)
{
	char	*line;

	(void)argc;
	(void)argv;
	line = NULL;
	while (prompt(line))
	{
	}
	return (0);
}
