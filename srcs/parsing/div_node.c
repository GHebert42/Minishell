
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

// /*	node get-set */
int	set_etype(t_table *tab, char *etype) //, char **a[2])//, int *i) // etype (int)
{
	int type;	// int cmd;	
	
	type = 0;	// cmd = 0;
	if (ft_strcmp(etype, "<<") == 0)
		tab->node->etype = INF2_END; // # 5 	//  node = get_infile2(node, node->cmd[id], i);
	else if (ft_strcmp(etype, "<") == 0)
		tab->node->etype = INF1_END;		// node = get_infile1(node, node->cmd[id]);
	else if (ft_strcmp(etype ,">>") == 0)
		tab->node->etype = OUTF2_END;	// node = get_outfile2(node, node->cmd[id]);
	else if (ft_strcmp(etype ,">") == 0)
		tab->node->etype = OUTF1_END;  	// node = get_outfile1(node, node->cmd[id]);
	else if (ft_strcmp(etype ,"|") == 0)
		tab->node->etype = PIPE_END;		// exec_custom???
	// else //if (ft_strcmp(etype ,"@") == 0)
	// 	tab->node->etype = DEAD_END;     
	
	return (tab->node->etype);
}



// t_node	*get_node(t_table *tab, t_node *node, int id)  
	// {
	// 	t_node *new;
	// 	int nod_len;	
	// 	int i;
	// 	int oldfd;

	// 	new = init_node(tab);	
	// 	new = node;
	// 	i = -1;
	// 	new->nod_len = tab->refs[id];
	// 	new->id = id;

	// 		// pre-requis builder_node
	// 	printf("\nDEBUG::: ### SET_NEW [id:%d]  pos_end:[%d] by Refs \n", new->id, tab->refs[new->id]);
	// 	if (new->id <= tab->nods && tab->cmds[id])
	// 	{
	// 		printf("DEBUG::	 SET NEW >> infile[%d] + outfile[%d] \n", new->infile, new->outfile);
	// 		new->etype = set_etype(tab, tab->token[tab->refs[new->id]]); // - node->nod_len);
	// 		// if(new->id <= tab->nods) //if // while
	// 		// {
	// 			// node->id = id;
	// 			// new->nod_len = tab->refs[new->id];
	// 		new->cmd = ft_mx_dup(tab->cmds[id]);
	// 		printf("DEBUG::  SET_node->cmd[%d] {__%s__}:: mx_len:%d::\n", id, *new->cmd, ft_mx_len(new->cmd));
	// 					// if (node->nod_len == 0)
	// 					// 	node->nod_len = tab->refs[0] - 1;

	// 					// printf("DEBUG::  SET_node->id [%d] [nod_len:%d]\n", id, new->nod_len);
	// 						// node->etype = set_etype(tab, tab->token[node->nod_len]);				
	// 						// printf("DEBUG: TTT->cmds[%d][%d] {__%s__}::len:%d::\n\n", id, i, tab->cmds[id][i], ft_mx_len(tab->cmds[id]));
	// 				// if(++i <= new->nod_len - 1)
	// 				// {				
	// 				// }
	// 					// if (node->etype > 1)				// if (set_etype(tab, tab->token[i]) > 1)	
	// 					// {
	// 					// 	tab->node->xfile = ft_strdup(tab->token[node->nod_len + 1]);			
	// 					// 	printf("DEBUG: Get_node->xfile {%s} ref + 1\n", tab->node->xfile);
	// 					// }
	// 					// printf("DEBUG:: Get_node t->node->cmd {%s} \n", *node->cmd);
	// 					// printf("DEBUG: Get_node->etype [%d]\n", tab->node->etype);
	// 		if (new->etype >= 2 && new->etype <= 4)
	// 		{
	// 			new->xfile = ft_strdup(tab->token[tab->refs[new->id]+1]);
	// 			printf("DEBUG::: XXX SET_node->xfile {%s} \n", new->xfile);
	// 		}		
	// 		i = 0;		
	// 		if (new->etype == 2 )// || tab->node->etype == 3)
	// 			new = get_outfile1(new, tab);
	// 		else if (new->etype == 3)
	// 			new = get_outfile2(new, tab);
	// 		else if (new->etype == 4)
	// 			new = get_infile1(new, tab);
	// 		else if (new->etype == 5)
	// 			new = get_infile2(new, tab);   
	// 		else if (new->etype == 1) 
		// 		{
		// 			// id++;
					
		// 			printf("DEBUG::	 ###  SET_[infile:%d] X0X [outfile:%d] \n", new->infile, new->outfile);

		// 		}
		// 		if ((new->id) > 1)
		// 		{
		// 			oldfd = new->outfile;
		// 			new->outfile = STDOUT_FILENO;
		// 		}

		// 	}
	// 	printf("DEBUG::: ### END_SET_NEW ID:%d  t->id:%d etype[%d] ###\n", new->id, node->id, tab->node->etype);
	// 		// ls > popov.txt
		// 		// wc < toto.txt 
		// 				// tab->node->cmd[nod - 1] = NULL;	
		// 				// got to do node with tab data
		// 				// 		- node->id = 1; parce que! tab->cmds[id]...
		// 				//		- node->cmd** = {"","",""} start with cmd[0] to exec
		// 				//		-				=  follow by args (if so) cmd[1]
		// 				//		-				= cmd[eot] : eot= endofnode - aka etype
		// 				//		redir set by etype
		// 				//		-	dead_end :normal ending close fd/free/exit (1) ... aka "fit"
		// 			// if (tab->cmds[cmd][nod] && (nod < node->tkn_len) && (cmd < tab->nod_num))
		
	// 	printf("- - -\t - - -\t - - - \n");
	// 	// new->id++;	
	// 	return (new);
