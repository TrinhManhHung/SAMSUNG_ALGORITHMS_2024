// PHÉP CỘNG

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    cin.ignore();
    while(t--){
        string s; getline(cin, s);
        s = " " + s;
        int tmp1 = s[1] - '0' + s[5] - '0';
        int tmp2 = s[9] - '0';
        if(tmp1 == tmp2){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}