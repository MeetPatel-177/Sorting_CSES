/**
 *    author:  Meet
 *    created: 30.10.2025 12:25:01
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

vector<ll> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        arr.assign(n,0);
        for(ll i=0; i<n; ++i) cin >> arr[i];
        
        sort(whole(arr));
        //all sums from 1 to reach are achievable
        ll reach = 0;
        for(ll i=0; i<n; ++i) {
            if((reach+1) >= arr[i]) {
                reach += arr[i];
            }else {
                break;
            }
        }

        ll ans = reach+1;
        cout << ans << "\n";
    }
    return 0;
}