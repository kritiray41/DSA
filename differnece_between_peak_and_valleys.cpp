/**
 * Problem: Peak Valley Difference
 * 
 * --- INTUITION & APPROACH ---
 * 1. The Goal: Find elements that act as peaks (strictly greater than both neighbors) 
 *    and valleys (strictly smaller than both neighbors), sum them up separately, and 
 *    return the difference: (sum of peaks - sum of valleys).
 * 
 * 2. Key Fixes from Initial Code:
 *    - Out-of-Bounds Access: Starting the loop at i = 0 checks nums[-1], and 
 *      ending at i = n - 1 checks nums[n]. We must loop from i = 1 to n - 2.
 *    - Edge Cases: If n < 3, no elements can have both left and right neighbors, 
 *      so we immediately return 0.
 * 
 * 3. Algorithm:
 *    - Check if size < 3. If so, return 0.
 *    - Loop `i` from 1 to `n - 2`.
 *    - Check peak: nums[i] > nums[i - 1] && nums[i] > nums[i + 1] -> add to peak sum.
 *    - Check valley: nums[i] < nums[i - 1] && nums[i] < nums[i + 1] -> add to valley sum.
 *    - Return peak - valley.
 * 
 * --- COMPLEXITY ---
 * - Time Complexity: O(n) — Single pass through the array.
 * - Space Complexity: O(1) — Constant extra space used.
 */

class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int n = nums.size();
        
        // At least 3 elements are required to form a peak or valley
        if (n < 3) return 0;
        
        int peak = 0;
        int valley = 0;
        
        // Iterate only from 1 to n - 2 to prevent out-of-bounds access
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                peak += nums[i];
            }
            if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
                valley += nums[i];
            }
        }   
        
        return peak - valley;
    }
};
