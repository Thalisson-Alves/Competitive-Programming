#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string enc;
    while(cin >> enc){
        cin.ignore();

        string ori;
        cin >> ori;
        cin.ignore();

        int test_ori[28] = {0}, test_enc[28] = {0};
        bool verify = false;
        int n = 28, tamanho = (int) enc.size();

        for(int i = 0; i < tamanho; i++){
            test_enc[enc[i] - 65]++;
        }
        for(int i = 0; i < tamanho; i++){
            test_ori[ori[i] - 65]++;
        }
        sort(test_enc, test_enc+n);
        sort(test_ori, test_ori+n);

        for(int i = n-1; i >= 0; i--){
            if (test_enc[i] != test_ori[i]){
                verify = false;
                break;
            }else{
                verify = true;
            }
            if (test_enc[i] == 0 || test_ori[i] == 0)
                break;
        }
        if(verify)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
