#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int a[n];
	for(int &x: a)
		cin >> x;
	int l=0, r=0;
	for(int i=1; i<n; i++)
		if(a[i] < a[i-1] && !l)
			l = i;
		else if(a[i] > a[i-1] && r < l)
			r = i;
	l = (!l? 1: l);
	r = (!r? n: r);
	vector<int> vt(a, a+n);
	sort(vt.begin(), vt.end());
	bool ans = true, equal = true;
	for(int i=0, k=0; i<n; i++){
		if(l <= i+1 && i+1 <= r){
			if(a[(r-1-k++)] != vt[i]){
				ans = false;
			}
		}
		else if (a[i] != vt[i]){
			ans = false;
		}
		if(a[i] != vt[i])
			equal = false;
	}
	if(ans)
		cout << "yes\n" << l << ' ' << r << endl;
	else if(equal)
		cout << "yes\n1 1\n";
	else
		cout << "no\n";
	
	return 0;
}