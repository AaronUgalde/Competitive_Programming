#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> days(n);
    int not_know = 0;
    int know = 0;
    int empty = 0;
    int buyed = 0;
    for(auto &x : days){
        cin >> x;
        if(x == 1){
            if(empty) empty--;
            else buyed++;
            not_know++;
        }else{
            know += not_know;
            int needed = (know > 0 ? (know/2) + 1 : 0);
            empty = buyed - needed;                        
            not_know = 0;
        }
    }

    cout << buyed << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}