/*
 * Leetcode 215: Kth Largest Element in an Array
   https://leetcode.com/problems/kth-largest-element-in-an-array/.

 * Given an integer array nums and an integer k, return the kth largest element
    in the array.

 * Note that it is the kth largest element in the sorted order, not the kth
    distinct element.

 * Can you solve it without sorting?
 */

#include <stdio.h> // Used by main, not the algorithm itself

int findKthLargestHelper(int* nums, int left, int right, int k){
  /* Partition algorithm from quicksort. Uses the rightmost element of nums as
   * the pivot and moves all larger elements to left. */
  int pivot = nums[right]; // Use rightmost element as pivot
  int newLeft = left;
  // Loop through each num from left to right
  for (int i = left; i < right; i++){
    // If larger than the pivot point
    if (nums[i] > pivot){
      // Swap it with newLeft
      int temp = nums[newLeft];
      nums[newLeft] = nums[i];
      nums[i] = temp;
      // Increment newLeft
      newLeft++;
    }
  }
  // Swap newLeft and pivot
  int temp = nums[newLeft];
  nums[newLeft] = pivot;
  nums[right] = temp;
  // End partition algorithm
  
  /* Performance optimizations: avoid duplicate calculations. We do these
   * calculations enough times that the impact is measurable; 103ms to 94ms.
   * Increases memory usage from 11.23 MB to 11.28 MB. */
  int kminus1 = k - 1;
  int numPivots = newLeft - left;

  if (numPivots == kminus1) // Target reached, we have pivoted k times
    return nums[newLeft];

  if (numPivots > kminus1) // Pivoted more than k times
    // Retry with smaller right bound
    return findKthLargestHelper(nums, left, newLeft - 1, k);

  /* Pivoted less than k times, retry with larger left bound and offset k by
   * number of pivots that were done previously */
  return findKthLargestHelper(nums, newLeft + 1, right, kminus1 - newLeft + left);
}

int findKthLargest(int* nums, int numsSize, int k)
{
  // Set up and call recursive helper
  return findKthLargestHelper(nums, 0, numsSize - 1, k);
}

int main(){
  int testCase1[6] = {3, 2, 1, 5, 6, 4};
  printf("findKthLargest(testCase1, 6, 2): %d (expected 5)\n",
          findKthLargest(testCase1, 6, 2));

  int testCase2[9] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  printf("findKthLargest(testCase2, 9, 4): %d (expected 4)\n",
          findKthLargest(testCase2, 9, 4));

  int testCase3[2] = {-1, -1};
  printf("findKthLargest(testCase3, 2, 2): %d (expected -1)\n",
          findKthLargest(testCase3, 2, 2));

  int testCase4[2] = {2, 1};
  printf("findKthLargest(testCase4, 2, 2): %d (expected 1)\n",
          findKthLargest(testCase4, 2, 2));

  int testCase5[3] = {-1, 2, 0};
  printf("findKthLargest(testCase5, 3, 2): %d (expected 0)\n",
          findKthLargest(testCase5, 3, 2));

  return 0;
}
