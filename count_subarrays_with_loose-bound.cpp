/**leetcode ps=2089

 * Problem: Count Loose-Bound Subarrays
 * 
 * --- INTUITION & APPROACH ---
 * 1. The Goal: Find the number of contiguous subarrays where every element 
 *    satisfies: minK <= nums[i] <= maxK.
 * 
 * 2. Key Insight (The Blocker Rule):
 *    - An element outside the range [minK, maxK] acts as an invalid boundary. 
 *      No valid subarray can cross an invalid element.
 *    - Invalid elements split the array into independent, contiguous blocks of valid numbers.
 * 
 * 3. Counting Subarrays in a Block:
 *    - For any contiguous block of valid elements of length L, the number of valid 
 *      subarrays is given by the formula: L * (L + 1) / 2.
 * 
 * 4. Algorithm:
 *    - Loop through `nums`.
 *    - If the element is valid, increment `curr_len`.
 *    - If the element is invalid, add the block's contribution (curr_len * (curr_len + 1) / 2) 
 *      to `totalsubarray` using `+=`, then reset `curr_len` to 0.
 *    - After the loop, add the remaining valid block's count and return the total.
 * 
 * --- COMPLEXITY ---
 * - Time Complexity: O(N) — Single pass through the array.
 * - Space Complexity: O(1) — Constant extra space.
 */
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       long long totalsubarray=0;
       long long curr_len=0;
       for(int i=0;i<nums.size();i++){
            if(nums[i]>=minK && nums[i]<=maxK){
                curr_len++;
            }else{
                totalsubarray+=(curr_len*(curr_len+1))/2;
                curr_len=0;
            }
                
       }
            return totalsubarray+=(curr_len*(curr_len+1))/2;
       
    }
};
