// 큰수 A+B
#include<string>
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

string A,B;
int a,b,carry=0;
vector<char> ret;
int main() {
    
    cin>>A>>B;

    int a_size=A.size(),b_size=B.size();
    
    if (a_size>b_size) {
        int diff = a_size-b_size;
        while(diff--) B='0'+B;
    } else {
        int diff = b_size-a_size;
        while(diff--) A='0'+A;
    }
    int t_size=A.size();
    for (int i=t_size-1;i>=0;i--) {
        a=A[i]-'0';
        b=B[i]-'0';
        int val=(a+b+carry)%10;
        carry=(a+b+carry)/10;
        ret.push_back(val+48);
    }
    if (carry>0) ret.push_back(carry+48);
    for (int i=ret.size()-1;i>=0;i--) {
        cout<<ret[i];
    }
    printf("\n");
    return 0;
}