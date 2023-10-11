#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool is_prime(long long a)
{
	if(a < 2) return false;
    for(long long i = 2; i*i <= a; i++)
        if(a % i == 0)
            return false;
    return true;
}

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;
        long long sq = round(sqrt(x));
        if(sq*sq == x && is_prime(sq))
            cout << "YES\n";
        else
            cout << "NO\n";
   }

    return 0;
}