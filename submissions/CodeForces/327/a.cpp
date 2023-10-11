#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n;
	cin >> n;
	int ans = 0, zeros=0, ones=0;
	for(int i=0, x; i<n; i++){
		cin >> x;
		if(x == 1)
			zeros--, ones++;
		else
			zeros++;
		if(zeros < 0) zeros = 0;
		ans = max(ans, zeros);
	}
	cout << (ones==n? ones-1: ans+ones) << endl;
	
	return 0;
}