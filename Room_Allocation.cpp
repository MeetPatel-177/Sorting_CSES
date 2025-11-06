/**
 *    author:  Meet
 *    created: 03.11.2025 18:46:07
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
        ll a,d;
        cin >> a >> d;
        arr.push_back({a,1,i});
        arr.push_back({d,-1,i});
    }

    sort(whole(arr), [](auto& a, auto& b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    ll mx = 0;
    vector<ll> rooms(n,0);
    rooms[0] = 1;
    
    ll curr = 0;
    deque<ll> emptyRooms;
    for(auto& [time,type,ind] : arr) {
        curr += type;
        mx = max(mx, curr);

        if(type < 0) {
            emptyRooms.push_back(rooms[ind]);
        }else {
            if(emptyRooms.empty()) {
                rooms[ind] = curr;
            }else {
                rooms[ind] = emptyRooms.front();
                emptyRooms.pop_front();
            }
        }
    }

    cout << mx << "\n";
    for(ll i=0; i<n; ++i) cout << rooms[i] << " ";
    cout << "\n";
    return 0;
}