#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	
	int ans = 0;
	bool open[n];
	memset(open, 0, sizeof(open));
	for(int i = 0; i < n; i++){
		for(int j = (i+1)%n; j != i; j=(j+1)%n){
			if(!open[j] && a[i].second == a[j].first){
				ans++;
				open[j] = true;
			}
		}
	}
	
	cout << n-ans << endl;
	
	return 0;
}