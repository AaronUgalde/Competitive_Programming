#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s;

    queue<int> R, D;
    for(int i = 0; i < n; i++){
        if(s[i] == 'R') R.emplace(i);
        else D.emplace(i);
    }

    while(!R.empty() and !D.empty()){
        if(R.front() < D.front()){
            D.pop();
            R.emplace(R.front() + n);
            R.pop();
        }else{
            R.pop();
            D.emplace(D.front() + n);
            D.pop();
        }
    }

    if(!R.empty()) cout << "R" << endl;
    else if(!D.empty()) cout << "D" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}