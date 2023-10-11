#include <bits/stdc++.h>
using namespace std;
#define ll long long

int gcd(int a, int b){return b? gcd(b, a%b): a;}

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	map<int, int> mp;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		mp[x]++;
	}
	if(mp[1] == n/3 && mp[2] == mp[4] + (mp[6] - mp[3]) && mp[4] <= mp[2] && mp[3] <= mp[6] && !mp[5] && !mp[7]){
		for(int i = 0; i < n/3; i++)
			if(mp[2] && mp[4]){
				cout << "1 2 4\n";
				mp[2] -= (mp[2]? 1: 0);
				mp[4] -= (mp[4]? 1: 0);
			}
			else if(mp[2] && mp[6]){
				cout << "1 2 6\n";
				mp[2] -= (mp[2]? 1: 0);
				mp[6] -= (mp[6]? 1: 0);
			}
			else if(mp[3] && mp[6]){
				cout << "1 3 6\n";
				mp[3] -= (mp[3]? 1: 0);
				mp[6] -= (mp[6]? 1: 0);
			}
	}
	else
		cout << -1 << endl;
	
	// 1 2 4
	// 1 2 6
	// 1 3 6
	
	return 0;
}