// }

static t_node	*get_params(t_table *tab,t_node *node, char **a, int *i)
{
	int etype;

	

	if (a[0][*i])
	{
		etype = set_etype(tab, a[0]);
		if (etype == 3)//a[0][*i] == '>' && a[0][*i + 1] && a[0][*i + 1] == '>')
			node = get_outfile2(node, tab);
		else if (etype == 2)
			node = get_outfile1(node, tab);
		else if (etype == 5)
			node = get_infile2(node, tab);
		else if (etype == 4)
			node = get_infile1(node, tab);
		else if (etype != '|')
			node->cmd = ft_mx_ext(node->cmd, a[0]);
		else
		{
			chk_error(PIPENDERR, NULL, 2);
			*i = -2;
		}
		printf("\n NEW %d len\n",ft_mx_len(node->cmd));
		return (node);
	}
	chk_error(PIPENDERR, NULL, 2);
	*i = -2;
	return (node);
}
static t_list	*stop_fill(t_list *cmdl, char **args, char **temp)
{
	ft_lstclear(&cmdl, free_cont);
	ft_mx_free(&temp);
	ft_mx_free(&args);
	return (NULL);
}

t_list	*get_node(t_table *tab, t_node *node, int i)  
{
	t_list 	*cmdl[2];
	char	**tmp;
	char	**tkn;

	t_node *new;
	int nod_len;	
	// int i;
	int oldfd;

	tkn = ft_mx_dup(tab->token);
	cmdl[0] = NULL;
	tmp = tkn;
	while(tkn[++i])
	{
		cmdl[1] = ft_lstlast(cmdl[0]);
		if( i == 0 || (tkn[i][0] == '|' && tkn[i + 1] && tkn[i + 1][0]))
		{
			i += tkn[i][0] == '|';
			ft_lstadd_back(&cmdl[0], ft_lstnew(init_node()));
			cmdl[1] = ft_lstlast(cmdl[0]);
		}
		tmp = tkn;
		cmdl[1]->content = get_params(tab, cmdl[1]->content, tmp, &i);
		if (i < 0)
			return (stop_fill(cmdl[0], tkn, tmp));
		if (!tkn[i])
			break;
	}
	ft_mx_free(&tmp);
	ft_mx_free(&tkn);
	return(cmdl[0]);
}


