#include <bits/stdc++.h>
using namespace std;

string solve(const vector<pair<int, int>> &vs)
{
    for (size_t i = 0; i < vs.size(); i++)
    {
        for (size_t j = 0; j < vs.size(); j++)
        {
            for (size_t k = 0; k < vs.size(); k++)
            {
                if (i == j || j == k || i == k)
                    continue;
                if ((vs[j].first - vs[i].first) * (vs[k].second - vs[i].second) == (vs[j].second - vs[i].second) * (vs[k].first - vs[i].first))
                    return "Yes";
            }
        }
    }
    return "No";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> vs(n);
    for (auto &p : vs)
        cin >> p.first >> p.second;
    cout << solve(vs) << '\n';

    return 0;
}
