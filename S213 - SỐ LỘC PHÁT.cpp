// SỐ LỘC PHÁT

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> v;
        queue<string> Q;
        Q.push("6");
        Q.push("8");
        while(1){
            string top = Q.front();
            if(top.size() == n) break;
            Q.pop();
            v.push_back(top);
            Q.push(top + "6");
            Q.push(top + "8");
        }
        while(!Q.empty()){
            string top = Q.front(); Q.pop();
            v.push_back(top);
        }
        cout << v.size() << endl;
        for(int i =v.size()-1; i >=0; i--){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}