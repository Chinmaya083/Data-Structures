#include<stdio.h>
#include<stdlib.h>

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

list *create_list ()
{
    list *l = (list*)malloc(sizeof(list));
    l->head = NULL;
    l->count = 0;
    return l;
}

/*void swap (node *a, node *b)
{
    node *temp;
    temp = a;
    a = b;
    b = temp;

}*/

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


void insert_beg (list *l, int data)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if (l->head == NULL)
    {
        l->head = temp;
    }
    else
    {
        temp->next = l->head;
        l->head = temp;
    }
    l->count++;

}

void append (list *l, int data)
{
    node *temp = (node*)malloc(sizeof(node));
    node *p = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if (l->head == NULL)
    {
       l->head = temp;
    }
    else
    {
        p = l->head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }l->count++;
}

void reverse_list (list *l, list *rev_list)
{
    node *p = (node*)malloc(sizeof(node));
    int pos,i;
    pos = l->count;
    //printf ("ATTRIBUTES: %d ",pos);
    while (1)
    {
        for (i=0,p=l->head; p->next != NULL && i<pos-1 ; i++,p = p->next);
        append (rev_list, p->data);
        pos -= 1;
        if (l->count == rev_list->count)break;
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
        temp = p;
        l->head = l->head->next;
       free (temp);
    }
    else{
    for (i = 0, p = l->head; i< pos - 2; p = p->next,i++);
    temp = p->next;
    p->next = p->next->next;
    free (temp);}

l->count --;
}

void display (list *l)
{
    node *temp = (node*)malloc(sizeof(node));
    temp = l->head;
    if(temp == NULL)
    {
        printf("\nLIST EMPTY");
        getch();
        return;
    }
    while (temp != NULL)
    {
        printf ("%d ",temp->data);
        temp = temp->next;
    }
}

void delete_list (list *l)
{
    node *p = (node*)malloc(sizeof(node));
    p = l->head;
    free (p);
    l->head = NULL;
}

void main ()
{
    list *l = create_list();
    append (l,1);append (l,4);append (l,3);
    append (l,2);append (l,9);append (l,5);
    insert_beg(l, 18);
    insert_n(l,100,3);
    //delete_list(l);
    display (l);printf ("\n");
}
