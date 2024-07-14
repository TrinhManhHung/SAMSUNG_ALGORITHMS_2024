//Hoan vi nguoc
#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s = "";
		for(int i=1; i<=n; i++) s += (i+'0');
		vector<string> res;
		do{
			res.pb(s);
		}while(next_permutation(s.begin(), s.end()));
		reverse(res.begin(), res.end());
		for(auto x : res){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
