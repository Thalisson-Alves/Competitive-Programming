#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i <= 2*n; i++){
		for(int spaces = 0; spaces < abs(n-i); spaces++)
			cout << "  ";
		int num = 0;
		if(i <= n)
			for(num = 0; num <= i; num++){
				cout << num << (i? ' ': '\n');
			}
		else
			for(num = 0; num <= n-(i-n); num++)
				cout << num << (i!=2*n? ' ': '\n');
		num--;
		while(--num >= 0)
			cout << num << (num? ' ': '\n');
	}
	
	return 0;
}
