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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<set<int>> v(m);
    for (auto i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int x;
            cin >> x;
            v[i].insert(x);
        }
    }
    for (auto i = 1; i <= n; i++)
    {
        for (auto j = i + 1; j <= n; j++)
        {
            auto ok = false;
            for (auto &st : v)
                if (st.count(i) && st.count(j))
                {
                    ok = true;
                    break;
                }
            if (not ok)
            {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (auto i = 1; i <= t; i++)
        solve();

    return 0;
}

