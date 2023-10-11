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
	map<int, int> mp;
	int negative = 0, positive = 0;
	for(int &x: a)
		cin >> x, mp[x]++, negative += (mp[x] == 1 && x < 0? 1: 0), positive += (mp[x] == 1 && x > 0? 1: 0);
	set<int> first, second, third;
	function<int(set<int>, int)> less_than = [](set<int> st, int n) -> int {
		int count=0;
		for(auto it=st.begin(); it!=st.end(); it++)
			if(*it < n)
				count++;
			else
				return count;
		return count;
	};
	int neg_positive = (positive? 0: 2);
	for(auto it=mp.begin(); it!=mp.end(); it++){
		if(it->first == 0)
			third.insert(it->first);
		else if(it->second == 3)
			first.insert(it->first), second.insert(it->first), third.insert(it->first);
		else if(it->second == 2){
			if(it->first > 0)
				second.insert(it->first), third.insert(it->first);
			else{
				if(neg_positive)
					second.insert(it->first), third.insert(it->first), neg_positive--;
				else if(less_than(second, 0)%2){
					if(negative % 2)
						first.insert(it->first), second.insert(it->first);
					else
						second.insert(it->first), third.insert(it->first);
				}
				else{
					if(negative%2)
						first.insert(it->first), third.insert(it->first);
					else
						second.insert(it->first), third.insert(it->first);
				}
			}
		}
		else{
			if(it->first < 0){
				if(neg_positive && it->first < 0)
					second.insert(it->first), neg_positive--;
				else if(less_than(second, 0)%2)
					second.insert(it->first);
				else if(!(less_than(first, 0)%2))
					first.insert(it->first);
				else
					third.insert(it->first);
			}
			else
				second.insert(it->first);
		}
	}

	cout << first.size() << ' ';
	for(auto it=first.begin(); it!=first.end(); it++)
		cout << *it << ' ';
	cout << '\n' << second.size() << ' ';
	for(auto it=second.begin(); it!=second.end(); it++)
		cout << *it << ' ';
	cout << '\n' << third.size() << ' ';
	for(auto it=third.begin(); it!=third.end(); it++)
		cout << *it << ' ';

	return 0;
}