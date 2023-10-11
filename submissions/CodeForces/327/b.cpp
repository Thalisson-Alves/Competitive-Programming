#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = 2, prime = 3;
	function<bool(int)> is_prime = [ans](int a){
        for(int i = ans; i*i<=a; i++)
            if(a%i == 0)
                return false;
        return true;
	};
	for(int c = 0; c < n; prime++){
        if(is_prime(prime))
            cout << ans << ' ', ans = prime, c++;
	}

	return 0;
}
