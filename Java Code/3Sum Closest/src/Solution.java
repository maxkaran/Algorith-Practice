import java.util.*;

//https://leetcode.com/problems/3sum-closest/description/
//Find the sum of 3 numbers closest to the target

class Solution {
    public static int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums); //this will rearrange the array in ascending order in O(log n) time complexity
        int closestToTarget = nums[0]+nums[1]+nums[2]; //initialize first 3sum to first 3 values in array

        for(int i=0;i<nums.length;i++) {
        	int diff = target - nums[i];
        	int j = i+1, k = nums.length-1;
        	while(j<k) {
        		if(Absolute(nums[i]+nums[j]+nums[k] - target) < Absolute(closestToTarget-target)) //doesn't matter if neg or pos, as long as it's closer
        			closestToTarget = nums[i]+nums[j]+nums[k];
        		
        		if(closestToTarget == target)
        			return target; //if the actual number is hit, the sum cannot get any closer, return it
        		
        		if(nums[j]+nums[k] < diff) //if difference is too little
        			j++; //go to next smallest value
        		else if(nums[j]+nums[k] > diff) //if difference is too great
        			k--; //go to next largest value
        	}
        }
        
        return closestToTarget;
    }

	private static int Absolute(int i) {//get absolute value of an integer
		if(i<0)
			i *= -1;
		
		return i;
	}

	public static void main(String[] args) {
		//test case
		int[] nums = {-1, 2, 1, -4};
		System.out.println(Solution.threeSumClosest(nums, 1));

	}

}
