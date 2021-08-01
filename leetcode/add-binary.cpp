#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        
        int a_size=a.size(),b_size=b.size();
        
        if (a_size>b_size) {
            int diff=a_size-b_size;
            while(diff--) b='0'+b;
        } else {
            int diff=b_size-a_size;
            while(diff--) a='0'+a;
        }
        string ret="";
        int t_size=a.size();
        int carry=0;
        for (int i=t_size-1;i>=0;i--) {
            int a_val=a[i]-'0',b_val=b[i]-'0';
            int val=a_val+b_val+carry;
            if (val>=2) carry=1;
            else carry=0;
            string str_val=to_string(val%2);
            ret=str_val+ret;
        }
        if (carry>=1) ret=to_string(carry)+ret;
        return ret;
    }
};