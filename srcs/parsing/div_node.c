
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehebert <gehebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:16:15 by gehebert          #+#    #+#             */
/*   Updated: 2023/02/06 18:10:13 by gehebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"


static int	count_str(char *s, char *set, int count)
{
	int		q[2];
	int		i;

	i = 0;
	q[0] = 0;
	q[1] = 0;
	while (s && s[i] != '\0')
	{
		count++;
		if (!ft_strchr(set, s[i]))
		{
			while ((!ft_strchr(set, s[i]) || q[0] || q[1]) && s[i] != '\0')
			{
				q[0] = (q[0] + (!q[1] && s[i] == '\'')) % 2;
				q[1] = (q[1] + (!q[0] && s[i] == '\"')) % 2;
				i++;
			}
			if (q[0] || q[1])
				return (-1);
		}
		else
			i++;
	}
	return (count);
}

static char	**fill_str(char **aux, char *s, char *set, int i[3])
{
	int		q[2];

	q[0] = 0;
	q[1] = 0;
	while (s && s[i[0]] != '\0')
	{
		i[1] = i[0];
		if (!ft_strchr(set, s[i[0]]))
		{
			while ((!ft_strchr(set, s[i[0]]) || q[0] || q[1]) && s[i[0]])
			{
				q[0] = (q[0] + (!q[1] && s[i[0]] == '\'')) % 2;
				q[1] = (q[1] + (!q[0] && s[i[0]] == '\"')) % 2;
				i[0]++;
			}
		}
		else
			i[0]++;
		aux[i[2]++] = ft_substr(s, i[1], i[0] - i[1]);
	}
	return (aux);
}

char	**div_str(char const *s, char *set)
{
	char	**aux;
	int		nwords;
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (!s)
		return (NULL);
	nwords = count_str((char *)s, set, 0);
	if (nwords == -1)
		return (NULL);
	aux = malloc((nwords + 1) * sizeof(char *));
	if (aux == NULL)
		return (NULL);
	aux = fill_str(aux, (char *)s, set, i);
	aux[nwords] = NULL;
	return (aux);
}

  //   ls -l -t -a | head -2 | wc -c >> out.txt   
  //      
  // cat < popov.txt
  //   < popov.txt | wc -l 
  //  < popov.txt wc -l | cat > titi2.txt
  //   ls  -lta | wc -l >> out.txt   
  //   ls -lt | head -2 | wc -l >> out3.txt  
 
/*
from parse.c /split_all ->
	div_node 	=> node spliter by ending char (<,>,|)
	word_count & ft_fill_array ... no comment!
	*** return table_command : called node !
*/