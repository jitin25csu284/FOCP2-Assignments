#include <bits/stdc++.h>
using namespace std;
string solve(int n, vector<int>& a) {
    sort(a.begin(), a.end(), greater<int>());
    long long alex = 0, bob = 0;
    set<int> seenAlex, seenBob;
    int turn = 0;
    for (int i = 0; i < n; i++) {
        if (turn == 0) {
            if (!seenAlex.count(a[i])) {
                alex += a[i];
                seenAlex.insert(a[i]);
            }
            turn = 1;
        } else {
            if (!seenBob.count(a[i])) {
                bob += a[i];
                seenBob.insert(a[i]);
            }
            turn = 0; 
        }
    }  
    return alex > bob ? "Alex" : "Bob";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve(n, a) << "\n";
    }
    return 0;
}
