#include <stdlib.h>

typedef struct      s_file
{
    char            *name;
    char            *path;
    int             type;
    char            *date;
    char            *username;
    char            *groupname;
    char            *chmod;
    char            *size;
    char            *numlink;
    long long int   blocks;
    long long int   last_modif;
    long long int   last_access;
    struct s_file    *next;
}                   t_file;



void	*ls_free_list(t_file *List_to_free)
{
	t_file	*list_copy;
	t_list	*scd_list_copy;

	if (!List_to_free)
		return (NULL);
	list_copy = List_to_free;
	while (list_copy->next)
	{
		scd_list_copy = list_copy->next;
		free(list_copy->name);
		free(list_copy->path);
		list_copy->type = -1;
		free(list_copy->date);
		free(list_copy->username);
		free(list_copy->groupname);
		free(list_copy->chmod);
		free(list_copy->size);
		free(list_copy->numlink);
		list_copy->blocks = -1;
		list_copy->last_modif = -1;
		list_copy->last_access = -1;
		free(list_copy);
		list_copy = scd_list_copy;
	}
}

int		main(int argc, char** argv)
{
	int			i;

}
