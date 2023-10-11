#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++)
        cin >> a[i];

    int comp = a[k-1];

    int ans = 0;
    for(int i = n-1; i >= 0; i--)
        if(a[i] != comp){
            ans = i+1;
            break;
        }

    if(ans < k)
        cout << ans << endl;
    else
        cout << -1 << endl;

	return 0;
}
