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

inline auto solve()
{
    string s;
    cin >> s;
    list<char> l;
    for (auto c: s)
        l.push_back(c);

    auto ans = false;
    for (auto ib = l.begin(), ia = ib++; ia != l.end() and ib != l.end(); ia=ib++)
    {
        if (*ia != *ib) continue;
        auto bt = ia == l.begin();
        auto tmp = --ia;
        l.erase(++ia, ++ib);
        ib = bt ? l.begin() : tmp;
        ans = not ans;
    }
    cout << (ans ? "Yes" : "No") << '\n';
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

