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
    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    for (auto i = 0; i < n; i++)
    {
        string s;
        int a, c;
        char b;
        cin >> s >> a >> b >> c;
        mp[s] = a * 10 + c;
    }
    for (auto i = 1; i <= m; i++)
    {
        auto sum = 0;
        auto ans = false;
        while (1)
        {
            string s;
            string c;

            cin >> s >> c;
            sum += mp[s];
            if (c != "+")
            {
                int x;
                cin >> x;
                if (c == ">")
                    ans = sum > x * 10;
                else if (c == ">=")
                    ans = sum >= x * 10;
                else if (c == "<")
                    ans = sum < x * 10;
                else if (c == "<=")
                    ans = sum <= x * 10;
                else
                    ans = sum == x * 10;
                break;
            }
        }
        cout << "Guess #" << i << " was" << (not ans ? " in" : " ") << "correct.\n";
    }
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

