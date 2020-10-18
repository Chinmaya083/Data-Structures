#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct list
{
    int count;
    node *head;
}list;

list *create_list()
{
    list *l = (list*)malloc(sizeof(list));
    l->count = 0;
    l->head = NULL;
    return l;
}

void insert_beg (list *l, int data)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if (l->head == NULL)
    {
        l->head = temp;
        temp->next = l->head;
    }
    else
    {
        if (l->count == 1)
        {
            node *p = (node*)malloc(sizeof(node));
            temp->next = l->head;
            l->head = temp;
            temp->next->next = l->head;

        }
        else
        {
            node *p = (node*)malloc(sizeof(node));
            p = l->head;
            while (p->next != l->head )
            {
                p = p->next;
            }
            //p->next = temp;
            temp->next = l->head;
            l->head = temp;
            p->next = l->head;

        }
    }


    l->count++;
}

void append (list *l, int data)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if (l->head == NULL)
    {
        l->head = temp;
        temp->next = l->head;
    }
    else
    {
        node *p = (node*)malloc(sizeof(node));
        p = l->head;
        while (p->next != l->head)
        {
            p = p->next;
        }
        p->next = temp;
        temp->next = l->head;
    }
    l->count ++;
}

void insert_n (list *l, int data, int pos)
{

    int i;
    if (pos == (l->count + 1))
    {
        append (l,data);
    }
    else if (pos == 1)
    {
        insert_beg(l,data);
    }
    else if (pos < l->count)
    {
        node *temp = (node*)malloc(sizeof(node));
        node *p = (node*)malloc(sizeof(node));
        temp->data = data;
        temp->next = NULL;
        for (i = 0, p = l->head; i< pos - 2; p = p->next,i++);
        temp->next = p->next;
        p->next = temp;
        l->count++;

    }

}


void display (list *l)
{
    //node *temp = (node*)malloc(sizeof(node));
    node *temp = l->head;
    do{
        printf ("%d ",temp->data);
        temp = temp->next;
    }while(temp != l->head);
    node *p = l->head;
    while (p->next != l->head)
    {
        p = p->next;
    }
    printf ("\nFirst Member (linked from last):");
    printf (" %d",p->next->data);
}

void delete_n (list *l, int pos)
{
    node *temp = (node*)malloc(sizeof(temp));
    temp = l->head;
    if (pos == 1)
    {
        node *p = (node*)malloc(sizeof(temp));
        p = l->head;
        while (p->next != l->head)
        {
          p = p->next;
        }
        p->next = NULL;
        free (p->next);

        l->head = temp->next;
        p->next = l->head;



    }
    else if (pos == l->count)
    {
        int i;
        for (i=0;i<pos-2;temp = temp->next,i++);
        free(temp->next);
        temp->next = NULL;
        temp->next = l->head;
    }
    else
    {
        int i;
        node *p = (node*)malloc(sizeof(node));
        for (i=0;i<pos-2;temp = temp->next,i++);
        p = temp->next->next;
        free(temp->next);
        temp->next = NULL;
        temp->next = p;
    }
    l->count --;
}

void main ()
{
    list *l = create_list();
    append (l,5);
    display (l);printf ("\n");
    insert_beg (l,45);display (l);printf ("\n");
    append (l,4);
    display (l);printf ("\n");
}

