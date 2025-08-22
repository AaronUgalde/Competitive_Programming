#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> A(2*n);
    for(int i = 0; i<2*n; i++){
        int x; cin >> x; x--;
        A[i] = x;
    }

    vector<vector<int>> positions(n);
    for(int i = 0; i<2*n; i++){
        positions[A[i]].push_back(i);
    }

    set<pair<int, int>> answers;
    for(int i = 0; i+1<2*n; i++){
        int a = A[i], b = A[i + 1];
        if(positions[a][0] + 1 == positions[a][1]) continue;
        if(positions[b][0] + 1 == positions[b][1]) continue;
        vector<int> v{positions[a][0], positions[a][1], positions[b][0], positions[b][1]};
        sort(all(v));
        if(v[0] + 1 == v[1] && v[2] + 1 && v[3]) answers.emplace(minmax(a, b));
    }

    cout << answers.size() << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}