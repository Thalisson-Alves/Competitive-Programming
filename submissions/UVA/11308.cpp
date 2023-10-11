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

vector<string> split(const string &s)
{
    vector<string> ans;
    stringstream ss(s);
    for (string x; ss >> x; ans.push_back(x));
    return ans;
}

void solve()
{
    string title;
    getline(cin, title);
    transform(all(title), title.begin(), [](char c){return toupper(c);});
    cout << title << '\n';

    int m, n, b;
    cin >> m >> n >> b;
    cin.ignore();

    map<string, int> mp;
    for (auto i = 0; i < m; i++)
    {
        string s;
        int x;
        cin >> s >> x;
        mp[s] = x;
    }
    cin.ignore();
    vector<pair<int, string>> ans;
    while (n--)
    {
        string s;
        getline(cin, s);

        int k;
        cin >> k;
        auto cost = 0ll;
        for (string ss; k--; )
        {
            int x;
            cin >> ss >> x;
            cost += x * mp[ss];
        }
        cin.ignore();

        if (cost <= b)
            ans.emplace_back(cost, s);
    }
    sort(all(ans));
    for (auto &p : ans)
        cout << p.second << '\n';
    if (ans.empty())
        cout << "Too expensive!\n";
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t; cin.ignore();
    for (auto i = 1; i <= t; i++)
        solve();

    return 0;
}

