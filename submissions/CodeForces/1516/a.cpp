#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        for (int i = 0; i < int(a.size()) && k; i++)
        {
            int s = min(a[i], k);
            a[i] -= s;
            a.back() += s;
            k -= s;
        }
        for (int i = 0; i < (int)a.size(); i++)
            cout << a[i] << " \n"[i == int(a.size()-1)];
    }


    return 0;
}
