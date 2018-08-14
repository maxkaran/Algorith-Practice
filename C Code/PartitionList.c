#include <stdio.h>
#include <stdlib.h>

 //Definition for singly-linked list.
 struct ListNode {
    int val;
    struct ListNode *next;
 };
 
struct ListNode* partition(struct ListNode* head, int x) {
    if(head == NULL || head -> next == NULL){
        return head;
    }
    
    struct ListNode* dummyHead, *ptr, *prev, *insertAfter;
    
    dummyHead = malloc(sizeof(struct ListNode));
    dummyHead -> next = head;
    prev = dummyHead;
    ptr = prev -> next; //ptr will point to node before the node being checked
    insertAfter = prev;
    
    while (ptr != NULL && ptr->val < x) //iterate through all nodes that do not need rearranging
	{
		insertAfter = ptr;
		prev = ptr;
		ptr = ptr->next;
	}
    
    while(ptr != NULL){ //first node that is out of place has been hit now
        if(ptr -> val < x){ //place before the partition
            prev -> next = ptr -> next;
            ptr -> next = insertAfter -> next;
            insertAfter -> next = ptr;
                        
            ptr = prev -> next;
            insertAfter = insertAfter -> next;
        }else{ //node belongs in current position, move on to next
            prev = ptr;
            ptr = ptr -> next;
        }
    }
    
    ptr = dummyHead -> next;
    free(dummyHead); //prevent mem leak
    return ptr;
}