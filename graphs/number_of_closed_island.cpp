# Number of Closed Islands (LeetCode 1254)

## Approach
An island is considered "closed" if it is entirely surrounded by water (`1`), meaning it does not touch the outer boundary of the grid. 

1. **Boundary Elimination (DFS):** 
   - Any land cell (`0`) that touches the outer edges (top, bottom, left, right rows/columns) of the grid cannot form a closed island. 
   - We first traverse all border cells. If we find a `0`, we perform a DFS to flood-fill and convert all connected land cells to water (`1`).

2. **Count Remaining Islands:**
   - After clearing all border-connected land masses, any remaining `0` in the grid is guaranteed to be completely enclosed by water.
   - We iterate through the grid, and for every `0` we encounter, we increment our island count and sink that entire island using DFS to avoid double-counting.

---

## Complexity Analysis
- **Time Complexity:** $O(M \times N)$ — Where $M$ is the number of rows and $N$ is the number of columns. Every cell is visited at most a constant number of times.
- **Space Complexity:** $O(M \times N)$ — In the worst-case scenario (e.g., a grid filled entirely with land), the recursion stack for the DFS will go as deep as the total number of cells.

---

## C++ Code
class Solution {
public:
int m,n;
bool dfs(vector<vector<int>>& grid,int r,int c){
    if(r>=m || r<0 || c>=n || c<0)
    return false;
    if(grid[r][c]==1){
        return true;
    }
    grid[r][c]=1;//mark visited
    bool left_close=dfs(grid,r,c-1);
    bool right_close=dfs(grid,r,c+1);
    bool up_close=dfs(grid,r-1,c);
    bool down_close=dfs(grid,r+1,c);
    return left_close && right_close && up_close && down_close;//closed island
}
    int closedIsland(vector<vector<int>>& grid) {
       m=grid.size();
       n=grid[0].size();
       int count=0;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0){
                if(dfs(grid,i,j)==true){
                    count++;
                }
            }
        }
       } 
       return count;

    }
};
