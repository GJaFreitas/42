#include "ft_printf.h"

// The only reason i need this extra function is because of the stupid constraint of 25 line per function,
// if it wasnt for that my printf would be so much more sophisticated
// id love to do the bonus and all the parsing of strings that comes with it but its
// simply to much work and patience necessary to do it in 25 lines per function
// i hate having 1 function being split between 2 or even more functions and using extra memory and
// processing time simply because the function will be more than 25 lines
// also this disgusting syntax we are pretty much forced to use "*(input++)" and other such things
// so that it ocuppies less lines, i understand that sometimes it makes code better
// but forcing its use in this way is not how it should be done imo, as much as ive become a better
// coder because of it its too frustrating sometimes. I'd love to have a solution for this but
// honestly i have no idea how to teach the principles these constraints do without them
// i just hope the next projects dont have norminette anymore, its a good learning tool
// but at this point its already become a complete nuisance

// If ft_printdata sucessfully prints something (meaning the specifier was correct eg: "%c") then it goes on as normal
// else it writes the '%' and then moves on, making it so that if you write a wrong specifier 
// eg: "%r", the output will be "%"
int    ft_ugh(char *input, va_list args, int *count)
{
        if (*input == '%')
        {
            if(!ft_printdata(count, *(input + 1), args))
            {
                *count += 1;
                write(1, "%", 1);
            }
            return (1);
        }
        else
        {
            *count += 1;
            write(1, input, 1);
            return (0);
        }
}

int ft_printf(char *input, ...)
{
    int     count;
    va_list args;

    va_start(args, input);
    count = 0;
    while (*input)
    {
        if (ft_ugh(input, args, &count))
            input++;
        input++;
    }
    va_end(args);
    return (count);
}
