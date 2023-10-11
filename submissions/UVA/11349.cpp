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

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

const char* solve()
{
    int n;
    cin.ignore(4); cin >> n;
    vector<vector<long long>> v(n, vector<long long>(n));
    for (auto &r : v) for (auto &x : r) cin >> x;
    for (auto i = 0; i < n / 2 + 1; i++)
    {
        for (auto j = i; j < n - i; j++)
        {
            // Check column
            if (v[j][i] < 0 or v[j][i] != v[n-1-j][n-1-i]) return "Non-symmetric";
            // Check row
            if (v[i][j] != v[n-1-i][n-1-j]) return "Non-symmetric";
        }
    }
    return "Symmetric";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (auto i = 1; i <= t; i++)
        cout << "Test #" << i << ": " << solve() << ".\n";

    return 0;
}

