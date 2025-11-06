/**
 *    author:  Meet
 *    created: 29.10.2025 16:53:10
**/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll MINF = -1e18;
const ll M = 1e9 + 7;
//const ll M = 998244353;
const ll M1 = 111053273;
const ll M2 = 4011052531;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define minus cout << -1 << "\n"

vector<pair<ll,ll>> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        arr.assign(n,{});
        for(ll i=0; i<n; ++i) cin >> arr[i].first >> arr[i].second;
        
        sort(whole(arr), [](auto& p1, auto& p2) {
            return p1.second < p2.second;
        });

        ll ans = 0;

        ll prev = 0;
        for(ll i=0; i<n; ++i) {
            if(arr[i].first < prev) continue;
            ++ans;
            prev = arr[i].second;
        }

        cout << ans << "\n";
    }
    return 0;
}