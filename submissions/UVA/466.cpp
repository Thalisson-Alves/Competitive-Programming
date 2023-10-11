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

void rotate90(vector<string> &v)
{
    auto a = v;
    for (auto i = 0u; i < v.size(); i++)
        for (auto j = 0u; j < v.size(); j++)
            v[i][j] = a[v.size() - 1u - j][i];
}

void reflect(vector<string> &v)
{
    auto a = v;
    for (auto i = 0u; i < v.size(); i++)
        for (auto j = 0u; j < v.size(); j++)
            v[i][j] = a[v.size() - 1u - i][j];
}

void solve()
{
    int n;
    for (auto t = 1; cin >> n; t++)
    {
        vector<string> a(n), b(n);
        for (auto i = 0; i < n; i++)
            cin >> a[i] >> b[i];

        cout << "Pattern " << t << " was ";
        if (a == b)
        {
            cout << "preserved.\n";
            continue;
        }

        auto r = a;
        reflect(r);

        auto ans = false;
        for (auto i = 1; i < 4; i++)
        {
            rotate90(a);
            if (a == b)
            {
                ans = true;
                cout << "rotated " << i * 90 << " degrees.\n";
                break;
            }
            rotate90(r);
            if (r == b)
            {
                ans = true;
                cout << "reflected vertically and rotated " << i * 90 << " degrees.\n";
                break;
            }
        }

        rotate90(r);
        if (ans)
            continue;
        if (r == b)
            cout << "reflected vertically.\n";
        else
            cout << "improperly transformed.\n";
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

