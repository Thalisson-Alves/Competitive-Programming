#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.size();
	ll ans = 0;
	for(int i=0; i < n; i++){
		int x = s[i];
		if(x%4==0)
			ans++;
		if(i){
			int y = s[i-1];
			y = y*10 + x;
			if(y %4 == 0)
				ans+=i;
		}
	}
	cout << ans << endl;

	return 0;
}