/*
	new = init_node(tab);	
	new = node;
	// i = -1;
	new->nod_len = tab->refs[id];
	new->id = id;

		// pre-requis builder_node
	printf("\nDEBUG::: ### SET_NEW [id:%d]  pos_end:[%d] by Refs \n", new->id, tab->refs[new->id]);
	if (new->id <= tab->nods && tab->cmds[id])
	{
		printf("DEBUG::	 SET NEW >> infile[%d] + outfile[%d] \n", new->infile, new->outfile);
		new->etype = set_etype(tab, tab->token[tab->refs[new->id]]); // - node->nod_len);
		// if(new->id <= tab->nods) //if // while
		// {
			// node->id = id;
			// new->nod_len = tab->refs[new->id];
		new->cmd = ft_mx_dup(tab->cmds[id]);
		printf("DEBUG::  SET_node->cmd[%d] {__%s__}:: mx_len:%d::\n", id, *new->cmd, ft_mx_len(new->cmd));
					// if (node->nod_len == 0)
					// 	node->nod_len = tab->refs[0] - 1;

					// printf("DEBUG::  SET_node->id [%d] [nod_len:%d]\n", id, new->nod_len);
						// node->etype = set_etype(tab, tab->token[node->nod_len]);				
						// printf("DEBUG: TTT->cmds[%d][%d] {__%s__}::len:%d::\n\n", id, i, tab->cmds[id][i], ft_mx_len(tab->cmds[id]));
				// if(++i <= new->nod_len - 1)
				// {				
				// }
					// if (node->etype > 1)				// if (set_etype(tab, tab->token[i]) > 1)	
					// {
					// 	tab->node->xfile = ft_strdup(tab->token[node->nod_len + 1]);			
					// 	printf("DEBUG: Get_node->xfile {%s} ref + 1\n", tab->node->xfile);
					// }
					// printf("DEBUG:: Get_node t->node->cmd {%s} \n", *node->cmd);
					// printf("DEBUG: Get_node->etype [%d]\n", tab->node->etype);
		if (new->etype >= 2 && new->etype <= 4)
		{
			new->xfile = ft_strdup(tab->token[tab->refs[new->id]+1]);
			printf("DEBUG::: XXX SET_node->xfile {%s} \n", new->xfile);
		}		
		i = 0;		
		if (new->etype == 2 )// || tab->node->etype == 3)
			new = get_outfile1(new, tab);
		else if (new->etype == 3)
			new = get_outfile2(new, tab);
		else if (new->etype == 4)
			new = get_infile1(new, tab);
		else if (new->etype == 5)
			new = get_infile2(new, tab);   
		else if (new->etype == 1) 
		{
			// id++;
			
			printf("DEBUG::	 ###  SET_[infile:%d] X0X [outfile:%d] \n", new->infile, new->outfile);

		}
		if ((new->id) > 1)
		{
			oldfd = new->outfile;
			new->outfile = STDOUT_FILENO;
		}

	}
	printf("DEBUG::: ### END_SET_NEW ID:%d  t->id:%d etype[%d] ###\n", new->id, node->id, tab->node->etype);
		// ls > popov.txt
		// wc < toto.txt 
				// tab->node->cmd[nod - 1] = NULL;	
				// got to do node with tab data
				// 		- node->id = 1; parce que! tab->cmds[id]...
				//		- node->cmd** = {"","",""} start with cmd[0] to exec
				//		-				=  follow by args (if so) cmd[1]
				//		-				= cmd[eot] : eot= endofnode - aka etype
				//		redir set by etype
				//		-	dead_end :normal ending close fd/free/exit (1) ... aka "fit"
			// if (tab->cmds[cmd][nod] && (nod < node->tkn_len) && (cmd < tab->nod_num))
	
	printf("- - -\t - - -\t - - - \n");
	// new->id++;	
	return (new);
}*/



// static int	node_count(char **tokens, char *set, int strt)
// {
// 	int		q[2];
// 	int		i;
// 	int		n;
// 	int		etype;	// num ref. etype if not next

// 	etype = -1;
// 	n = strt;
// 	q[0] = 0;
// 	q[1] = 0;
// 	// printf("DEBUG: node_count begin :: \tn = (%d)\n", strt);
// 	while (etype < 0 && (tokens[n]))
// 	{
// 		i = 0;
// 		while (tokens[n] && tokens[n][i] != '\0')
// 		{		
// 			if (ft_strchr(set, tokens[n][i]))
// 				return(n);
// 			if (!ft_strchr(set, tokens[n][i]))
// 			{
// 				while ((!ft_strchr(set, tokens[n][i])) && tokens[n][i] != '\0')
// 				{ 
// 						q[0] = (q[0] + (!q[1] && tokens[n][i] == '\'')) % 2;
// 						q[1] = (q[1] + (!q[0] && tokens[n][i] == '\"')) % 2; 
// 						i++;
// 				}
// 				if (q[0] || q[1])
// 					return (-1);
// 			}
// 			i++;
// 		}
// 		n++;
// 	}
// 	return (n); 
// }

