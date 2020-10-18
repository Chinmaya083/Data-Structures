#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}node;

typedef struct list
{
    int count;
    node *head;
}list;

list *create_list ()
{
    list *l = (list*)malloc(sizeof(list));
    l->head = NULL;
    l->count = 0;
    return l;
}

void insert_beg (list *l, int data)
{
    node *temp = (node*)malloc(sizeof(node));
    node *p = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if (l->head == NULL)
    {
        l->head = temp;

    }
    else
    {
        p = l->head;
        temp->next = p;
        p->prev = temp;
        l->head = temp;
    }
    l->count++;

}

void append (list*l, int data)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if (l->head == NULL)
    {
        l->head = temp;

    }
    else
    {
        node *p = (node*)malloc(sizeof(node));
        p = l->head;
        while (p->next != NULL)
        {
           p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
    l->count++;
}

void insert_n (list *l, int data, int pos)
{

    int i;
    if (pos == (l->count + 1))
    {
        append (l, data);
    }
    else if (pos == 1)
    {
        insert_beg(l, data);
    }
    else if (pos < l->count)
    {
        node *temp = (node*)malloc(sizeof(node));
        node *p = (node*)malloc(sizeof(node));
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;
        for (i = 0, p = l->head; i< pos - 2; p = p->next, i++);
        temp->next = p->next;
        p->next = temp;
        temp->prev = p;
        //for (i = 0, p = l->head; i< pos; p = p->next,i++);
        temp->next->prev = temp;

        l->count++;

    }
}

void delete_n (list *l, int pos)
{
    node *p = (node*)malloc(sizeof(node));
    node *temp = (node*)malloc(sizeof(node));
    p = l->head;
    int i;
    if (pos == 1)
    {
       temp = l->head;
       l->head = l->head->next;
       free(temp);
    }
    else
    {
        for (i = 0, p = l->head; i< pos - 2; p = p->next, i++);
        {
            temp = p->next;
        }
        p->next = p->next->next;
        free (temp);}

    l->count --;
}



void delete_list (list *l)
{
    node *p = (node*)malloc(sizeof(node));
    p = l->head;
    l->head = NULL;
    l->count = 0;
    free (p);
}

void display (list *l)
{
    node *temp;
    temp = l->head;
    while (temp != NULL)
    {
        printf ("%d ",temp->data);
        temp = temp->next;
    }
}


void main ()
{
   list *l = create_list();
   //list *r = create_list();
   append (l,1);append (l,2); append (l,3); append (l,4);
   display (l);printf ("\n");
   insert_n(l,1,2);
   display (l);printf ("\n");
   insert_beg(l,70);
   display (l);printf ("\n");

}
