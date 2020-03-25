// 1339. 단어 수학
#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int n;
int alpha[35];
vector<string> s;
int max_=0;

int main() {
    
    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        string str;
        cin>>str;
        s.push_back(str);
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<s[i].size();j++) {
            alpha[s[i].at(j)-'A'] += pow(10, s[i].size()-j-1);
        }
    }
    
    sort(alpha, alpha+35, greater<int>());

    for(int i=0;i<35;i++) {
        if(alpha[i]<=0) break;

        max_+=alpha[i]*(9-i);
    }
    
    printf("%d\n", max_);

    return 0;
}