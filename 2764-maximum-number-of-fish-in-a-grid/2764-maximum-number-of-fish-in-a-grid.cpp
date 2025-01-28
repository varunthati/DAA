#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxFish = 0;

        // Helper function for DFS
        auto dfs = [&](int r, int c, auto& dfsRef) -> int {
            // Base case: out of bounds or land cell
            if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
                return 0;
            }

            // Collect fish in current cell and mark it as visited
            int fish = grid[r][c];
            grid[r][c] = 0;

            // Explore all 4 adjacent cells
            fish += dfsRef(r + 1, c, dfsRef);
            fish += dfsRef(r - 1, c, dfsRef);
            fish += dfsRef(r, c + 1, dfsRef);
            fish += dfsRef(r, c - 1, dfsRef);

            return fish;
        };

        // Loop through all cells in the grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {  // Start DFS if it's a water cell
                    maxFish = max(maxFish, dfs(i, j, dfs));
                }
            }
        }

        return maxFish;
    }
};
