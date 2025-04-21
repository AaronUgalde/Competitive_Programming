#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int q; cin >> q;
    queue<int> line;
    for(int i = 0; i<q; i++){
        int operation; cin >> operation;
        if(operation == 1){
            int menu; cin >> menu;
            line.push(menu);
        }else{
            cout << line.front() << '\n';
            line.pop();
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}