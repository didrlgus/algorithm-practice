#include<bits/stdc++.h>
using namespace std;
map<int,int> cnt_mp;
int n,p_sum[100005],leader,leader_cnt,ret;
int solution(vector<int> &A) {
    n=(int)A.size();
    cnt_mp[A[0]]++;
    leader=A[0];
    for(int i=1;i<n;i++) {              // 배열 전체에서 leader 1명에 대해서만 고려해주면됨
        cnt_mp[A[i]]++;
        if(leader!=A[i]) {
            if(cnt_mp[leader]<cnt_mp[A[i]]) leader=A[i];
        }
    }
    leader_cnt=cnt_mp[leader];
    if(A[0]==leader) p_sum[0]=1;
    else p_sum[0]=0;
    for(int i=1;i<n;i++) {
        if(A[i]==leader) p_sum[i]=p_sum[i-1]+1;
        else p_sum[i]=p_sum[i-1];
    }
    for(int i=0;i<n-1;i++) {
        int left_cnt=p_sum[i],left_len=i+1;
        int right_cnt=p_sum[n-1]-left_cnt,right_len=n-left_len;
        if((left_cnt>left_len/2)&&(right_cnt>right_len/2)) ret++;
    }
    return ret;
}