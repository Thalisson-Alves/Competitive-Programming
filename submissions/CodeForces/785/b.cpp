#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int left = 1e9+7;
	int right = -1;
	for(int i = 0; i < n; i++){
		int l, r;
		cin >> l >> r;
		left = min(r, left);
		right = max(right, l);
	}
	int m;
	cin >> m;
	int _left = 1e9+7;
	int _right = -1;
	for(int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		_left = min(r, _left);
		_right = max(_right, l);
	}
	int ans = max(right-_left, _right-left);
	cout << (ans < 0? 0: ans) << '\n';
	
	return 0;
}