#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void printvec(vector<int> v){
    for(int i = 0; i<v.size(); i++){
        cout << i << ':' << v[i] << ' ';
    }
    cout << endl;
}


void solve(int testcase){
    int n, w; cin >> n >> w;
    vector<vector<pair<int, int>>> columns(w);
    for(int i = 0; i<n; i++){
        int x, y; cin >> x >> y; x--; y--;
        columns[x].emplace_back(y, i);
    }

    vector<int> cube_row(n);
    int min_size = INT_MIN;
    for(int i = 0; i<w; i++){
        sort(all(columns[i]));
        for(int j = 0; j<columns[i].size(); j++){
            cube_row[columns[i][j].second] = j;
        }
        min_size = max(min_size, (int)columns[i].size());
    }

    vector<int> row_maxTime(min_size, INT_MIN);
    vector<bool> is_infinite(min_size, false);
    for(int i = 0; i<w; i++){
        int j = 0;
        for(; j<columns[i].size(); j++){
            row_maxTime[j] = max(row_maxTime[j], columns[i][j].first);
        }
        if(j < min_size) is_infinite[j] = true;
    }

    for (int j = 1; j < min_size; j++) {
        row_maxTime[j] = max(row_maxTime[j], row_maxTime[j - 1] + 1);
        is_infinite[j] = is_infinite[j] || is_infinite[j - 1];
    }

    int q; cin >> q;
    for(int i = 0; i<q; i++){
        int time, cube; cin >> time >> cube;
        cube--; time--;
        if(row_maxTime[cube_row[cube]] > time || is_infinite[cube_row[cube]]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
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