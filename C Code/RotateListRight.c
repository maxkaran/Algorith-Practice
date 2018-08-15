//https://leetcode.com/problems/rotate-list/description/
//Given a linked list, rotate the list to the right by k places, where k is non-negative.

#include<stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
        if(head == NULL) return head;
        
        int length=1; // number of nodes
        struct ListNode *end;
        end = head;
        
        while(end->next != NULL)  // get the number of nodes in the list
        {
            end = end->next;
            length++;
        }
        end->next = head; // circle the link

        k = k%length;
    
        for(int i=0; i<length-k; i++){ 
            end = end->next;
        } // the end node is the (len-k)-th node (1st node is head)
        

        //cut the linked list here
        head = end->next; 
        end->next = NULL;
        return head;
}