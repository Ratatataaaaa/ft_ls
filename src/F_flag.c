#include "../includes/FT_LS.h"

void	F_print(t_dir *head)
{
	struct stat buf;
	if (head->chmod[0] == 'd')
		ft_putchar('/');
	else if ((int)head->chmod & S_IXUSR)
		ft_putchar('*');
	else if (head->chmod[0] == 'l')
		ft_putchar('@');
}
