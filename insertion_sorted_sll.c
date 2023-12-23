// This C program demonstrates how to insert an element into a singly linked list using the insertion sort algorithm. The program allows the user to create a linked list by entering elements, and then prompts the user to enter an element to be inserted into the sorted linked list. The program then displays the linked list after the insertion.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int age;
    struct node *next;
};
struct node *createendsll()
{
    int item;
    struct node *p, *start = NULL, *last;
    printf("Enter the elements(to stop enter -999)\n");
    scanf("%d", &item);
    while (item != -999)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->age = item;
        if (start == NULL)
        {
            p->next = NULL;
            start = p;
            last = p;
        }
        else
        {
            last->next = p;
            p->next = NULL;
            last = p;
        }
        scanf("%d", &item);
    }
    return start;
}
struct node *insertsortsll(struct node *start, int elem)
{
    struct node *new, *temp, *follow;
    new = (struct node *)malloc(sizeof(struct node));
    new->age = elem;
    if (start == NULL)
    {
        new->next = NULL;
        start = new;
    }
    else if (elem < start->age)
    {
        new->next = start;
        start = new;
    }
    else
    {
        temp = start;
        while (temp != NULL && temp->age < elem)
        {
            follow = temp;
            temp = temp->next;
        }
        follow->next = new;
        new->next = temp;
    }
    return start;
}
void displaysll(struct node *start)
{
    struct node *temp;
    if (start == NULL)
        printf("The linked list is empty\n");
    else
    {
        temp = start;
        while (temp != NULL)
        {
            printf("\n%d\n", temp->age);
            temp = temp->next;
        }
    }
}
int main()
{
    struct node *start = NULL;
    int elem;

    start = createendsll();
    printf("The address of the linked list is %p\n", (void *)start);

    printf("Enter the element to be inserted in the linked list\n");
    scanf("%d", &elem);

    start = insertsortsll(start, elem);
    printf("The address of the linked list after insertion is %p\n", (void *)start);

    printf("The linked list is: ");
    displaysll(start);

    return 0;
}