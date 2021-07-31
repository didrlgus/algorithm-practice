// 큰수 A+B
#include<string>
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

string A,B,r_A,r_B;
int a,b,carry=0;
vector<int> ret;
int main() {
    
    cin>>A>>B;

    int a_size=A.size(),b_size=B.size();
    
    for(int i=a_size-1;i>=0;i--) {
        r_A += A[i];
    }

    for (int i=b_size-1;i>=0;i--) {
        r_B += B[i];
    }
    if (a_size>b_size) {
        int diff = abs(a_size-b_size);
        while(diff--) {
            r_B+='0';
        }
    } else {
        int diff = abs(a_size-b_size);
        while(diff--) {
            r_A+='0';
        }
    }
    int t_size=r_A.size();
    for (int i=0;i<t_size;i++) {
        a=r_A[i]-'0';
        b=r_B[i]-'0';
        int val=(a+b+carry)%10;
        carry=(a+b+carry)/10;
        ret.push_back(val);
    }
    if (carry>0) ret.push_back(carry);
    for (int i=ret.size()-1;i>=0;i--) {
        cout<<ret[i];
    }
    printf("\n");
    return 0;
}