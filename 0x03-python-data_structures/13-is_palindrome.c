#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * reverse_listint - Reverses a linked list in place
 * @head: Pointer to the head of the list
 * Return: Pointer to the new head of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *prev = NULL, *current = *head, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    return *head;
}

/**
 * is_palindrome - Identifies if a singly linked list is a palindrome
 * @head: Pointer to the head of the list
 * Return: 1 if it is palindrome else 0
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head, *prev_slow = *head;
    
    if (*head == NULL || (*head)->next == NULL)
        return 1;

    // Move fast to the end and slow to the middle
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    // Reverse the second half of the list
    prev_slow->next = reverse_listint(&slow);

    // Compare the reversed second half with the first half
    while (slow != NULL)
    {
        if ((*head)->n != slow->n)
            return 0;
        *head = (*head)->next;
        slow = slow->next;
    }

    return 1;
}
