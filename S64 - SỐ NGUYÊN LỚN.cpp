#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(1e9 + 7)
#define pb push_back
int main(){
	int t; cin >> t;
	while(t--){
		string s1, s2; cin >> s1 >> s2;
		int n = s1.size(), m = s2.size();
		s1 = " " + s1; s2 = " " + s2;
		
		int F[n+1][m+1]; //F[i][j] Xau con chung dai nhat tinh den s1[i] va s2[j]
		memset(F, 0, sizeof(F));
		for(int i =1; i <=n; i++){
			for(int j =1; j <=m; j++){
				if(s1[i] == s2[j]){
					F[i][j] = F[i-1][j-1] + 1;
				}
				else F[i][j] = max(F[i-1][j], F[i][j-1]);
			}
		}
		cout << F[n][m] << endl;
	} 
	return 0;
}
