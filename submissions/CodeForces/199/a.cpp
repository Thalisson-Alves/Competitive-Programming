#include <bits/stdc++.h>
using namespace std;

#define deb(x) (cerr << #x << " -> " << x << endl)

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	vector<int> a;
    int n;
	cin >> n;
	if(n == 0){
		cout << "0 0 0\n";
		return 0;
	}
	a.emplace_back(0);
	a.emplace_back(1);
	while(a[a.size()-1] != n){
		int v = a[a.size()-1] + a[a.size()-2];
		a.emplace_back(v);
	}
	
	if(n > 2)
		cout << a[a.size()-2] << " " << a[a.size()-4] << " " << a[a.size()-5] << endl;
	else{
		for(int i = 1; i <= 3; i++){
			if(i <= n)
				cout << "1 ";
			else
				cout << "0 ";
		}
		cout << endl;
	}

    return 0;
}