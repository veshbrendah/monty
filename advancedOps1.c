#include "monty.h"

/**
 * pchar - prints the int at the top of the stack as char
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}
	if (isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the contents of a stack_t stack as a string
 * @stack: stack given by main
 * @line_cnt: line counter for error messages
 *
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar((char) current->n);
		current = current->next;
	}
	putchar('\n');
}

/**
* rotl - rotates the first element of the stack
* @stack: stack head
* @line_count: line count
*
* Return: void
*/
void rotl(stack_t **stack, unsigned int line_count)
{
	stack_t *left;
	stack_t *right;

	(void) line_count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	left = right = *stack;

	while (right->next) /* move the right pointer to the last node */
		right = right->next;
	right->next = left; /* a circle infinite linked list loop */
	left->prev = right;
	*stack = left->next; /* so we cut the link between the 0 and 1 element */
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
* rotr - rotates the last node of a stack_t stack
* @stack: stack head
* @line_count: line count
*
* Return: void
*/
void rotr(stack_t **stack, unsigned int line_count)
{
	stack_t *bottom;
	stack_t *prev;

	(void) line_count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	bottom = *stack;

	while (bottom->next)
		bottom = bottom->next;

	prev = bottom->prev;
	bottom->next = *stack;
	bottom->prev = NULL;
	prev->next = NULL;
	(*stack)->prev = bottom;
	*stack = bottom;
}

