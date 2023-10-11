#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x, y;
	cin >> n >> x >> y;
	int people = ceil(n*y/100.0);
	cout << (x >= people? 0: people-x) << endl;

	return 0;
}