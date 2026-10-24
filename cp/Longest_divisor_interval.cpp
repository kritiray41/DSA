**
 * Problem: Longest Divisors Interval (Codeforces)
 * 
 * --- INTUITION & APPROACH ---
 * 1. The Goal: Find the maximum size of a contiguous interval [l, r] of positive 
 *    integers such that every number in the interval divides n (i.e., n % i == 0).
 * 
 * 2. Key Mathematical Insight:
 *    - The longest sequence of consecutive integers that all divide n will ALWAYS start at 1.
 *    - Why? In any block of consecutive integers, there is always at least one multiple 
 *      of 2, one multiple of 3, one multiple of 4, etc. If n is divisible by a block of 
 *      numbers, checking blocks starting from 1 yields the maximal contiguous block.
 * 
 * 3. Algorithm:
 *    - Greedily check consecutive integers starting from i = 1, 2, 3, ...
 *    - Keep incrementing `i` as long as `n % i == 0`.
 *    - The moment `n % i != 0`, the chain breaks. The maximum size of the valid 
 *      interval is `i - 1`.
 * 
 * --- COMPLEXITY ---
 * - Time Complexity: O(log n) or practically O(1) per test case because the Least 
 *   Common Multiple (LCM) of numbers up to 45 exceeds 10^18, so the loop runs 
 *   at most ~45 times.
 * - Space Complexity: O(1)
 *//

#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
long long n;
cin>>n;
int i=1;
while(n%i==0)
i++;
cout<<i-1<<endl;
}
return 0;

}
