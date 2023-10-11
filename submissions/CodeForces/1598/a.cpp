#include <bits/stdc++.h>
using namespace std;

string solve(const vector<vector<char>>& grid)
{
    int n = grid[0].size();
    for (int i = 0; i < n - 1; i++)
    {
        if (grid[0][i+1] == '1' && grid[1][i+1] == '1')
            return "NO";
    }
    return "YES";
}

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<char>> grid(2, vector<char>(n));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];

        cout << solve(grid) << '\n';
    }

    return 0;
}
