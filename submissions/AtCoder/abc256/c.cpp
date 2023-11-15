#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'
#define dfv(x) dff(x); for (auto y: x) cerr << y << ' '; cerr << '\n';
#define all(x) x.begin(), x.end()

using ll = long long;
using pii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

vector<vector<int>> allcomb(int h)
{
    vector<vector<int>> comb;
    for (auto i = 1; i < h; i++)
        for (auto j = 1; j < h - i; j++)
            comb.push_back(vector<int>{i, j, h-i-j});
    return comb;
}

void solve()
{
    vector<int> hs(3), ws(3);
    for (auto &x : hs) cin >> x;
    for (auto &x : ws) cin >> x;

    const auto &ac0 = allcomb(hs[0]);
    const auto &ac1 = allcomb(hs[1]);
    const auto &ac2 = allcomb(hs[2]);

    auto ans = 0;
    for (const auto &c0 : ac0)
    {
        for (const auto &c1 : ac1)
        {
            for (const auto &c2 : ac2)
            {
                auto s0 = c0[0] + c1[0] + c2[0];
                auto s1 = c0[1] + c1[1] + c2[1];
                auto s2 = c0[2] + c1[2] + c2[2];
                if (s0 == ws[0] and s1 == ws[1] and s2 == ws[2]) ans++;
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //int t;
    //cin >> t;
    //while (t--)
    //{
        solve();
    //}

    return 0;
}

