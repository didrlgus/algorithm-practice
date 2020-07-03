// 문장
#include<bits/stdc++.h>
using namespace std;
int n,cnt,ret;
string s,s2,arr[1005];
void init() {
    arr[1]="one",arr[2]="two",arr[3]="three",arr[4]="four",arr[5]="five",
    arr[6]="six",arr[7]="seven",arr[8]="eight",arr[9]="nine",arr[10]="ten";
    arr[11]="eleven",arr[12]="twelve",arr[13]="thirteen",arr[14]="fourteen",
    arr[15]="fifteen",arr[16]="sixteen",arr[17]="seventeen",arr[18]="eighteen",arr[19]="nineteen",
    arr[20]="twenty",arr[30]="thirty",arr[40]="forty",arr[50]="fifty",arr[60]="sixty",arr[70]="seventy",arr[80]="eighty",arr[90]="ninety",
    arr[100]="onehundred",arr[200]="twohundred",arr[300]="threehundred",arr[400]="fourhundred",arr[500]="fivehundred",
    arr[600]="sixhundred",arr[700]="sevenhundred",arr[800]="eighthundred",arr[900]="ninehundred";
    for(int i=20;i<100;i+=10) {
        for(int j=i+1;j<=i+9;j++) arr[j]=arr[i]+arr[j-i];
    }
    for(int i=100;i<1000;i+=100) {
        for(int j=i+1;j<=i+99;j++) arr[j]=arr[i]+arr[j-i];
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>s;
        if(s!="$") cnt+=(int)s.size();
        s2+=s+' ';    
    }
    for(int i=1;i<1000;i++) {
        if((int)arr[i].size()+cnt==i) {
            ret=i;
            break;
        }
    }
    s2.replace(find(s2.begin(),s2.end(),'$')-s2.begin(),1,arr[ret]);
    cout<<s2<<'\n';
    return 0;
}