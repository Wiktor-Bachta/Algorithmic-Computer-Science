#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

void insert(node **c, int value);
void printList(struct node *head);
int q_remove(node **head);
int s_remove(node **head);

int main(void)
{
    node *queue = NULL;
    node *stack = NULL;
    for (int i = 0; i < 50; i++)
    {
        insert(&queue, i);
        printf("Dodano do kolejki %d\n", i);
    }
    for (int i = 0; i < 50; i++)
    {
        printf("Usunięto z kolejki %d\n", q_remove(&queue));
    }
    for (int i = 0; i < 50; i++)
    {
        insert(&stack, i);
        printf("Dodano do stosu %d\n", i);
    }
    for (int i = 0; i < 50; i++)
    {
        printf("Usunięto ze stosu %d\n", s_remove(&stack));
    }
    return 0;
}

void insert(node **head, int value)
{
    node *new = malloc(sizeof(node));
    new->value = value;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
    }
    else
    {
        node *lastNode = *head;
        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = new;
    }
    return;
}

int q_remove(node **head)
{
    int removed;
    if (*head == NULL)
    {
        printf("Kolejka jest pusta.\n");
        return -1;
    }
    else if ((*head)->next == NULL)
    {
        removed = (*head)->value;
        free(*head);
        *head = NULL;
    }
    else
    {
        node *secondToLastNode = *head;
        while (secondToLastNode->next->next != NULL)
        {
            secondToLastNode = secondToLastNode->next;
        }
        removed = secondToLastNode->next->value;
        free(secondToLastNode->next);
        secondToLastNode->next = NULL;
    }
    return removed;
}

int s_remove(node **head)
{
    int removed;
    if (*head == NULL)
    {
        printf("Kolejka jest pusta.\n");
        return -1;
    }
    node *firstNode = *head;
    removed = firstNode->value;
    *head = ((*head)->next);
    free(firstNode);
    return removed;
}
