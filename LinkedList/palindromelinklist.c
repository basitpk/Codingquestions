/**
  Problem Statement

  Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

  Asked in Broadcom

**/


// Definition for singly-linked list.

#include<stdio.h>
#include<stdbool.h>
struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode *reverse(struct ListNode *head)
{
    struct ListNode *prev=NULL, *cur =head, *nex;
    while(cur != NULL)
    {
        nex = cur->next;
        cur->next =prev;
        prev=cur;
        cur=nex;
    }
    return prev;
}
bool isPalindrome(struct ListNode* head){
    struct ListNode *slow, *fast;
    if(!head)
        return true;
    slow=head;
    fast=head->next;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
     
    slow = slow->next;
    struct ListNode *s2 = reverse(slow);
    
    while(s2)
    {
       if(head->val != s2->val)
           return false;
       head = head->next;
       s2 = s2->next;
    }
    return true;
}
