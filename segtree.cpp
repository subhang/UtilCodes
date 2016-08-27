#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int maxsize;
int getmid(int s,int e) { 
    return (s+((e-s)/2));
}
int st[100];
int constructst(int a[],int ss,int se,int si){
    //cout << "camehere " << ss << " " << se << endl;
    if(ss == se){
      //  cout << "assigning " << si << " " << a[ss] << endl;
        st[si] = a[ss];
        return a[ss];
    }
    int mid = getmid(ss,se);
    st[si] = constructst(a,ss,mid,(si*2)+1)+constructst(a,mid+1,se,(si*2)+2);
    //cout << st[si] << "is at index" << si << endl;
    return st[si];
    
}
int getsum(int ss,int se,int qs,int qe,int si){
    
        if(qs <= ss && qe >= se) return st[si];
        if(se < qs || ss > qe) return 0;
        int mid = getmid(ss,se);
        
        return getsum(ss,mid,qs,qe,(2*si)+1)+getsum(mid+1,se,qs,qe,(2*si)+2);
}
void updateval(int ss,int se,int i,int diff,int si){
    
    if(i < ss||i > se) return;
    st[si] = st[si]+diff;
    if(se != ss){
        int mid = getmid(ss,se);
        updateval(ss,mid,i,diff,2*si+1);
        updateval(mid+1,se,i,diff,2*si+2);
    }
    
}
void update(int a,int i,int x){
    
    int diff = a[i]-x;
    a[i] = x;
    updateval(0,n-1,i,diff,0);
    
}
void createst(int a[],int n){
    
    constructst(a,0,n-1,0);
}
int main(){
    int n;
    cin >> n;
    int l,r;
    int a[30];
    
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    createst(a,n);
    for(int i = 0;i < 10;i++) {
        cout << st[i] << " ";
    }
    
    cout << endl;
    int q;
    cin >> q;
    while(q--){
        cin >> l >> r;
        cout << l << " " << r << endl;
        cout << getsum(0,n-1,l,r,0) << endl;
    }
    
    
}
