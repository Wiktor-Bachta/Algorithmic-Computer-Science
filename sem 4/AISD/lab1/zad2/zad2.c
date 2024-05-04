#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

typedef struct OneWayCyclicList
{
    node *nodePointer;
    int numElements;
} OneWayCyclicList;

void insert(OneWayCyclicList *l, int value);
void printList(OneWayCyclicList l);
void freeList(OneWayCyclicList l);
void merge(OneWayCyclicList *l1, OneWayCyclicList *l2);
int numComparisons(OneWayCyclicList l, int a);
float avgCost(OneWayCyclicList l, int A[], int n);

int main(void)
{
    // part 1
    OneWayCyclicList l1;
    OneWayCyclicList l2;
    l1.nodePointer = NULL;
    l1.numElements = 0;
    l2.nodePointer = NULL;
    l2.numElements = 0;
    for (int i = 10; i < 20; i++)
    {
        insert(&l1, 2 * i);
        insert(&l2, 2 * i + 1);
    }
    printf("Lista pierwsza:\n");
    printList(l1);
    printf("Lista druga:\n");
    printList(l2);
    merge(&l1, &l2);
    printf("Zmergowane listy:\n");
    printList(l1);

    freeList(l1);

    // part 2
    OneWayCyclicList l;
    l.nodePointer = NULL;
    l.numElements = 0;
    int T[10000];
    int I[1000];
    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
    {
        T[i] = rand() % (100001);
        insert(&l, T[i]);
    }
    for (int i = 0; i < 1000; i++)
    {
        I[i] = rand() % (100001);
    }
    printf("Średni koszt wyszukania z tablicy T: %f\n", avgCost(l, T, 10000));
    printf("Średni koszt wyszukania losowej liczby: %f\n", avgCost(l, I, 1000));

    freeList(l);
    
    return 0;
}

void insert(OneWayCyclicList *l, int value)
{
    node *new = malloc(sizeof(node));
    new->value = value;
    if (l->numElements == 0)
    {
        l->nodePointer = new;
        new->next = new;
    }
    else
    {
        node *lastNode = l->nodePointer;
        for (int i = 0; i < l->numElements - 1; i++)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = new;
        new->next = l->nodePointer;
    }
    l->numElements += 1;
    return;
}

void freeList(OneWayCyclicList l)
{
    node *n = l.nodePointer;
    node *tmp;
    for (int i = 0; i < l.numElements; i++)
    {
        tmp = n->next;
        free(n);
        n = tmp;
    }
    return;
}

void printList(OneWayCyclicList l)
{
    node *n = l.nodePointer;
    for (int i = 0; i < l.numElements; i++)
    {
        printf("%d ", n->value);
        n = n->next;
    }
    printf("\n");
    return;
}

void merge(OneWayCyclicList *l1, OneWayCyclicList *l2)
{
    node *l1Last = l1->nodePointer;
    node *l2Last = l2->nodePointer;
    for (int i = 0; i < l1->numElements - 1; i++)
    {
        l1Last = l1Last->next;
    }
    for (int i = 0; i < l2->numElements - 1; i++)
    {
        l2Last = l2Last->next;
    }
    l1Last->next = l2->nodePointer;
    l2Last->next = l1->nodePointer;
    l1->numElements += l2->numElements;
    l2->numElements = 0;
    l2->nodePointer = NULL;
    return;
}

int numComparisons(OneWayCyclicList l, int a)
{
    int counter = 0;
    node *n = l.nodePointer;
    for (int i = 0; i < l.numElements; i++)
    {
        counter += 1;
        if (n->value == a)
        {
            return counter;
        }
        n = n->next;
    }
    return counter;
}

float avgCost(OneWayCyclicList l, int A[], int n)
{
    int totalCost = 0;
    for (int i = 0; i < 1000; i++)
    {
        totalCost += numComparisons(l, A[rand() % n]);
    }
    return (float)totalCost / 1000;
}