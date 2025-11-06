/**
 *    author:  Meet
 *    created: 04.11.2025 22:01:00
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long int
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// order_of_key(k) : no. of elements < k
// *find_by_order(i) : value at index i (0-based)

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
        ll n,x;
        cin >> n >> x;
        arr.assign(n,0);
        for(ll i=0; i<n; ++i) cin >> arr[i];

        for(ll i=0; i<n; ++i) arr[i] = arr[i]*M + i;
        sort(whole(arr));

        ll a,b,c;
        a = b = c = -1;
        bool found = 0;

        for(ll i=0; i<n-2; ++i) {
            if(i > 0 && arr[i]/M == arr[i-1]/M) continue;

            ll l = i+1, r = n-1;

            while(l < r) {
                ll sum = arr[i]/M + arr[l]/M + arr[r]/M;
                if(sum == x) {
                    a = arr[i]%M, b = arr[l]%M, c = arr[r]%M;
                    found = 1;
                    break;    
                }
                else if(sum > x) --r;
                else ++l;
            }
        }


        if(found) cout << a+1 << " " << b+1 << " " << c+1 << "\n";
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}