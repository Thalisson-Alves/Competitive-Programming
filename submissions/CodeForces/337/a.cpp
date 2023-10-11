#include <bits/stdc++.h>

using namespace std;

void solve(int f[], int tam, int n)
{
    sort(f, f+tam);
    int resp = f[tam-1] - f[0];
    for (int i = 0; i <= tam-n; i++){
        if ((f[i+n-1] - f[i]) < resp)
            resp = f[i+n-1] - f[i];
    }
    cout << resp;
}

int main (int argc, char* argv[])
{
    int n, m;
    cin >> n >> m;
    int f[m];
    for (int i = 0; i < m; i++){
        cin >> f[i];
    }
    solve(f, m, n);

    return 0;
}
