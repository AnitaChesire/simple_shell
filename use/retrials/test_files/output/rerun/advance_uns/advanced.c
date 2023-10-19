#include "main.h"
/**
 *exit_func - invoked by user through writing exit
 *@unix - struct pointer
 *Return: non zero number
 */

int exit_func(my_shell *unix)
{
	int betty;
	if (unix->argv[1])
	{
		betty = error_detect(unix->argv[1]);
		if(betty == -1)
		{
			unix->status = 2;
			fprinterr(unix, "error found: ");
			_writeerr(unix->argv[1]);
			_putchar('\n');
			return (1);
		}
		unix->err_no = _err_no(info->argv[1]);
		return (-2);
	}
	unix->_err_no = -1;
	return (-2);
}

