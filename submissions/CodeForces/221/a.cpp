#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cout << (i==1? n: i-1) << ' ';
	cout << endl;

    return 0;
}
