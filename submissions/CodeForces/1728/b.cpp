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
    vector<int> v(n);
    for (auto i = 0; i < n; i++) v[i] = i+1;
    for (auto i = 0, r = n%3; r < 2; r++, i+=2)
        swap(v[i], v[i+1]);

    for (auto i = 0; i < n; i++)
        cout << v[i] << " \n"[i == n-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

	return 0;
}

