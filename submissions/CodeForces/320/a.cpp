#include <bits/stdc++.h>
using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string magic;
	cin >> magic;
	int fs = 0;
	int n = magic.length();
	string ans = "YES";
	for(int i = 0; i < n; i++){
		fs = (magic[i] == '4'? fs+1: 0); 
		if((i == 0 && magic[i] == '4') || (magic[i] != '4' && magic[i] != '1') || (fs > 2)){
			ans = "NO";
			break;
		}
	}
	cout << ans << endl;

    return 0;
}