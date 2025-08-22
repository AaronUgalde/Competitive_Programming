#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int n, d; cin >> n >> d;
    string boxes; cin >> boxes;
    int numberOfCookies = 0;
    for(auto &box : boxes){
        if(box == '@') numberOfCookies++;
    }

    numberOfCookies -= d;
    for(auto &box : boxes){
        if(box == '@'){
            if(numberOfCookies){
                cout << '@';
                numberOfCookies--;
            }else{
                cout << '.';
            }
        }else{
            cout << '.';
        }
    }

    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}