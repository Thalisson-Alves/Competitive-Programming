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

void solve()
{
    set<string> ans;
    string s;
    for (char c; cin >> noskipws >> c; )
    {
        if (isalpha(c))
            s.push_back(tolower(c));
        else if (c != '-')
        {
            if (s.size())
                ans.insert(s);
            s.clear();
        }
        else
        {
            char next;
            cin >> noskipws >> next;
            if (next != '\n')
                s.push_back(c);
            else
                continue;

            if (isalpha(next))
                s.push_back(tolower(next));
            else 
            {
                if (s.size() and s != "-") ans.insert(s);
                s.clear();
            }
        }
    }
    for (auto &x : ans) cout << x << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    for (auto i = 1; i <= t; i++)
        solve();

    return 0;
}
