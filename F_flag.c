#include "../includes/FT_LS.h"

void	F_print(t_dir *head)
{
	struct stat buf;
	if (head->chmod[0] == 'd')
		ft_putstr("/");
	else if (stat(head->name, &buf) == 0 && buf.st_mode & S_IXUSR)
		ft_putchar('*');
	else if (head->cmod[0] == 'l')
		ft_putchar('@');
}
