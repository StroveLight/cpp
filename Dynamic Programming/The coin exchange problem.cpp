
#include <bits/stdc++.h>
using namespace std;


// create memo to save solutions
long int v[251] = {0};

// evaluate where the number can be
void setter2(set<int>&s,int n, int max_n) {
    for (int i = 0; i<=max_n; i++) {  // max_n<=250  ;  n is the current number of the set
        if (v[i]!=0&&i+n<=max_n) v[i+n]+=v[i];
    }
}

// iiterate over the numbers once
void setter1(set<int>&s, int max_n) {
    for (set<int>::iterator it=s.begin(); it!= s.end(); it++) {
        setter2(s,*it,max_n);
    }
}

int main() {
    v[0] = 1;
    int a, times, n;
    set<int> s;
    cin>>a>>times;
    long int ans;
    while(times--) {
        cin>>n; s.insert(n);
    } setter1(s,a);
    // using setter, the position in v[a] has the number
    // of ways that you can reach the value
    cout<<v[a]<<'\n';
    return 0;
}
