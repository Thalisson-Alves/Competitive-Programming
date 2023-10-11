#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    for (int i = 0; i < n; i++)
    {
        // print i + 1 open in a row
        for (int j = 0; j < i + 1; j++)
            cout << "(";
        // print i + 1 closed in a row
        for (int j = 0; j < i + 1; j++)
            cout << ")";
        // print the rest
        for (int j = 0; j < n - i - 1; j++)
            cout << "()";
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}
