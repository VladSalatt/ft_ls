/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 11:47:25 by ebulwer           #+#    #+#             */
/*   Updated: 2020/08/07 13:12:37 by ebulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void _ls(const char *dir, int op_a, int op_l)
{
        struct dirent *d;
        DIR *dh = opendir(dir);
        if(!dh)
        {
			if (errno == ENOENT)
				perror("directory does not exist");
			else
            	perror("unable to read directory");
            exit(EXIT_FAILURE);
        }
        while((d = readdir(dh)) != NULL)
        {
            if(!op_a && d->d_name[0] == '.') continue;
            printf("%s ", d->d_name);
			if(op_l)
				printf("\n");
        }
        if(!op_l)
			printf("\n");
}

int main(int ac, char *av[])
{
	if(ac == 1)
		_ls(".", 0, 0);
	else if(ac == 2)
	{
		if(av[1][0] == '-')
		{
			int op_a = 0;
			int op_l = 0;
			char *p = (char *)(av[1]+1);
			while(*p)
			{
				if(*p == 'a')
					op_a = 1;
				else if(*p == 'l')
					op_l = 1;
				else
				{
					perror("unknown option error");
					exit(EXIT_FAILURE);
				}
				p++;
			}
			_ls(".", op_a, op_l);
		}
		else
			_ls(av[1], 0, 0);
	}
		else if(ac == 3)
		{
			if(av[1][0] != '-')
			{
				perror("incorrect usage error");
				exit(EXIT_FAILURE);
			}
		
			int op_a = 0;
        	int op_l = 0;
        	char *p = (char *)(av[1]+1);
        	while(*p)
			{
				if(*p == 'a')
					op_a = 1;
				else if(*p == 'l')
                	op_l = 1;
            	else
            	{
                	perror("unknown option error");
                	exit(EXIT_FAILURE);
            	}
            	p++;
            }
            	_ls(av[2], op_a, op_l);
		}
		return 0;
}
