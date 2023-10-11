#include <bits/stdc++.h>
using namespace std;

string solve(const vector<vector<int>> &grid)
{
    vector<int> available(5);
    int treashold = grid.size() / 2;
    for (int i = 0; i < 5; i++)
        for (auto &person : grid)
            available[i] += person[i];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == j || (available[i] < treashold || available[j] < treashold))
                continue;

            int both = 0;
            for (auto &person : grid)
                both += person[i] == person[j];

            int ma = max(available[i], available[j]);
            int mb = min(available[j], available[i]);

            if (mb - both >= treashold) return "YES";
            if (ma - ((treashold - (mb - both))) >= treashold) return "YES";
            if (mb-both >= treashold)
                return "YES";
        }
    }
    return "NO";
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
        vector<vector<int>> grid(n, vector<int>(5));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 5; j++)
                cin >> grid[i][j];

        cout << solve(grid) << '\n';
    }

    return 0;
}