// node_fill : use tab->cmds[] to stack node... former tab->token[]
static t_table *node_fill(t_table *tab, int len, int strt, char** tkn)
{	
	int i;	//token pos
	int id;
	t_node *node;
	
	node = tab->node;	
	node->nod_len = 0;
	i = 0;
	tab->node->id = 1;
	printf ("DEBUG:: start _nod_fill NODS = [ %d ]\n", tab->nods);
	// printf("DEBUG::: TEST node >> infile[%d] + outfile[%d] \n", node->infile, node->outfile);
	while (tab->node->id <= tab->nods && i < ft_mx_len(tab->token))
	{
		id = tab->node->id;
		tab->cmds[id] = NULL;//ft_mx_dup(tkn);
		node->nod_len = tab->refs[tab->node->id]; // - node->nod_len);

		if (node->nod_len == 0)// && node->etype == 1)
		{
			node->nod_len = tab->refs[0] - 1;
			printf("DEBUG: TEST:0:  node_fill nod_len[%d] i[%d] \n", node->nod_len, i);
			// break;
		}
		// printf("\nDEBUG: TEST >> id[%d] :: token->nod_len{%s} \n", id, tab->token[node->nod_len]);
		tab->node->etype = set_etype(tab, tab->token[node->nod_len]);
		printf("\nDEBUG:::	TEST >> node->id[%d] :: etype_ _%d_ _  \n", tab->node->id, node->etype);
		printf("DEBUG::	:: TEST => nod_len(%d) i=%d\n", node->nod_len, i);


		while (i < node->nod_len)
		{
			// if (i == tab->refs[node->id])
			// 	i++;
		printf("DEBUG: +++ node_fill tab->cmds[%d] token[%d] {%s} \n", node->id, i, tab->token[i]);	
			tab->cmds[id] = ft_mx_ext(tab->cmds[id], tab->token[i]);
			i++;
		}	
		if (node->etype == 1)//tab->refs[node->id])
			i++;
			// tab->node->etype = set_etype(tab, tab->token[tab->refs[tab->nums]]);
					// if (tab->node->etype == 0)
					// else if (tab->node->etype == 1)
				// if (i > ft_mx_len(tab->token))
				// 	break;		
				// else
				// printf("DEBUG: TEST >> node->id(%d) :: ->nods_(%d) _  \n", node->id, tab->nods);
		if (node->id < tab->nods)
			node->id++;
		else 
			break;
				// {
				// 	printf("DEBUG: TEST >> token_len = (%d)  _  \n", ft_mx_len(tab->token));
				// 	while (i++ < ft_mx_len(tab->token) - 1)
				// 		printf("DEBUG: node_fill _out_reject!! node->id[%d] idex[%d] token{%s} \n", id, i, tab->token[i]);
				// 		// ++i;
				// }
	}
	tab->nods = id;
	tab->node = node;
	// printf ("DEBUG:: \tEND_nod_fill NODS = [ %d ]\t _ _ _\n\n", tab->nods);
	return (tab);
}

		// ls -lt | wc -l >> ut.txt
		// ls >> gg.txt
   
t_table	 *div_node(t_table *tab, char *set) // call by parse>split_all
{
	t_node	*node;			// node sub_split by etype
	char **tkn;
	int 	i;		// pos to start

	i = 0;
	// tab->node = init_node(tab);
	node = tab->node;	
	if (node->id <= tab->nods)// start at zero < node->id start at 1
	{
		node->nod_len = tab->refs[node->id];
			// node->nod_len = node_count(tab->token, set, 0);	// how many token into this node
			// printf("DEBUG: div_ nods = %d :: tkn = %d ::\n", tab->nods, tab->refs[0]);
		// printf("DEBUG: div_ node->nod_len (%d) \n", node->nod_len);
		// printf("DEBUG: div_ tab->node->[id:%d] [ref:%d] \n", node->id, tab->refs[node->id]);
		tkn = (char **)malloc(sizeof(char *) * (tab->nods)); 
			if (!(tkn))
				return (NULL);
		tab = node_fill(tab, node->nod_len, node->nod_len, tkn);	
	}	
	printf("DEBUG: div_node:: end... \t... go for get_node \n\n");

	tab->node = node;
	tab->cmdl = get_node(tab, node, 0);
	return (tab);    
}
  //   ls -l -t -a | head -2 | wc -c >> out.txt   
  //      
  // cat < popov.txt
  //   < popov.txt | wc -l 
  //  < popov.txt wc -l | cat > titi2.txt
  //   ls  -lta | wc -l >> out.txt   
  //   ls -lt | head -2 | wc -l >> out3.txt  
//    printf("DEBUG: TEST find_command >> path{%s}  \n", path);
 
/*
from parse.c /split_all ->
	div_node 	=> node spliter by ending char (<,>,|)
	word_count & ft_fill_array ... no comment!
	*** return table_command : called node !
*/