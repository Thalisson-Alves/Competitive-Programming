#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;cin.ignore();
    string q;
    cin >> q;
    while(t--){
        for(int i = 0; i < n-1; i++){
            if(q[i+1] == 'G' && q[i] == 'B'){
                swap(q[i+1], q[i]);
                ++i;
            }
        }
    }
    cout << q << endl;

    return 0;
}
