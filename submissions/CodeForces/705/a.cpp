#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	int i = 0;
	string f[2] = {"hate", "love"};
	for(i = 0; i < n-1; i++)
        cout << "I " << f[i%2] << " that ";
    cout << "I " << f[i%2] << " it\n";
}

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //int t;
    //cin >> t;
    //while(t--)
        solve();

    return 0;
}

