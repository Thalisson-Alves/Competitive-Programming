#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, b, p;
	cin >> n >> b >> p;
	int bm = b*2+1, pm = p*n;
	ll matches = 0, rnd = n/2, player = n;
	while(player > 1){
		matches += rnd;
		player -= rnd;
		rnd = player / 2;
	}
	cout << bm*matches << " " << pm << endl;
	
	return 0;
}