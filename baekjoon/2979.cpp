// 트럭 주차
#include<bits/stdc++.h>

using namespace std;

int a,b,c;
int arr[110];
int max_=-987987987;

int main() {

    cin>>a>>b>>c;
    
    for(int i=0;i<3;i++) {
        int s,e;
        cin>>s>>e;

        if(max_<e) max_=e;

        for(int j=s;j<e;j++) arr[j]++;
    }

    int sum=0;

    for(int i=1;i<max_;i++) {
        if(arr[i]==1) sum+=a;
        else if(arr[i]==2) sum+=b*2;
        else if(arr[i]==3) sum+=c*3;
    }

    cout<<sum<<endl;
}