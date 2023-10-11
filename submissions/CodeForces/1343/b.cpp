#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if ((n/2)%2){
            cout << "NO" << endl;
            continue;
        }
        else{
            cout << "YES\n";
            int c=0;
            for(int e = 2, o = 1; c < n; c++){
                if (c < n/2){
                    cout << e << " ";
                    e += 2;
                }
                else{
                    cout << o;
                    o += 2;
                    if (c == n-2)
                        o += n/2;
                    if (c == n-1)
                        cout << endl;
                    else
                        cout << " ";
                }
            }
        }
    }

    return 0;
}
