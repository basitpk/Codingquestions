'''
   Problem Statement:
   Delete Nth node from  end in linked list

   ------- Example ------------
   Input: head = [1,2,3,4,5], n = 2
   Output: [1,2,3,5]

'''



class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        i = 0
        prev = head
        temp = head
        
        while(temp != None):
            # prev = head
            temp = temp.next
            i+=1
        k = 0
        temp = head
        # print(str(i-n+1))
        if (i == n):
            y=temp.next
            del temp
            return y
        while(k < (i-n)):
            prev=temp
            temp =temp.next
            k+=1
        prev.next = temp.next
        del temp
        # print(temp)        
        return head