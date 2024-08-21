#include "push_swap.h"

// Basic algo goes something like:
// →Push elements from stack A to stack B while elements from B are smaller than A
// →If elements in B are unordered then switch them
// →If B has more than 2 elements then removing from B and switching in B until the smaller element comes first is necessary
// (I believe this is the biggest problem in the algorithm)

void    ft_logic(Stack *a, Stack *b)
{
    while (b->top == 0 || a->arr[a->top] > b->arr[b->top])
    {
        if (a->arr[a->top] > a->arr[a->top - 1])
        {
            if (b->arr[b->top] < b->arr[b->top - 1])
                ft_double_swap(a, b);
            else
                ft_swap_top(a);
        }
        ft_push(a, b);
        while (b->top > 1 && b->arr[b->top] < b->arr[b->top - 1])
        {
            ft_swap_top(b);
            if (b->arr[b->top] < b->arr[b->top - 1])
                ft_push(b, a);
        }
    }
}
