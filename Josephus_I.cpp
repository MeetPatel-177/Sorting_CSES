/**
 *    author:  Meet
 *    created: 03.11.2025 15:04:35
**/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 4e18;
const ll MINF = -4e18;
const ll M = 1e9 + 7;
//const ll M = 998244353;
const ll M1 = 111053273;
const ll M2 = 4011052531;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define minus cout << -1 << "\n"

vector<ll> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n;
    cin >> n;
    
    deque<ll> q;

    for(ll i=1; i<=n; ++i) q.push_back(i);
    while(!q.empty()) {
        ll curr = q.front(); q.pop_front();
        //this will not pop out in this round so push it to the back so we can consider it for the next round
        q.push_back(curr);

        ll will_remove = q.front(); q.pop_front();
        cout << will_remove << " ";
    }

    cout << "\n";
    return 0;
}