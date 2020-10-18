void  rev_list (list *l, list *r)
{
    node *temp = (node*)malloc(sizeof(node));
    node *r_list = (node*)malloc(sizeof(node));
    int i,pos = l->count;
    temp = l->head;
    r_list = r->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (1)
    {
        append (r,temp->data);
        temp = temp->prev;
        if (r->count == l->count)break;
    }
    //*l = *r;

}
