#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(x) dff(x); for (auto y: x) cerr << y << ' '; cerr << '\n';
#define all(x) x.begin(), x.end()

using ll = long long;
using pii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

template<typename T>
double D(const pair<T, T>& P, const pair<T, T>& Q, const pair<T, T>& R)
{
    return (P.first * Q.second + P.second * R.first + Q.first * R.second) -
           (R.first * Q.second + R.second * P.first + Q.first * P.second);
}

void solve()
{
    int p, t;
    cin >> p >> t; cin.ignore();
    vector<set<int>> v(p);
    for (string line; getline(cin, line), line.size();)
    {
        stringstream ss(line);
        int i, j;
        ss >> i >> j;
        v[i-1].insert(j);
    }
    unordered_map<string, int> mp;
    for (auto i = 0; i < p; i++)
    {
        string s;
        for (auto x : v[i])
            s += to_string(x) + '_';
        mp[s]++;
    }
    cout << mp.size() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t; cin.ignore(2);
    for (auto i = 1; i <= t; i++)
    {
        solve();
        if (i<t)cout << '\n';
    }

    return 0;
}

