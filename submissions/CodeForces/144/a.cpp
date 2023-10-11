#include <bits/stdc++.h>

using namespace std;

int solve(int bigger, int smaller, int n)
{
    return (bigger > smaller)? (bigger + n-2-smaller): (bigger+ n-1-smaller);
}

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int smaller = 0, bigger = 0;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        smaller = (a[smaller] >= a[i])? i: smaller;
        bigger = (a[bigger] < a[i])? i: bigger;
    }

    auto ans = solve(bigger, smaller, n);
    cout << ans << endl;

    return 0;
}
