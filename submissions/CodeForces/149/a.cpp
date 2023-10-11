#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int k;
	cin >> k;
	int a[12];
	for(int i = 0; i < 12; i++){
		cin >> a[i];
	}
	sort(a, a+12);
	int ans = 0;
	if(!k)
		cout << ans << endl;
	else{
		for(int i = 11; i >= 0 && k > 0; i--){
			k-=a[i];
			ans ++;
		}
		if(k <= 0)
			cout << ans << endl;
		else
			cout << -1 << endl;
	}

    return 0;
}