#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	string s[10] = {"zero", "one", "two", "three", "four", "five", "six",  "seven", "eight", "nine"};
	if(n >= 0 && n < 10)
		cout << s[n] << endl;
	else if(n < 20){
		if(n == 10)
			cout << "ten\n";
		if(n == 11)
			cout << "eleven\n";
		if(n == 12)
			cout << "twelve\n";
		if(n == 13)
			cout << "thirteen\n";
		if(n == 14)
			cout << "fourteen\n";
		if(n == 15)
			cout << "fifteen\n";
		if(n == 16)
			cout << "sixteen\n";
		if(n == 17)
			cout << "seventeen\n";
		if(n == 18)
			cout << "eighteen\n";
		if(n == 19)
			cout << "nineteen\n";
	}else if(n < 30){
		cout << "twenty";
		int temp = n%10;
		if(temp)
			cout << "-" << s[temp];
		cout << endl;
	}else if(n < 40){
		cout << "thirty";
		int temp = n%10;
		if(temp)
			cout << "-" << s[temp];
		cout << endl;
	}
	else if(n < 50){
		cout << "forty";
		int temp = n%10;
		if(temp)
			cout << "-" << s[temp];
		cout << endl;
	}else if(n < 60){
		cout << "fifty";
		int temp = n%10;
		if(temp)
			cout << "-" << s[temp];
		cout << endl;
	
	}else if(n < 70){
		cout << "sixty";
		int temp = n%10;
		if(temp)
			cout << "-" << s[temp];
		cout << endl;
	
	}else if(n < 80){
		cout << "seventy";
		int temp = n%10;
		if(temp)
			cout << "-" << s[temp];
		cout << endl;
	
	}else if(n < 90){
		cout << "eighty";
		int temp = n%10;
		if(temp)
			cout << "-" << s[temp];
		cout << endl;
	}else{
		cout << "ninety";
		int temp = n%10;
		if(temp)
			cout << "-" << s[temp];
		cout << endl;
	}
	
	return 0;
}