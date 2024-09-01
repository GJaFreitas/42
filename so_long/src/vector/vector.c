#include "../../headers/header.h"

void	__vec_rm_index(int index);
t_element	*__vec_add(void *value);
t_element	*__vec_set_value_index(int index, void *value);
void	*__vec_get_val(int index);
void	__vec_destructor(void);
void	__vec_rm_rf(void);
void	__vec_rm_val(void *value);
void	__vec_rm_first();
void	__vec_exec_on_each(void (*fun)(t_element *e, void *v), void *v);
void	__vec_exec_on_index(void (*fun)(t_element *e, void *v), void *v, int index);
void	__remove_this(t_element *e);

void	*new_vector(void)
{
	t_vector	*v;

	v = malloc_safe(sizeof(t_vector));
	v->size = 0;
	v->begin = NULL;
	v->end = NULL;
	v->next = NULL;
	v->add = __vec_add;
	v->set_at_index = __vec_set_value_index;
	v->get = __vec_get_val;
	v->destroy = __vec_destructor;
	v->for_each = __vec_exec_on_each;
	v->for_index = __vec_exec_on_index;
	v->remove_first = __vec_rm_first;
	v->remove_all = __vec_rm_rf;
	v->remove_index = __vec_rm_index;
	v->remove_value = __vec_rm_val;
	v->remove_this = __remove_this;
	vector(v);
	return (v);
}
