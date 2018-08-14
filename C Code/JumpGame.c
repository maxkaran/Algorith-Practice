/*https://leetcode.com/problems/jump-game/description/
  Given an array of non-negative integers, you are initially positioned at the first index of the array.
  Each element in the array represents your maximum jump length at that position.
  Determine if you are able to reach the last index.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int helper(int *nums, int *numsTested, int numsSize, int index){
    int jumpVal = nums[index]; //how far one can jump from this point

    if(jumpVal+index+1 >= numsSize){ //this is reaching the end of the array
        return 1;
    }else if(nums[index] == 0){ //this index cannot go any further
        return 0;
    }

    for(int i=jumpVal;i>0;i--){//check all reachable indexes from this index
        if(numsTested[i+index] == 2){ //if undefined, figure out if it is valid
            numsTested[i+index] = helper(nums, numsTested, numsSize, i+index);
            if(numsTested[i+index] == 1){ //if it is can reach end, this index can reach the end as well
                return 1;
            }
        }
    }
    return 0; //no valid jump paths from this index

}

bool canJump(int* nums, int numsSize) {
    int *reachable = malloc(numsSize * sizeof(int));
    
    for(int i=0;i<numsSize;i++){
        reachable[i] = 2; //2 means that this point in the array has not been checked yet and is undefined
    }

    reachable[0] = helper(nums, reachable, numsSize, 0);
    return reachable[0];
}

int main(void){ //test cases
    int arr1[] = {3,2,1,0,4}; //end unreachable

    if(canJump(arr1, 5) == false){
        printf("correct! The end is unreachable\n");
    }

    int arr2[] = {2,3,1,1,4}; //end reachable

    if(canJump(arr2, 4) == true){
        printf("correct! The end is reachable\n");
    }
}