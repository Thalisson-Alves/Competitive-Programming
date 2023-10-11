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

auto is_connected(const vector<vector<int>> &g)
{
    set<int> s;
    stack<int> st;
    st.push(0);
    while (not st.empty())
    {
        auto t = st.top();
        st.pop();
        for (auto x : g[t])
            if (not s.count(x))
                st.push(x), s.insert(x);
    }

    return s.size() == g.size();
}

inline auto solve()
{
    int n, m;
    cin >> n >> m;
    if (n != m)
    {
        cout << "NO\n";
        return;
    }
    vector<vector<int>> g(n);
    for (int x, y; cin >> x >> y;)
        g[x-1].push_back(y-1),g[y-1].push_back(x-1);
    cout << (is_connected(g) ? "FHTAGN!" : "NO") << '\n';
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

