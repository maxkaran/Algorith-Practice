//Question from LeetCode: https://leetcode.com/problems/powx-n/description/
//given an integer x (-100 < x < 100) and 32 bit signed integer n (-2^31 < n < 2^31 - 1), return x^n

class Solution {
    public static double myPow(double x, int n) {
    	//Due to edge case of having the 32 bit signed integer at value -2^31 (which is 32 1 bits in succession), n = -n doesn't work and
    	//causes the bits to overflow, resulting in half the value, but it stays negative. To handle this edge case, the following if statement is necessary
    	if(n == -2147483648 && java.lang.Math.abs(x) != 1)
    		return 0;
    	
    	if(n<0){
            n = -n;
            x = 1/x;
        }
        	
        if (n == 0)
            return 1;
        
        double ans = myPow(x, n/2);
        
        if (n%2 == 0){
            return ans*ans;
        }
        else{
            return x*ans*ans;
        }
    }
    
    public static void main(String[] args) {
    	System.out.println(Solution.myPow(2, -2147483648));
    }
}