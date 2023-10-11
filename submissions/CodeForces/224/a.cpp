#include <bits/stdc++.h>
using namespace std;

#define deb(x) (cerr << #x << " -> " << x << endl)

int mdc(int a, int b){ return b? mdc(b, a%b): a; }

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
	cin >> a >> b >> c;
	long l,h,w;
    l=sqrt((a/(double)b)*c);
    h=sqrt((a/(double)c)*b);
    w=sqrt((b/(double)a)*c);
    cout<<4*l+4*h+4*w;

    return 0;
}
