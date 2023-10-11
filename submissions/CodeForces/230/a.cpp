#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int s, n;
	cin >> s >> n;
	vector<pair<int, int>> d(n);
	for(pair<int, int> &x: d)
		cin >> x.first >> x.second;
	sort(d.begin(), d.end());
	string ans = "YES";
	for(pair<int, int> &x: d){
		if(s > x.first)
			s += x.second;
		else{
			ans = "NO";
			break;
		}
	}
	cout << ans << endl;
	
	return 0;
}
