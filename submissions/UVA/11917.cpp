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
    map<string, int> mp;
    for (auto i = 0; i < n; i++)
    {
        string s;
        int x;
        cin >> s >> x;
        mp[s] = x;
    }
    int d;
    string s;
    cin >> d >> s;

    auto it = mp.find(s);
    if (it == mp.end() or it->second > d + 5)
        cout << "Do your own homework!\n";
    else if (it->second <= d)
        cout << "Yesss\n";
    else
        cout << "Late\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t; cin.ignore();
    for (auto i = 1; i <= t; i++)
        cout << "Case " << i << ": ", solve();

    return 0;
}

