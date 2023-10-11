#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string n;
	cin >> n;
	int ans = 0;
	function<string(string s)> sum_digits = [](const string &s) -> string {
		int sum = 0;
		for(char c: s)
			sum += c-'0';
		return to_string(sum);
	};
	while(n.length() > 1){
		ans++;
		n = sum_digits(n);
	}

	cout << ans << endl;

	return 0;
}