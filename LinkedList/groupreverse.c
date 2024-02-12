1->2->2->4->5->6->7->8
i = 0;
prev_curr= NULL;
temp = head;
while(temp != NULL)
{
    // prev_curr
    Node *current = temp, *nex, *prev;
    i =0;
    prev_curr = temp;
    while(current != NULL and i <4)
    {
        prev =current;
        nex = current->next;
        if(i ==  k-1)
        {
        //  prev_curr= current;
         nex_curr=current->next;
        }
        current->next =prev;
        current = nex;
        i++
    }
    prev_curr->next = temp; 
    temp = nex_curr;

}