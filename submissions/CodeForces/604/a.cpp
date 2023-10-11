#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t[5], w[5], h[2];

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for(int i = 0; i < 5; i++)
        cin >> t[i];
    for(int i = 0; i < 5; i++)
        cin >> w[i];
    cin >> h[0] >> h[1];
    double ans = 0;
    for(int i = 0, x = 500; i < 5; i++, x+=500){
        ans += max(0.3f*x, (1- t[i]/250.0f)*x-50*w[i]);
    }
    ans = round(ans) + 100*h[0] - 50*h[1];
    cout << ans << endl;

	return 0;
}
