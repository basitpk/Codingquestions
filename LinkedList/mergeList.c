/*
Problem Statement :-

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.


--------- Examples -----------

Input : list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

*/


//  Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    struct ListNode *result = NULL;
    if(list1 == NULL)
        return list2;
    else if (list2 == NULL)
        return list1;
    if(list1->val <= list2->val)
    {
        result = list1;
        result->next = mergeTwoLists(list1->next, list2);
    }
    else {
        result = list2;
        result->next = mergeTwoLists(list2->next, list1);
    }
    return result;
}

