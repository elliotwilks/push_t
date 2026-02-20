#include<stdio.h>
#include<stdlib.h>

typedef struct s_node
{
	int	value;
	int	index;
	struct s_node *next;
} node;

void	create_node(node **stack, int value)
{
	node	*n = malloc(sizeof(node));
	n->value = value;

	// new node points to the old head
	n->next = *stack;

	// Set the stack to the new node
	*stack = n;
}

void	print_node(node **stack)
{
	node	*temp;

	temp = *stack;
	while (temp != NULL)
	{
		printf("Value: %d Index: %d\n", temp->value, temp->index);
		temp = temp->next;
	}
}

int	node_count(node **stack)
{
	int	count;
	node	*temp;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

void	assign_index(node **stack)
{
	int	i;
	int	index;
	node	*current;
	node	*compare;

	i = 0;
	index = 0;
	current = *stack;
	while (current != NULL)
	{
		index = 0;
		compare = *stack;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
			i++;
		}
		current->index = index;
		current = current->next;
	}
}

// Function to perform bubble sort on the linked list
void	ll_bubble_sort(node *stack) 
{
        node	*traverse;
	node	*prev;
	node	*ptr;
	int	len;
	int	i;
	int	swapped;

	len = stack_len(stack);
	i = 0;

	// Iterating over the whole linked list
	while (i < len)
	{
		traverse = stack;
        	prev = stack;
		swapped = 0;

        	while (traverse->next != NULL) 
		{
			// Temporary pointer to store next node
			*ptr = traverse->next;
			if (traverse->data > ptr->data)
				swapped = 1;
		
			if (traverse == head)
			{
                    		// Performing swap operations and updating head 
                    		traverse->next = ptr->next;
                    		ptr->next = traverse;
                    		prevNode = ptr;
                    		head = prevNode;
                	}
                	else
			{
                    		// Performing swap operation
                    		traverse->next = ptr->next;
                    		ptr->next = traverse;
                    		prevNode->next = ptr;
                    		prevNode = ptr;
                	}
			continue;
		}
		prev = traverse;
		traverse = traverse->next;
        }
	if (swapped == 1)
            break;
	++i;
}

int	main(int argc, char **argv)
{
	int	i;
	node	**stack_a;
	node	*head_a;
	stack_a = &head_a;

	head_a = NULL;

	i = 1;
	while (i < argc)
	{
		create_node(stack_a, atoi(argv[i]));
		i++;
	}

	print_node(stack_a);
	
	assign_index(stack_a);
	printf("\n");	
	print_node(stack_a);

	bubble_sort(stack_a);
	printf("\n");	
	print_node(stack_a);

	return (0);
}

