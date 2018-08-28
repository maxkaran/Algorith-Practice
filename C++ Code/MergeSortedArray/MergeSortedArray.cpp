#include <vector>

using namespace std;


class MergeSortedArray {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //edgecase of empty vectors
        if(n == 0)
            return;
        else if(m == 0){
            for(int i=0;i<m+n;i++){
    		    nums1[i] = nums2[i];
    	    }
            return;
        }

    	vector<int> sorted = vector<int>(m);
    	int i=0, j=0, sortedIndex = 0;; //iterators for the sorted arrays

    	while(i<m && j<n){
    		if(nums1[i] <= nums2[j]){
    			sorted[sortedIndex] = nums1[i];
    			i++;
    		}else{
    			sorted[sortedIndex] = nums2[j];
    			j++;
    		}
    		sortedIndex++;
    	}

    	while(j<n){
    		sorted[sortedIndex++] = nums2[j++];
    	}
    	while(i<m){
    		sorted[sortedIndex++] = nums1[i++];
    	}

    	for(int i=0;i<sorted.size();i++){
    		nums1[i] = sorted[i];
    	}

    }
};
