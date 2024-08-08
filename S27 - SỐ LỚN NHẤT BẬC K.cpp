// SỐ LỚN NHẤT BẬC K

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int k; string s; cin >> k >> s;
        int n = s.size();
        s = " " + s;
        for(int i =1; i <n; i++){
            if(k == 0) break;
            int tmp = s[i];
            int res = i;
            for(int j =i+1; j <=n; j++){
                if(s[j] >= tmp){
                    tmp = s[j];
                    res = j;
                }
            }
            if(tmp != s[i]){
                swap(s[i], s[res]);
                k--;
            }
        }
        for(int i =1; i <=n; i++) cout << s[i];
        cout << endl;
    }
    return 0;
}