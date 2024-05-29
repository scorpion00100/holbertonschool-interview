#include "lists.h"

/**
 * check_palindrome - checks if a singly linked list is a palindrome
 * @left: double pointer to head of the list
 * @right: pointer to the tail of the list
 *
 * Return: 0 if it's not a palindrome, 1 otherwise
 */
int check_palindrome(listint_t **left, listint_t *right)
{
    int palindrome;

    if (right == NULL)
        return (1);
    palindrome = check_palindrome(left, right->next);

    if (palindrome == 0 || (*left)->n != right->n)
        return (0);
    (*left) = (*left)->next;

    return (palindrome);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of the list
 *
 * Return: 0 if it's not a palindrome, 1 otherwise
 */
int is_palindrome(listint_t **head)
{
    return (check_palindrome(head, *head));
}
