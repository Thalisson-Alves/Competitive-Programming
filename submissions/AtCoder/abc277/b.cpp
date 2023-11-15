#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'
#define dfv(x) dff(x); for (auto i = 0u; i < x.size(); i++) cerr << x[i] << " \n"[i==x.size()-1];

#define all(x) x.begin(), x.end()

using ll = long long;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{-1,0},{0,-1},{1,0},{0,1}};

void solve()
{
    int n;
    cin >> n;
    set<string> st;
    string ans = "Yes", ff = "HDCS", ss = "A23456789TJQK";
    while (n--)
    {
        string s;
        cin >> s;
        if (st.count(s) or ff.find(s[0])==string::npos or ss.find(s[1])==string::npos)
        {
            ans = "No";
            break;
        }
        st.insert(s);
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //int t;
    //cin >> t;
    //for (auto i = 1; i <= t; i++)
        solve();

    return 0;
}
