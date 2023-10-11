#include <bits/stdc++.h>
using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int lift[n], land[n];
    for(int i = 0; i < n; i++)
        cin >> lift[i];
    for(int i = 0; i < n; i++)
        cin >> land[i];

    double l = 0, r = 2e9;
    while(abs(r-l) > 1e-8){
        double mid = l+(r-l)/2.0;
        double fuel = mid;
        for(int i = 0; i < n; i++){
            fuel -= (fuel+m)/lift[i];
            fuel -= (fuel+m)/land[(i+1)%n];
        }
        if(fuel > 0)
            r = mid;
        else
            l = mid;
    }
    if(r > 1e9+1000)
        cout << -1 << endl;
    else
        cout << fixed << setprecision(10) << r << endl;

    return 0;
}
