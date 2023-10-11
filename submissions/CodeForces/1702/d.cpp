#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'
#define dfv(x) dff(x); for (auto y: x) cerr << y << ' '; cerr << '\n';
#define all(x) x.begin(), x.end()

using ll = long long;
using pii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
    string s;
    cin >> s;
    int p;
    cin >> p;
    auto total = 0;
    map<char, int> mp;
    for (auto &c : s)
        mp[c]++, total += c - 'a' + 1;
    for (auto it = mp.rbegin(); total > p and it != mp.rend(); it++)
    {
        while (total > p and it->second)
        {
            it->second--;
            total -= (it->first - 'a' + 1);
        }
    }
    for (auto &c : s)
        if (mp[c]) cout << c, mp[c]--;
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    for (auto i = 1; i <= t; i++)
        solve();

    return 0;
}

