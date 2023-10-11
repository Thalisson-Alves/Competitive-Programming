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
    int n;
    cin >> n;
    map<string, string> genes;
    map<string, vector<string>> parents;
    const set<string> gene_values{"dominant", "recessive", "non-existent"};
    for (auto i = 0; i < n; i++)
    {
        string x, y;
        cin >> x >> y;
        if (gene_values.count(y))
            genes[x] = y;
        else
            parents[y].push_back(x);
    }

    for (auto cc = true; cc; )
    {
        cc = false;
        for (const auto &x : parents)
        {
            if (not (genes.count(x.second.front()) and genes.count(x.second.back())))
            {
                cc = true;
                continue;
            }
            auto p1 = genes[x.second.front()];
            auto p2 = genes[x.second.back()];
            if (p2 == "dominant") swap(p1, p2);

            if (p2 == "dominant" or (p1 == "dominant" and p2 == "recessive"))
                genes[x.first] = "dominant";
            else if (p1 == "dominant" or (p1 == "recessive" and p2 == "recessive"))
                genes[x.first] = "recessive";
            else
                genes[x.first] = "non-existent";
        }
    }
    for (const auto &x : genes)
        cout << x.first << ' ' << x.second << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t; cin.ignore();
    for (auto i = 1; i <= t; i++)
        solve();

    return 0;
}

