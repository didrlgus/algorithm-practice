// NBA 농구
#include<bits/stdc++.h>
using namespace std;

int n,arr1[2890],arr2[2890],cnt1,cnt2;

string to_minute(int m,int s) {
    string str="";
    if(m<10) str+='0';
    str+=to_string(m);
    str+=':';
    if(s<10) str+='0';
    str+=to_string(s);
    return str;
}
int main() {
    cin>>n; cin.ignore();
    for(int i=0;i<n;i++) {
        string str;
        getline(cin,str);
        int t,m,s;
        t=atoi(str.substr(0,1).c_str());
        m=atoi(str.substr(2,4).c_str());
        s=atoi(str.substr(5).c_str());
        for(int j=m*60+s;j<2880;j++) {
            if(t==1) arr1[j]++;
            else arr2[j]++;       
        }
    }
    for(int i=0;i<2880;i++) {
        if(arr1[i]>arr2[i]) cnt1++;
        else if(arr1[i]<arr2[i]) cnt2++;
    }
    cout<<to_minute(cnt1/60,cnt1%60)<<"\n";
    cout<<to_minute(cnt2/60,cnt2%60)<<"\n";
    return 0;
}