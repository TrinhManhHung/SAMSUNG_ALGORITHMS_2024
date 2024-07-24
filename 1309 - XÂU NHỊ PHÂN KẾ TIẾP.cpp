//XÂU NHỊ PHÂN KẾ TIẾP

#include<bits/stdc++.h>
using namespace std;

void Solve(){
	string s; cin >> s;
	int idx = s.size()-1;
	while(idx >= 0 && s[idx] == '1'){
		s[idx] = '0';
		idx--;
		
	}
	if(idx >= 0) s[idx] = '1';
	cout << s << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		Solve();
	}
	return 0;
}
