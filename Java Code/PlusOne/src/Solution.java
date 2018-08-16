/*https://leetcode.com/problems/plus-one/description/
 * Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
 * The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
 * You may assume the integer does not contain any leading zero, except the number 0 itself.
*/
class Solution {
    public int[] plusOne(int[] digits) {
        int endIndex = digits.length - 1;
        while(digits[endIndex] == 9){
            digits[endIndex] = 0;
            endIndex--;
            if(endIndex == -1){
                int returnArr[] = new int[digits.length + 1];
                returnArr[0] = 1;
                for(int i=1;i<returnArr.length;i++)
                    returnArr[i] = 0;
                
                return returnArr;
            }
        }
        
        digits[endIndex]++;
        
        return digits;
        
    }
}