#include <bits/stdc++.h>
using namespace std;

#define deb(x) (cerr << #x << " -> " << x << endl)

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, k;
	cin >> n >> k;
	if(k <= n/2 + n%2){
		cout << k*2-1 << endl;
	}
	else{
		cout << 2*(k-n/2-n%2) << endl;
	}

    return 0;
}
