#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }
        vector<int> ans;
        for (auto it = mp.begin(); it != mp.end(); it++)
            ans.push_back(it->first), it->second--;
        for (auto it = mp.begin(); it != mp.end(); it++)
            while (it->second--)
                ans.push_back(it->first);
        for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n-1];
    }

    return 0;
}
