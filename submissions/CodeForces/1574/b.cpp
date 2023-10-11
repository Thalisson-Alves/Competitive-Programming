#include <bits/stdc++.h>
using namespace std;

void solve(const vector<int>& letters, int m)
{
    int lower_bound = max(0, letters.back() - (letters[0] + letters[1]) - 1);
    int upper_bound = accumulate(letters.begin(), letters.end(), 0) - 3;

    cout << (m <= upper_bound && m >= lower_bound ? "YES" : "NO") << "\n";
}

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--)
    {
        vector<int> letters(3);
        int m;
        for (auto &x: letters)
            cin >> x;
        cin >> m;
        sort(letters.begin(), letters.end());
        solve(letters, m);
    }

    return 0;
}
