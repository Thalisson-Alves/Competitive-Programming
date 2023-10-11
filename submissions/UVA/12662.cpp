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

string rep(int n, string s)
{
    auto a = s;
    while (--n) s += a;
    return s;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &x : v) cin >> x;
    int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;
        --a;
        int l, r;
        for (r = a + 1; r < n and v[r] == "?"; r++);
        for (l = a - 1; l >= 0 and v[l] == "?"; l--);
        if (v[a] != "?")
            cout << v[a] << '\n';
        else if (r == n or (r - a > a - l and l != -1))
            cout << rep(a - l, "right of ") << v[l] << '\n';
        else if (l == -1 or (r - a < a - l and r != -1))
            cout << rep(r - a, "left of ") << v[r] << '\n';
        else
            cout << "middle of " << v[l] << " and " << v[r] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}

