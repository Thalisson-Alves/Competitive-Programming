#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int grid[3][3];
    //bool visited[3][3] = {false};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> ans(3, vector<int>(3));
    int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    auto inside = [](int i, int j){ return i >= 0 && i < 3 &&  j >= 0 && j < 3;};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            ans[i][j] += !(grid[i][j] % 2);
            for(auto dir: directions){
                int row = i+dir[0];
                int col = j+dir[1];
                if(inside(row, col)){
                    ans[row][col] += (grid[i][j] % 2);
                }
            }
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; ++j){
            cout << ans[i][j] % 2;
        }
        cout << endl;
    }

    return 0;
}
