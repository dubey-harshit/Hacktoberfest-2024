#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> run(vector<vector<char>> grid, vector<vector<int>> visited, int i, int j)
    {

        visited[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        auto inside = [&](int row, int col)
        {
            return 0 <= row && row < grid.size() && 0 <= col && col < grid[0].size();
        };

        while (!q.empty())
        {
            pair<int, int> node = q.front();
            q.pop();
            for (auto dir : directions)
            {
                int row = node.first + dir.first;
                int col = node.second + dir.second;

                if (inside(row, col) && !visited[row][col] && grid[row][col] == '1')
                {
                    q.push({row, col});
                    visited[row][col] = 1;
                }
            }
        }
        return visited;
    }
    int bfs(vector<vector<char>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> visited(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                visited[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    visited = run(grid, visited, i, j);
                }
            }
        }
        return cnt;
    }
    int numIslands(vector<vector<char>> &grid)
    {
        return bfs(grid);
    }
};

int main()
{

    // Leetcode Solution to proble - https://leetcode.com/problems/number-of-islands/
    return 0;
}