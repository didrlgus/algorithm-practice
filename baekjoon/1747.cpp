// 소수&팰린드롬
#include<bits/stdc++.h>
using namespace std;
int n,k=1003001;
bool arr[1003005];
int main() {
    scanf("%d",&n);
    for(int i=2;i<=k;i++) arr[i]=true;  
    for(int i=2;i<=k;i++) {
	    if(arr[i]) {
		    for(int j=2;j<=k/i;j++){
			    if(arr[i*j]) arr[i*j]=false;
		    }
	    }
    }
    for(int i=n;i<=k;i++) {
        if(arr[i]) {
            string str=to_string(i);
            bool flag=false;
            for(int j=0;j<(int)str.size();j++) {
                if(str[j]!=str[(int)str.size()-1-j]) {
                    flag=true;
                    break;
                }
            }
            if(!flag) {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}