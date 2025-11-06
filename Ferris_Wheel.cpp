/**
 *    author:  Meet
 *    created: 28.10.2025 16:55:56
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
        ll n, x;
        cin >> n >> x;
        arr.assign(n,0);
        for(ll i=0; i<n; ++i) cin >> arr[i];
        
        sort(whole(arr));

        ll ans = 0;

        ll i = 0, j = n-1;
        while(i <= j) {
            while(i <= j && (arr[i] + arr[j]) > x) {
                ++ans;
                --j;
            }
            if(i <= j) ++ans;
            ++i;
            --j;
        }

        cout << ans << "\n";
    }
    return 0;
}