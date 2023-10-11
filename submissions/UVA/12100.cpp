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

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;
    vector<int> st(10);
    for (auto i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.emplace(x, i);
        st[x]++;
    }
    auto ans = 0;
    while (not q.empty())
    {
        auto front = q.front();
        q.pop();
        auto mx = 0;
        for (auto i = 9; i >= 0; i--)
            if (st[i])
            {
                mx = i;
                break;
            }
        if (front.first == mx)
        {
            ans++;
            if (front.second == m) break;
            st[mx]--;
        }
        q.push(front);
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
    while (t--)
    //{
        solve();
    //}

    return 0;
}

