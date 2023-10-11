#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n, m;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> n >> m;
	if(n > m){
		out << 'B';
		while(m--)
			out << "GB", n--;
		while(--n)
			out << 'B';
	}else{
		if(m > n)
			out << 'G', m--;
		while(n--)
			out << "BG", m--;
		while(m--)
			out << 'G';
	}
	out << endl;
	
	return 0;
}