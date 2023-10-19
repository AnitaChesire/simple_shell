#include "main.h"
/**
 * 
 *
 *
 *
 */

struct unix *info;
char **get_environ(unix *info)
{
	if(!info->environ || info->env_change)
	{
		info->environ = lits_to_strings(info->env);
		info->env_change = 0;
	}
	return (info->environ);
}

void mem_free(unix *info, int bnc)
{
	free(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (bnc)
	{
		if (info->env)
		{
			free(&(info->env));
		}
		if (info->environ)
		{
			free(&(info->environ));
		}
	}
}
