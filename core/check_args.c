/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:02:52 by svanmarc          #+#    #+#             */
/*   Updated: 2023/10/20 10:39:41 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	no_double(int ac, char **av, int startindex)
{
	int	i;
	int	j;

	i = startindex;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoll(av[i]) == ft_atoll(av[j]))
			{
				ft_putstr("Error : double\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	str_entre_dans_un_int(char *str)
{
	long long int	num = ft_atoll(str);
	if (num < INT_MIN || num > INT_MAX)
	{
		ft_putstr("DEBUG : Error : str_entre_PAS dans_un_int: ");
		ft_putstr(str);
		ft_putstr("\n");
		return (0);
	}
	return (1);	
}

int	tous_les_strs_entrent_dans_int(int ac, char **av, int startindex)
{
	int	i;
	
	i = startindex;
	while (i < ac)
	{
		//SI (av[i]) ne rentrre pas dans ub)
		if (!str_entre_dans_un_int(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	nbr_only(int ac, char **av, int startindex)
{
	int	i;
	int	j;

	i = startindex;
	while (i < ac)	
	{
		j = 0;
		if (av[i][j] == '-')
			j++;
		while (av[i][j])
		{
			if ((av[i][j] >= '0' && av[i][j] <= '9')
					|| av[i][j] == ' ')
			j++;
			else 
			{
				printf("DEBUG - nbr_only : %s is not a number\n", av[i]);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	no_error_in_args(int ac, char **av, int startindex)
{
	if (nbr_only(ac, av,startindex) == 0)
	{
		printf("DEBUG - nbr_only\n");
		return (0);
	}	
	else if (tous_les_strs_entrent_dans_int(ac, av, startindex) == 0)
	{
		printf("DEBUG - tous_les_strs_NE entrent PAS _dans_int\n");
		return (0);
	}	
	else if (no_double(ac, av, startindex) == 0)
	{
		printf("DEBUG - no_double\n");
		return (0);
	}	
	else
		return (1);
}
