Intuition
To rotate the array efficiently, instead of shifting elements one by one, we can use the reversal technique.
The main idea is:

Reverse the entire array.
Reverse the first k elements.
Reverse the remaining elements.
This places every element in its correct rotated position.

Approach
Find the size of the array n.
Since rotating n times results in the same array, compute:
k = k % n
Reverse the complete array.
Reverse the first k elements.
Reverse the remaining n-k elements.
This achieves rotation in-place without using extra space.

Complexity
Time complexity:
O(n)
Each reverse operation takes linear time.

Space complexity:
O(1)
No extra space is used.

Code
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
