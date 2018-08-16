/* https://leetcode.com/problems/length-of-last-word/description/
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.
*/

class Solution {
    public int lengthOfLastWord(String s) {
        int index = s.length()-1;
        int count = 0;

        while(index != -1 && s.charAt(index) == ' ')
            index--;
                
        while(index != -1 && s.charAt(index) != ' '){
            count++;
            index--;
        }
        
        return count;
    }
}