#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n, c;
	cin >> n >> c;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	int ans = 0;
	for(int i = 0; i < c; i++)
		if(a[i] < 0)
			ans += -a[i];
		else
			break;
		
	cout << ans << endl;

    return 0;
}