#include <stdio.h>
#include <stdlib.h>

void    sa(t_stack_node **stackA)
{
    if (*stackA != NULL && (*stackA)->next != NULL)
    {
        int temp;

        temp = (*stackA)->value;
        (*stackA)->value = (*stackA)->next->value;
        (*stackA)->next->value = temp;
    }
}

void    sb(t_stack_node **stackB)
{
    if (*stackB != NULL && (*stackB)->next != NULL)
    {
        int temp;

        temp = (*stackB)->value;
        (*stackB)->value = (*stackB)->next->value;
        (*stackB)->next->value = temp;
    }
}

void    ss(t_stack_node **stackA, t_stack_node **stackB)
{
    sa(stackA);
    sb(stackB);
}

int	ps_atoi(const char *str)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

typedef struct stack_node
{
    int value;
    struct stack_node *next;
} t_stack_node;

t_stack_node    *read_values_and_push_onto_stack_A(int argc, char *argv[])
{
    t_stack_node    *stackA = NULL;
    int i;

    i = argc - 1;
    while (i >= 1)
    {
        int value = ps_atoi(argv[i]);

        t_stack_node    *new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
        if (new_node == NULL)
        {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        new_node->value = value;
        new_node->next = stackA;
        stackA = new_node;
        i--;
    }
    return(stackA);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf ("Usage: %s <value1> <value2> ... <valueN>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    t_stack_node    *stackA = read_values_and_push_onto_stack_A(argc, argv);
    t_stack_node    *stackB = NULL;
    printf("Stack A elements: ");
    t_stack_node *currentA = stackA;
    while (currentA != NULL)
    {
        printf("%d ", currentA->value);
        currentA = currentA->next;
    }
    printf("\n");
    while (stackA != NULL)
    {
        t_stack_node *temp = stackA;
        stackA = stackA->next;
        free(temp);
    }
    return(0);
}
