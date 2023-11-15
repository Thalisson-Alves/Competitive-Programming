#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n;
	cin >> n;
	string ans = "No";
	for(int i=1; i <= 9; i++)
		for(int j = 1; j <= 9; j++)
			if(i*j == n){
				ans = "Yes";
				goto fim;
			}
	fim:
		cout << ans << endl;

    return 0;
}