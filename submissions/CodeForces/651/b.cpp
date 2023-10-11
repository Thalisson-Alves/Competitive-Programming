#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n;
	cin >> n;
	map<int, int> mp;
	for(int i=0, b; i<n; i++)
		cin >> b, mp[b]++;
	int ans = 0;
	int tmp;
	do{
		tmp = 0;
		for(auto it = mp.begin(); it != mp.end(); it++){
			tmp += (it->second-- > 0? 1: 0);
		}
		ans += tmp? tmp-1: 0;
	}while(tmp != 0);
	cout << ans << endl;

	return 0;
}