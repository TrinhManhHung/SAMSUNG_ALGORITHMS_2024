//XÂU NHỊ PHÂN TRƯỚC
#include<bits/stdc++.h>
using namespace std;

void Solve(){
	string s; cin >> s;
	int n = s.size();
	s = " " + s;
	int idx = n;
	while(idx >= 1 && s[idx] == '0'){
		s[idx] = '1';
		idx--;
	}
	if(idx >= 1){
		s[idx] = '0';
	}
	for(int i=1; i<=n; i++) cout << s[i];
	cout << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		Solve();
	}
	return 0;
}
