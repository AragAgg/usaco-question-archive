/* Binary search on the radius value r
 * For a given radius, binary search on the location to detonate a haybale
	* Two symmetric cases: detonate to the right or to the left
	* In the right case, binary search for the left-most haybale that can detonate all bales to its right
	* Check if this bale can also detonate all bales to its left
 * If so, we have a working radius value that explodes all bales!
 */

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> A;

bool works_right(int start, int rad){
	// does everything after start detonate?
	int cur = start, nex = 0;
	while(cur < A.back()){
		while(nex+1 < n && A[nex+1] <= cur + rad) nex++;
		if(A[nex] == cur){
			return false;
		}
		cur = A[nex];
		rad -= 2;
	}
	return true;
}

// We can negate and reverse the A array, then run works_right with -start as the parameter
// See if you can figure out why this trick works!
bool works_left(int start, int rad){
    for(int &x: A) x *= -1;
    reverse(A.begin(), A.end());
    bool ans = works_right(-start, rad);
	reverse(A.begin(), A.end());
    for(int &x: A) x *= -1;
    return ans;
}

int main()
{
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    cin >> n;
    A.resize(n);
    for(int i=0; i<n; ++i){
        cin >> A[i];
		// We only need 2r to be the distance between two haybales in the initial explosion
		// So to make r an integer, we can multiply the haybale locations by 2.
		A[i] *= 2;
    }
    sort(A.begin(), A.end());
    int lo = 0, hi = 2e9;
    while(lo < hi){
        int mid = lo+(hi-lo)/2;
        int l = A.front(), r = A.back();
		while(l < r){
			int m = l+(r-l)/2; // leftmost start location that works_right
			if(works_right(m, mid)) r = m;
			else l = m+1;
		}
		if(works_left(l, mid)){
			hi = mid;
		} else{
			lo = mid+1;
		}
    }
    cout << lo/2 << '.' << (lo % 2 ? 5 : 0) << '\n';
}
