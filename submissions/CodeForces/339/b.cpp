#include <bits/stdc++.h>
using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    long long prev = 1;
    long long ans = 0;
    for(long long i =0 ; i < m; i++){
        long long task;
        cin >> task;
        if(task > prev){
            ans += task - prev;
        }else if (prev > task){
            ans += (n - prev + task);
        }
        prev = task;
    }

    cout << ans << endl;

    return 0;
}
