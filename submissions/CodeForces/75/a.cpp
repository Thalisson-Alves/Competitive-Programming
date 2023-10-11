#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	int c = a+b;
	function<int(int)> remove_zeros = [](int x){
		string no_zero, number;
		number = to_string(x);
		for(char c: number)
			if(c != '0')
				no_zero += c;
		return stoi(no_zero);
	};
	
	cout << (remove_zeros(a) + remove_zeros(b) == remove_zeros(c)? "YES\n": "NO\n");

	return 0;
}