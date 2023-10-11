#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    cin >> n;
    vector<int> cs(10);
    int sum = 0;
    for (char c : n)
    {
        cs[c - '0']++;
        sum += c - '0';
    }

    if (sum % 3 == 0)
    {
        cout << "0\n";
        return 0;
    }

    if (n.size() > 1)
        for (int i = 0; i < 10; i++)
        {
            for (int j = sum % 3; j < 9; j += 3)
            {
                if (!cs[j])
                    continue;
                if (cs[i] && (sum - i) % 3 == 0)
                {
                    cout << "1\n";
                    return 0;
                }
            }
        }

    if (n.size() > 2)
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
            {
                if ((k != i) && (!cs[k] || !cs[i]))
                    continue;
                if ((k == i) && cs[k] < 2)
                    continue;
                if ((sum - i - k) % 3 == 0)
                {
                    cout << "2\n";
                    return 0;
                }
            }

    cout << "-1\n";

    return 0;
}
