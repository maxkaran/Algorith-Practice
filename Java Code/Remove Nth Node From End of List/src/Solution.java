// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
// Given a linked list, remove the n-th node from the end of list and return its head.



 /*Definition for singly-linked list.
 public class ListNode {
     int val;
     ListNode next;
     ListNode(int x) { val = x; }
 }
*/

class Solution {
    public static ListNode removeNthFromEnd(ListNode head, int n) {
        
        ListNode endPtr, toDelete, headPtr;
        headPtr = new ListNode(0);
        headPtr.next = head;
        
        endPtr = headPtr;
        toDelete = headPtr;
        
        for(int i=0;i<n+1;i++)
            endPtr = endPtr.next;
        
        while(endPtr != null){
            endPtr = endPtr.next;
            toDelete = toDelete.next;
        }
        
        toDelete.next = toDelete.next.next;
        
        return headPtr.next;
    }

	public static void main(String[] args) {
       ListNode head = new ListNode(0);
       head.next = new ListNode(0);
       head.next.next = new ListNode(0);
       head.next.next.next = new ListNode(0);
       head.next.next.next.next = new ListNode(0);
       
       Solution.removeNthFromEnd(head, 3);

	}
}