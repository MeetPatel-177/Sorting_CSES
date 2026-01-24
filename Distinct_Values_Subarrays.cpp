/**
 *    author:  Meet
 *    created: 24.01.2026 12:08:40
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// order_of_key(k) : no. of elements < k
// *find_by_order(i) : value at index i (0-based)

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
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        arr.assign(n,0);
        for(ll i=0; i<n; ++i) cin >> arr[i];
        
        ll ans = 0;

        map<ll,ll> f;
        ll l = 0, r = 0;

        ll plen = 0;

        while(r < n) {
            while(r < n && f[arr[r]] == 0) {
                ++f[arr[r]];
                ++r;
            }
            ll len = r - l;
            ans += (len*(len+1)/2);
            ans -= (plen*(plen+1)/2);
            while(r < n && f[arr[r]] != 0) {
                --f[arr[l]];
                ++l;
            }
            plen = r - l;
        }

        cout << ans << "\n";
    }
    return 0;
}