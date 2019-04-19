#include <bits/stdc++.h>
using namespace std;

// will be used to save the ways that you can reach the asked amount 'a'
long int counter = 0;

// rest is the distance to the asked amount, if it is negative, you have passed it
void supra(set<int>&s, set<int>::iterator itt, int rest) {
    // iterate from the current coin to the greater ones
    for (set<int>::iterator it = itt; it!=s.end(); it++) {
        if (*it > rest) {  // this means that you have passed the asked amount 'a'
            return;
        }else if (*it == rest) {// this means that this way leaves you with asked amount
            counter++;  // save that you can reach this way
            // also, the next value (which is greater) will not be a valid answer
            return;
        }else {
            // this means that you have not reached the asked amount yet
            supra(s, it, rest - *it); // now try to add the number, and you will be *it units closer to 'a'
        }
    } return;
}

int main() {
    int a, times, n;
    set<int> s;
    cin>>a>>times;
    while(times--) {
        cin>>n; s.insert(n);
    } supra(s,s.begin(),a);
    cout<<counter<<'\n';
    return 0;
}
