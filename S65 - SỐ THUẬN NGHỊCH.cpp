#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int n = s.size();
		s = " " + s;
		int F[n+1][n+1]; // F[i][j] = 1 s[i..j] thuan nghich
		memset(F, 0, sizeof(F));
		for(int i =1; i <=n; i++) F[i][i] = 1;
		int res = 1;
		for(int len =2; len <=n; len++){
			for(int i =n-len+1; i >=1; i--){
				int j = i + len - 1;
				if(s[i] == s[j]){
					if(len == 2 || (F[i+1][j-1] == 1)){
						F[i][j] = 1;
						res = max(res, j - i + 1);
					}
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}