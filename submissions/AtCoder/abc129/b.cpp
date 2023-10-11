#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    int n;
    cin >> n;
    int a[n], sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    int s[2] = {0}, t = sum / 2, ti = 1, dist = INT_MAX;
    sum = 0;
    for (int i = 0; i < n; i++){
        sum += a[i];
        if (abs(sum - t) < dist){
            dist = abs(sum - t);
            ti = i;
        }
    }

    for(int i = 0; i < n; i++){
        if (i > ti)
            s[0] += a[i];
        else
            s[1] += a[i];
    }

    cout << abs(s[0] - s[1]) << endl;

    return 0;
}