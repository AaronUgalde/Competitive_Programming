#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int n, k; cin >> n >> k;
    vector<int> cards(n);
    for(auto &card : cards)
        cin >> card;

    sort(cards.begin(), cards.end());

    int maxNumberOfCards = 0;
    for(int i = 0, j = 0; i < n; i++){
        j = max(i, j);
        while(j < n && cards[j] - cards[i] < k && (i == j || cards[j] - cards[j-1] <= 1))
            j++;
        
        maxNumberOfCards = max(maxNumberOfCards, j - i);
    }

    cout << maxNumberOfCards << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}