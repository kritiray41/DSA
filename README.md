# Palindrome Number

## Problem
Given an integer `x`, return `true` if `x` is a palindrome, and `false` otherwise.

## Approach
- Reverse the integer
- Compare reversed number with original number
- If both are same, then it is palindrome

## Time Complexity
O(log n)

## Space Complexity
O(1)

## C++ Solution

```cpp
class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) {
            return false;
        }

        int original = x;
        long long rev = 0;

        while (x > 0) {

            int digit = x % 10;

            rev = rev * 10 + digit;

            x /= 10;
        }

        return original == rev;
    }
};
```
