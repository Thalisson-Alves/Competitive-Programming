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
    int g, p;
    while (cin >> g >> p, g or p)
    {
        using T = vector<pair<int, int>>;
        vector<T> races(g, T(p));
        for (auto &race : races)
        {
            for (auto i = 0; i < p; i++)
                cin >> race[i].first, race[i].second = i;
            sort(all(race));
        }

        int q;
        cin >> q;
        while (q--)
        {
            int k;
            cin >> k;
            vector<int> points(k);
            for (auto &x : points) cin >> x;
            unordered_map<int, int> rank;
            auto best = 0;
            for (auto &race : races)
            {
                for (auto i = 0; i < k; i++)
                    rank[race[i].second] += points[i], best = max(best, rank[race[i].second]);
            }
            set<int> ans;
            for (auto x : rank)
                if (x.second == best) ans.insert(x.first+1);

            auto it = ans.begin();
            for (auto i = 0u; i < ans.size(); i++, it++)
                cout << *it << " \n"[i == ans.size()-1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}

