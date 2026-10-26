# leetcode(ps)_Count Islands with Total Value Divisible by K

## Approach
This problem can be efficiently solved using **Depth-First Search (DFS)** to find all connected components (islands) of positive numbers in the grid.

1. **Grid Traversal:** 
   - We iterate through every cell `(i, j)` in the $m \times n$ grid. 
   - When we encounter a cell with a positive value (`grid[i][j] > 0`), it marks the beginning of a new island.

2. **DFS Flood-Fill & Sum Accumulation:**
   - From that starting cell, we trigger a DFS that explores all 4-directional neighbors (up, down, left, right).
   - During the traversal, we add up the values of all connected cells into a `sum` variable and mark the visited cells as `0` to prevent counting them multiple times.
   - We use `long long` for the sum to prevent potential integer overflow since cell values and grid sizes can be large.

3. **Divisibility Check:**
   - Once the DFS completes for an island, we check if its total `sum` is divisible by $k$ (`sum % k == 0`). 
   - If it is, we increment our valid island counter.

---

## Complexity Analysis
- **Time Complexity:** $O(M \times N)$ — Where $M$ is the number of rows and $N$ is the number of columns. Every cell is visited a constant number of times during the traversal and DFS flood-fill.
- **Space Complexity:** $O(M \times N)$ — In the worst-case scenario (e.g., a single large island covering the entire grid), the recursion stack depth can grow up to $O(M \times N)$.

---

## C++ Code

```cpp
class Solution {
public: 
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    long long dfs(int i, int j, vector<vector<int>>& grid) {
        long long sum = grid[i][j];
        grid[i][j] = 0; // Mark as visited by setting to 0
        
        for (vector<int>& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0) {
                sum += dfs(i_, j_, grid);
            }
        }
        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = dfs(i, j, grid);
                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
