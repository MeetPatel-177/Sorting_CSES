/**
 *    author:  Meet
 *    created: 29.10.2025 17:01:34
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
        
        for(ll i=0; i<n; ++i) arr[i] = arr[i]*M + i;

        sort(whole(arr));

        bool found = 0;

        ll i = 0, j = n-1;
        while(i < j) {
            ll v1 = arr[i]/M, v2 = arr[j]/M;
            if((v1 + v2) == x) {
                found = 1;
                ll i1 = arr[i]%M, i2 = arr[j]%M;
                cout << i1+1 << " " << i2+1 << "\n";
                break;
            }
            else if((v1 + v2) > x) --j;
            else ++i;
        }

        if(!found) cout << "IMPOSSIBLE\n";
    }
    return 0;
}