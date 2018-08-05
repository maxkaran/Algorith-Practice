class Solution {
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode start = new ListNode(0);
        ListNode current = start;
        ListNode p1 = l1, p2 = l2; //pointers for linked lists that are being passed in
        boolean carry = false;
        
        while(p1 != null || p2 != null) {
        	int val1, val2;
        	
        	if(p1 == null)
        		val1 = 0;
        	else
        		val1 = p1.val;
        	
        	if(p2 == null)
        		val2 = 0;
        	else
        		val2 = p2.val;
        	
        	current.val = val1 + val2;
        	
        	if(carry) {
        		current.val += 1; //if there is a carry from previous node, add one
        		carry = false;
        	}
        	
        	if(current.val >= 10) { //if value exceeds 10, there is a carry for the next node
        		current.val -= 10;
        		carry = true;
        	}
        	
        	if(p1 != null) p1 = p1.next;
        	if(p2 != null) p2 = p2.next;
        	
        	if(p1 != null || p2 != null) { //if there is more values to be added, create a new node
        		current.next = new ListNode(0);
        		current = current.next;
        	}
        	
        }
        
        if(carry) //if there is a final carry out, the last node will just be a one
        	current.next = new ListNode(1);
        
        return start;
    }
    
    
	public static void main(String[] args) {
		ListNode l1 = new ListNode(4), l2 = new ListNode(5);
		l1.next = new ListNode(5); l2.next = new ListNode(6);
		l1.next.next = new ListNode(3); l2.next.next = new ListNode(4);
		
		ListNode solution = Solution.addTwoNumbers(l1, l2);
		
		while(solution != null) {
			System.out.println(solution.val);
			solution = solution.next;
		}

	}

}
