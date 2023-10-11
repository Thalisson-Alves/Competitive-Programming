#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'
#define dfv(x) dff(x); for (auto i = 0u; i < x.size(); i++) cerr << x[i] << " \n"[i==x.size()-1];

#define all(x) x.begin(), x.end()

using ll = long long;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

inline auto f(int n)
{
    return int(log10(n)) + 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    priority_queue<int> pa(all(a)), pb(all(b));

    auto ans = 0ll;
    while (not pa.empty())
    {
        auto x = pa.top();
        auto y = pb.top();
        if (x == y)
        {
            pa.pop();
            pb.pop();
            continue;
        }

        if (x > y)
        {
            pa.pop();
            pa.emplace(f(x));
        }
        else if (y > x)
        {
            pb.pop();
            pb.emplace(f(y));
        }

        ans++;
    }

    cout << ans << '\n';
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

