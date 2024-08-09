#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(){
	faster();
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n+1];
		for(int i =1; i <=n; i++) cin >> a[i];
		stack<int> st;
		for(int i =1; i <=n; i++){
			while(!st.empty() && a[st.top()] <= a[i]){
				st.pop();
			}
			if(st.empty()) cout << i << " ";
			else cout << i - st.top() << " ";
			st.push(i);
		}
		cout << "\n";
	}
	return 0;
}
