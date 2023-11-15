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
    int a = -1, b = -1, c = -1, d = -1;
    for (auto i = 0; i < 10; i++)
    {
        string s;
        cin >> s;
        auto j = s.find('#');
        if (j != string::npos)
        {
            if (a == -1) a = i + 1;
            b = i + 1;
            c = j + 1;
            d = s.rfind('#') + 1;
        }
    }
    cout << a << ' ' << b << '\n' << c << ' ' << d << '\n';
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

