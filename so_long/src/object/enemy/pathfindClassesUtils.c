#include "../../../headers/header.h"

char	*__get_key(t_gridnode *node)
{
	char	*key;

	key = ft_itoa((long int)node);
	return (key);
}

/*
t_hashtable	*__populate_table()
{
	int		i;
	int		j;
	t_hashtable	*ht;
	t_gridnode	*node;

	i = 0;
	ht = new_hashtable(HTABLE_SIZE);
	while (grid()->grid[i])
	{
		j = 0;
		while (grid()->grid[i][j])
		{
			node = grid()->grid[i][j];
			ht->insert(grid()->key(node), node, ht);
			j++;
		}
		i++;
	}
	return (ht);
}
*/
