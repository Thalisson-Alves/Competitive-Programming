#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'
#define dfv(v) dff(v); for (auto x:v) cerr << " " << x; cerr << '\n'; 

#define all(x) x.begin(), x.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;


template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &x : v) cin >> x;
    auto x = 0, y = 0, ans = 1;
    vector<vector<bool>> b(n, vector<bool>(m));   
    while (true)
    {
        b[x][y] = true;
        if (v[x][y] == 'R') y++;
        else if (v[x][y] == 'D') x++;
        else if (v[x][y] == 'U') x--;
        else if (v[x][y] == 'L') y--;
        if (x < 0)
        {
            x++;
            break;
        } else if (x == n)
        {
            x--;
            break;
        } else if (y < 0)
        {
            y++;break;
        }
        else if (y == m)
        {
            y--;break;
        }
        if (b[x][y])
        {
            ans = 0;
            break;
        }
    }
    if (ans)
        cout << x+1 << ' ' << y+1 << '\n';
    else
        cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //int n;
    //cin >> n;
    //for (auto t = 1; t <= n; t++)
    {
        // cout << "Case #" << t << '\n';
        solve();
    }

	return 0;
}

