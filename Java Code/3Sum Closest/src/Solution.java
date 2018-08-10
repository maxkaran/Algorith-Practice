import java.util.*;

//https://leetcode.com/problems/3sum-closest/description/
//Find the sum of 3 numbers closest to the target

class Solution {
    public static int threeSumClosest(int[] nums, int target) {
        HashSet<Integer> intHash = new HashSet<>(nums.length); //hash table to hold all nums
        
        int closest = nums[0]+nums[1]+nums[2];
        
        for(int num : nums) { //place all integers in nums into the hashset
        	intHash.add(num);
        }
    	

        return closest;
    }


	public static void main(String[] args) {
		//test case
		int[] nums = {-1, 2, 1, -4};
		System.out.println(Solution.threeSumClosest(nums, 1));

	}

}
