
void reverse_list (list *l, list *rev_list)
{
    node *p = (node*)malloc(sizeof(node));
    int pos,i;
    pos = l->count;
    //printf ("ATTRIBUTES: %d ",pos);
    while (1)
    {
        for (i=0,p=l->head; p->next != NULL && i<pos-1; i++, p = p->next);
            append (rev_list, p->data);
        pos -= 1;
        if (l->count == rev_list->count)
            break;
    }
}
