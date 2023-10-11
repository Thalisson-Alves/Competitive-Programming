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
    int n;
    cin >> n;
    stack<pair<int, int>> st;
    while (n--)
    {
        string command;
        cin >> command;
        if (command == "PUSH")
        {
            int x;
            cin >> x;
            if (not st.empty())
                st.emplace(x, min(x, st.top().second));
            else
                st.emplace(x, x);
        }
        else if (command == "MIN")
        {
            if (st.empty()) cout << "EMPTY\n";
            else cout << st.top().second << '\n';
        }
        else
        {
            if (st.empty()) cout << "EMPTY\n";
            else st.pop();
        }
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

