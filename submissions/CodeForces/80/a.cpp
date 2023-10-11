#include <bits/stdc++.h>

using namespace std;

bool prime(int n)
{
    for(int i = 2; i*i <= n; i++)
        if(!(n%i))
            return false;
    return true;
}

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    if(prime(a) && prime(b)){
        bool next_prime = true;
        for(int i = a+1; i < b; i++)
            if(prime(i))
                next_prime = false;
        if(next_prime)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
        cout << "NO\n";

    return 0;
}
