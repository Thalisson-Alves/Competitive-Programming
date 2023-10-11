#include <bits/stdc++.h>
using namespace std;
// #define ll long long
// #define debug(x) cerr << #x << " = " << x << '\n'

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n, s, t;
        cin >> n >> s >> t;
        int p[n];
        for (int &x : p)
                cin >> x;
        set<int> st;
        int pos = s-1, ans = 0;
        while (pos != t-1 && st.find(pos) == st.end())
                st.insert(pos), pos = p[pos]-1, ans++;
        cout << (pos == t-1 ? ans : -1) << '\n';

        return 0;
}