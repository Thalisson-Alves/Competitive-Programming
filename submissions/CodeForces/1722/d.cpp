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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> ps(n+1), ss(n+1);
    for (auto i = 0; i <= n; i++)
    {
        ps[i] = i;
        ss[i] = n - i;
    }
    auto sum = 0LL;
    for (auto i = 0; i < n; i++)
        sum += (s[i] == 'L' ? ps[i] : ss[i+1]);

    vector<ll> ans{sum};
    for (auto i = 0; i < n / 2; i++)
    {
        if (s[i] == 'L')
            ans.push_back(ans.back() - ps[i] + ss[i+1]);
        if (s[n - i - 1] == 'R')
            ans.push_back(ans.back() - ss[n - i] + ps[n - i - 1]);
    }


    ll size = ans.size();
    for (auto i = 0; i < n - size + 1; i++)
        ans.push_back(ans.back());
    for (auto i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (auto t = 1; t <= n; t++)
    {
        // cout << "Case #" << t << '\n';
        solve();
    }

	return 0;
}

