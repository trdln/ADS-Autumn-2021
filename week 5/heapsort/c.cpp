#include <iostream>
using namespace std;
int main(){
    int n; int k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < n - k + 1; ++i){
        cout<< min(a[i],min(a[i+1],a[i+2])) << endl;
    }
}