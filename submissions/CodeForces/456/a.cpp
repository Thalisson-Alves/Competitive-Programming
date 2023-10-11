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
	for(pair<int, int> &p: a)
		cin >> p.first >> p.second;
	sort(a.begin(), a.end());
	for(int i=1; i<n; i++)
		if(a[i-1].first < a[i].first && a[i-1].second > a[i].second){
			cout << "Happy Alex\n";
			return 0;
		}
	cout << "Poor Alex\n";

	return 0;
}