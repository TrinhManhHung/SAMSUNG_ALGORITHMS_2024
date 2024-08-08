// BIẾN ĐỔI TRUNG TỐ - HẬU TỐ

#include <bits/stdc++.h>
using namespace std;

int uutien(char c){
	if(c == '^') return 3;
	else if(c == '*' || c == '/') return 2;
	else if(c == '+' || c == '-') return 1;
	return 0;
}
void solve(){
	string s; cin >> s;
	string res = "";
	stack<char> st;
	for(auto x : s){
		if(isalpha(x)) 
			res += x;
		else if(x == '('){
			st.push(x);
		}
		else if(x == ')'){
			while(!st.empty() && st.top() != '('){
				res += st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			while(!st.empty() && uutien(st.top()) >= uutien(x)){
				res += st.top();
				st.pop();
			}
			st.push(x);
		}
	}
	while(!st.empty()){
		res += st.top();
		st.pop();
	}
	cout << res << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}