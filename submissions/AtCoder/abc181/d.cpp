#include <bits/stdc++.h>
using namespace std;

string solve(const string &s)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        for (size_t j = 0; j < s.size(); j++)
        {
            for (size_t k = 0; k < s.size(); k++)
            {
                if (i == j || i == k || j == k)
                    continue;
                if (((s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0')) % 8 == 0)
                    return "Yes";
            }
        }
    }
    return "No";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    if (s.size() == 1)
    {
        cout << ((s[0] - '0') % 8 ? "No" : "Yes") << '\n';
        return 0;
    }
    else if (s.size() == 2)
    {
        cout << ((((s[0] - '0') * 10 + (s[1] - '0')) % 8) && (((s[1] - '0') * 10 + (s[0] - '0')) % 8) ? "No" : "Yes") << '\n';
        return 0;
    }
    vector<int> vs(10);
    for (char c : s)
        vs[c - '0']++;
    s = "";
    for (int i = 0; i < 10; i++)
        s += string(min(vs[i], 3), i + '0');
    cout << solve(s) << '\n';

    return 0;
}
