
class Solution {
public:
    vector<vector<vector<int>>> t;

    int solve(vector<vector<int>>& grid, int i, int j, int x) {
        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds
        if (i < 0 || i >= m || j < 0 || j >= n)
            return INT_MAX;

        if (t[i][j][x] != -1)  
            return t[i][j][x];

        int cur = x ^ grid[i][j];

        if (i == m - 1 && j == n - 1)
            return t[i][j][x] = cur;
        return t[i][j][x] = min(solve(grid, i + 1, j, cur), solve(grid, i, j + 1, cur));
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        t = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(1024, -1)));
        
        return solve(grid, 0, 0, 0);
    }
};
