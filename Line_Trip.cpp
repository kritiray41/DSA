//=== APPROACH: Line Trip ===

/*1. PROBLEM UNDERSTANDING:
- You need to travel from point 0 to point x and back to point 0.
- You have n gas stations located at positions a_1, a_2, ..., a_n.
- Your car fully refuels whenever it hits a gas station.
- Goal: Find the minimum tank size (maximum single gap you must cross without refueling).

2. KEY OBSERVATIONS:
The entire trip is divided into segments (gaps) between consecutive check-points (0, gas stations, and x). Because you must survive the worst-case single stretch, your tank capacity must be at least as large as the maximum gap among the following three types:

  a) First Gap: From the starting point 0 to the first gas station.
     - Distance = a[0] - 0 = a[0]

  b) Intermediate Gaps: Between any two adjacent gas stations.
     - Distance = a[i+1] - a[i]  (for all i from 0 to n-2)

  c) Final Gap (The Turnaround): From the last gas station to x and back.
     - Since there is no gas station at x, you must drive to x and return to the last station without refueling.
     - Distance = 2 * (x - a[n-1])

3. ALGORITHM / STEPS:
1. Read t (number of test cases).
2. For each test case, read n and x, followed by the array of gas stations `a`.
3. Initialize `max_gap` with the distance to the first station: `a[0]`.
4. Loop through the stations from i = 0 to n-2 to check distances between adjacent stations:
   - `max_gap = max(max_gap, a[i+1] - a[i])`
5. Calculate the distance from the last station to x and back:
   - `last_gap = 2 * (x - a[n-1])`
   - `max_gap = max(max_gap, last_gap)`
6. Print `max_gap`.

4. COMPLEXITY:
- Time Complexity: O(n) per test case, since we iterate through the station array once.
- Space Complexity: O(n) to store the stations (can be optimized to O(1) if processed on the fly).
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
cin>>t;
while(t--){
long long n,k;
cin>>n>>k;
for(int i=0;i<n;i++){
int max_count=a[0];
max_count=max(max_count,a[i+1]-a[i]);
}
int last_count=2*(x-a[n-1]);
max_count=max(max_count,last_count);
}
  cout<<max_gap<<endl;
return 0;
}


