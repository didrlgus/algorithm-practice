// 9375. 패션왕 신해빈
#include<bits/stdc++.h>

using namespace std;

map<string,int> m;

int main() {

    int n;
    scanf("%d",&n);

    while(n--) {
        int a;
        scanf("%d\n",&a);

        while(a--) {
            string s;
            getline(cin,s);

            int idx=s.find(" ");

            string ns="";
            for(int i=idx+1;i<s.size();i++) ns+=s[i];

            m[ns]++;
        }
        
        int sum=1;
        for(auto iter:m) {
            sum*=(iter.second+1);       // (각각 입는 경우 + 아무것도 안 입는 경우)
        }
        sum--;                          // 모두 입지 않은 경우 -1
        printf("%d\n",sum);
        m.clear();
    }

    return 0;
}