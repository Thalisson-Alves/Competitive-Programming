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
    for (auto n = 1, t = 1; cin >> n, n; t++)
    {
        cout << "Case " << t << ": ";

        vector<pair<int,int>> v(n);
        vector<int> starts(n), states(n);
        for (auto i = 0; i < n; i++) cin >> v[i].first >> v[i].second >> starts[i], starts[i]--;
        set<pair<int, vector<int>>> vis;
#define STATE_R(x, y) (starts[x] + states[y]) % (v[x].first + v[x].second)
#define STATE(x) STATE_R(x, x)
        auto ans = -1;
        while (1)
        {
            auto cur = 0;
            for (auto i = 1; i < n; i++)
                if (states[i] < states[cur] or (states[i] == states[cur] and STATE(cur) < v[cur].first)) cur = i;

            auto awake = 0;
            for (auto i = 0; i < n; i++)
                if (STATE_R(i, cur) < v[i].first) awake++;
            if (awake >= n - awake)
            {
                for (auto i = 0; i < n; i++)
                {
                    auto is = STATE(i);
                    if (is < v[i].first) ans = max(ans, states[i]);
                    else ans = max(ans, (v[i].first + v[i].second) - is);
                }
                ans++;
                break;
            }

            auto cur_state = STATE(cur);
            if (cur_state >= v[cur].first)
            {
                states[cur] += (v[cur].first + v[cur].second) - cur_state;
                continue;
            }
            if (cur_state != v[cur].first - 1)
            {
                states[cur]++;
                continue;
            }

            states[cur] += (v[cur].first + v[cur].second) - cur_state;
            vector<int> sts(n);
            for (auto i = 0; i < n; i++)
                sts[i] = STATE_R(i, cur);
            if (vis.count(make_pair(cur, sts))) break;
            vis.emplace(cur, sts);
        }
        cout << ans << '\n';
    }
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

