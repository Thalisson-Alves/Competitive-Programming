#include <bits/stdc++.h>
using namespace std;

bool all_gt1(const map<char, int> &mp)
{
    for (auto it = mp.begin(); it != mp.end(); it++)
        if (it->second <= 1)
            return false;
    return true;
}

bool any_gt1(const map<char, int> &mp)
{
    for (auto it = mp.begin(); it != mp.end(); it++)
        if (it->second > 1)
            return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto x : s) mp[x]++;
    switch (mp.size())
    {
    case 2:
        cout << (all_gt1(mp) ? "Yes" : "No") << '\n';
        break;
    case 3:
        cout << (any_gt1(mp) ? "Yes" : "No") << '\n';
        break;
    case 4:
        cout << "Yes\n";
        break;
    default:
        cout << "No\n";
    }

    return 0;
}
