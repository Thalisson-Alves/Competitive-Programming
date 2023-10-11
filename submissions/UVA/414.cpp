#include <bits/stdc++.h>

using namespace std;

void solveC()
{
    int n;
    cin >> n;
    while(n--){
        int f;
        cin >> f;
        int fa[3];
        long long ans = 0, multiplaier = 1;
        for(int j = 0; j < f; j++){
            multiplaier = 1;
            for (int i = 0; i < 3; i++){
                cin >> fa[i];
                multiplaier *= fa[i];
            }
            ans += multiplaier;
        }
        cout << ans << endl;
    }
}

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 1;
    while(true){
        cin >> n; cin.ignore();
        if (n == 0)
            break;

        string line;
        int most_x = 0, ans = 0, xs[n] = {0};
        for(int i = 0; i < n; i++){
            getline(cin, line);
            for(int j = 0; j < 25; j++){
                if (line[j] == 'X')
                    xs[i]++;
            }
            most_x = max(xs[i], most_x);
        }
        for(int i = 0; i < n; i++){
            ans += most_x - xs[i];
        }
        cout << ans << endl;
    }

    return 0;
}
