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
        vector< pair<int, int> > color;
        while(n--){
            int c;
            cin >> c;
            if(c < 0)
                color.push_back(make_pair(abs(c), -1));
            else
                color.push_back(make_pair(c, 1));
        }
        sort(color.begin(), color.end());

        int ans = 1, tamanho = (int)color.size();
        int prev_color = color[tamanho-1].second, prev = color[tamanho-1].first;
        for(int i = tamanho-2; i >= 0; --i){
            if(prev_color != color[i].second && color[i].first < prev){
                prev_color = color[i].second;
                prev = color[i].first;
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
