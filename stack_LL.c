#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node* next;
    int data;
}node;

typedef struct list
{
    node *head;
    int size;
}list;

list *create_stack ()
{
    list* l = (list*)malloc(sizeof(list));
    l->head = NULL;
    l->size = 0;
    return l;
}


void push (list *l,int data)
{
    node *temp =(node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if(l->head == NULL)
    {
        l->head = temp;
    }
    else
    {
       node *p = l->head;
       while(p->next)
       {
           p = p->next;
       }
       p->next = temp;

    }
    ++l->size;
}

void pop (list *l)
{
    node *temp = l->head;
    if (l->size == 1)
    {
        l->head = NULL;
        --l->size;
    }
    else if(l->size == 0)
    {
        printf("\nStack is empty.\n");
        return;
    }
    else
    {
    int i = 0;
    while (i < (l->size - 2))
    {
        temp = temp->next;
        ++i;
    }
    free(temp->next);
    temp->next = NULL;
    //temp->top = NULL;
    printf("\nTOPMOST ELEMENT POPPED\n");
    --l->size;
    }

}

void peek (list* l)
{
  node *temp = l->head;
  int i = 0;
  if (temp == NULL)
  {
      printf ("\nStack is empty.");
  }
  else
  {
  while (temp->next)
  {
      temp = temp->next;
      ++i;
  }
  printf ("\nTop most element is:%d",temp->data);
  }
}

void main ()
{
    list *s = create_stack();
    push (s,10);push (s,9);push (s,8);push (s,7);push (s,6);push (s,5);
    printf("%d",s->size);
    peek(s);
    pop(s);
    peek(s);
    pop(s);
    peek(s);
    pop(s);
    peek(s);
    pop(s);
    peek(s);
    pop(s);
    peek(s);
    pop(s);
    pop(s);
    peek(s);

}
