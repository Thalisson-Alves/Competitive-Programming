#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int a, b;
	cin >> a >> b;
	if(a >= 1 && a <= 9 && b >= 1 && b <= 9)
		cout << a*b << endl;
	else
		cout << -1 << endl;

    return 0;
}