/**
 *    author:  Meet
 *    created: 03.11.2025 15:53:08
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

vector<array<ll,3>> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n;
    cin >> n;
    for(ll i=0; i<n; ++i) {
        ll a,b;
        cin >> a >> b;
        arr.push_back({a,b,i});
    }

    
    sort(whole(arr), [](auto& a, auto& b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    vector<bool> contained(n,0), contains(n,0);

    ll mxr = 0;
    for(ll i=0; i<n; ++i) {
        ll l = arr[i][0], r = arr[i][1], ind = arr[i][2];
        if(r <= mxr) {
            contained[ind] = 1;
        }
        mxr = max(mxr, r);
    }

    ll mnr = INF;
    for(ll i=n-1; i>=0; --i) {
        ll l = arr[i][0], r = arr[i][1], ind = arr[i][2];
        if(r >= mnr) {
            contains[ind] = 1;
        }
        mnr = min(mnr,r);
    }

    for(ll i=0; i<n; ++i) cout << contains[i] << " ";
    cout << "\n";
    for(ll i=0; i<n; ++i) cout << contained[i] << " ";
    cout << "\n";
    return 0;
}