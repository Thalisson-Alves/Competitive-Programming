#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'
#define dfv(x) dff(x); for (auto i = 0u; i < x.size(); i++) cerr << x[i] << " \n"[i==x.size()-1];

#define all(x) x.begin(), x.end()

using ll = long long;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

void solve()
{
    string s;
    cin >> s;
    vector<int> c{3,2,4,1,3,5,0,2,4,6};
    vector<int> v(7);
    for (auto i = 0u; i < s.size(); i++)
        if (s[i] == '1')
            v[c[i]] += 1;

    int f = v.size(), l = -1;
    for (auto i = 0u; i < v.size(); i++)
    {
        if (v[i] and f == v.size()) f = i;
        if (v[i]) l = i;
    }
    auto ans = false;
    for (auto i = f + 1; i < l; i++)
        if (v[i] == 0) ans = true;

    if (ans and s[0] == '0')
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //int n;
    //cin >> n;
    //for (auto t = 1; t <= n; t++)
    {
        // cout << "Case #" << t << '\n';
        solve();
    }

	return 0;
}

