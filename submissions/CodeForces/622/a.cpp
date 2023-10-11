#include <bits/stdc++.h>

long long solve(long long n)
{
    long long pos = 1, high = 1;
    while(true){
        if(n == pos)
            return high;
        if(n > pos + high){
            high++;
            pos = pos+high;
        }else{
            return n-pos;
        }
    }
}

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;
    long long ans = solve(n);
    cout << ans << endl;

    return 0;
}
