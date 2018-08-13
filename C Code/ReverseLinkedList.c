//Problem is from LeetCode: https://leetcode.com/problems/reverse-linked-list-ii/description/

#include <stdio.h>
#include <stdlib.h>

//Definition for singly-linked list.
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;
 
struct ListNode* reverseBetween(ListNode* head, int m, int n) {
    
    if(m == n){
        return head;
    }

    if(head == NULL){
        return NULL;
    }
    
    struct ListNode *ptr, *next, *reversedListHead, *reversedListPtr, *startNode, *toDelete, *dummy;

    dummy = malloc(sizeof(struct ListNode)); //dummy pointer that will point to head (helps handle some edgecases)
    dummy -> next = head;
    ptr = dummy; //ptr will iterate through the list

    int i=0;
    for(;i<m-1;i++){
        ptr = ptr -> next; //get to start of where list reverse begins
    }
    
    
    startNode = ptr; //will save the node before the reversed sequence so it can be reattached at the end
    ptr=ptr->next;

    reversedListHead = malloc(sizeof(struct ListNode)); //this will be the end of the new linked list segment
    reversedListHead -> val = ptr -> val;

    reversedListPtr = reversedListHead; //this will iterate through to the start of the new segment

    for(;i<n-1;i++){

        next = reversedListPtr; //save this node as it will actually become the next

        reversedListPtr = malloc(sizeof(struct ListNode));

        reversedListPtr -> val = ptr -> val;
        reversedListPtr -> next = next;       
    }

    ptr = ptr -> next; //move along one more so that the new linked lists end can be attached to the remaining numbers   

    //link new linked list into the old one
    startNode -> next = reversedListPtr;
    reversedListHead -> next = ptr;

    return dummy -> next; //return start of original list, which has now been changed
    
}

int main(void){
    ListNode *head = malloc(sizeof(ListNode));
    
    ListNode *ptr = head;
    ptr -> val = 1;

    for(int i = 2; i<6; i++){
        ptr -> next = malloc(sizeof(ListNode));
        ptr -> next -> val = i;

        ptr = ptr->next;
    }

    ptr -> next = NULL; //set end of linked list to NULL

    ptr = head; //reset ptr to print out the linked list

    while(ptr != NULL){
        printf("%i ", ptr->val);
        ptr = ptr -> next;
        if(ptr != NULL){
            printf("-> ");
        }
    }
 
    ListNode *reversed = reverseBetween(head, 2, 4); //test method on linked list of 1->2->3->4->5

    printf("\n");

    while(reversed != NULL){
        printf("%i ", reversed->val);
        reversed = reversed -> next;
        if(reversed != NULL){
            printf("-> ");
        }
    }


}