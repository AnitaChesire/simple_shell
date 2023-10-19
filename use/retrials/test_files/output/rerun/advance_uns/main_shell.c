#include "main.h"
/**
 *
 *
 *
 */
int hsh(my_shell *unic_info, char **av)
{
	ssize_t command = 0;
	int bt_sys = 0;/*deals with built in */
	
	while (command != -1 && bt_sys != -2)
	{
		clear_info(info);/*still not implemented*/
		if (shell_interactive(info))
		{
			_putchar("$ ");/*still not implemented*/
		}
		command = user_input(info);
		if (command != -1)
		{
			set_info(info, av); /*still not set*/
			bt_sys = find_builtin(info);/*still not implemented*/
			if (bt_sys == -1)
			{
				find_cmd(info);/*still not implemented*/
			}
		}

		else if (shell_interactive(info))
		{
			_putchar('\n');
		}
		free_info(info, 0); /*still not implemented*/

	}
	write_histo(info); /*still not implemented*/
	free_info(info, 1);/*still not implemented*/
	if (!shell_interactive(info) && info->status)/*still not implemenyed*/
	{
		exit(info->status);
	}
	else if (bt_sys == -2)
	{
		if (info->err_num == -1)
		{
			exit(info->status);
		}
		exit(info->err_num);
	}
	return (bt_sys);
}


