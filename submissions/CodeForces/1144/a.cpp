#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    int n;
    cin >> n;
    bool c;
    while(n--){
        string x;
        cin >> x;
        int maior = x[0], menor = x[0];
        for (int i = 0; i < x.size(); i++){
            int num = x[i];
            for (int j = i+1; j < x.size(); j++){
                int num2 = x[j];
                if (i == 0){
                    if (x[j] > maior)
                        maior = x[j];
                    if (x[j] < menor)
                        menor = x[j];
                }
                if (x[i] == x[j]){
                    c = false;
                    goto finished;
                }
                else
                    c = true;
            }
            if (maior - menor > x.size() - 1){
                c = false;
                break;
            }
            else
                c = true;
        }
        finished:
            if (c)
                cout << "Yes\n";
            else
                cout << "No\n";
    }

    return 0;
}
