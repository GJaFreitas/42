#ifndef QUEUE_H
#define QUEUE_H

# include "helper_structs.h"

typedef struct s_queue t_queue;
typedef struct s_element t_element;

struct s_queue
{
	t_element	*top;

	void		*(*pop)(t_queue *queue);
	void		(*add)(void *content, t_queue *queue);
	// Destructor with an option to destroy the contents stored or not
	void		(*destroy)(t_queue *queue, int content);
};

t_queue	*new_queue(void);

#endif
