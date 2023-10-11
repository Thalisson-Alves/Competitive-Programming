#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'
#define dfv(x) dff(x); for (auto i = 0u; i < x.size(); i++) cerr << x[i] << " \n"[i==x.size()-1];
#define all(x) x.begin(), x.end()

using ll = long long;
using pii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir{{1,0},{-1,0},{0,1},{0,-1}};

inline auto check(const vector<vector<bool>> &g, const string &s, char c, int j)
{
    for (auto i = 0; i < (int)g.size(); i++)
        if (s[i] == c and g[i][j])
            return false;
        else if (i != j and s[j] == s[i] and not g[j][i])
            return false;
    return true;
}

inline auto solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<vector<bool>> w(n, vector<bool>(n));
    string labels(n, '-');
    for (int x, y; cin >> x >> y;)
    {
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
        w[x-1][y-1] = 1;
        w[y-1][x-1] = 1;
    }
    for (auto i = 0; i < n; i++)
        if ((int)g[i].size() == n - 1)
            labels[i] = 'b';

    auto it = labels.find('-');
    if (it != string::npos)
    {
        labels[it] = 'a';
        for (auto x : g[it])
            if (labels[x] == '-')
                labels[x] = 'a';
    }
    replace(all(labels), '-', 'c');
    auto valid = true;
    for (auto i = 0; i < n and valid; i++)
    {
        if (labels[i] == 'b')
            valid = (int)g[i].size() == n - 1;
        else
            valid = check(w, labels, labels[i] == 'a' ? 'c' : 'a', i);
    }
    cout << (valid ? "Yes" : "No") << '\n';
    if (valid) cout << labels << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //int t;
    //cin >> t;
    //for (auto i = 1; i <= t; i++)
        solve();

    return 0;
}

