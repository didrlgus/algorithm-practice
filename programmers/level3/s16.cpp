// 입국심사
#include<bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(),times.end());
    long long max_=times.back();

    long long start=1,end=max_*n;

    while(start+1<end) {
        long long mid=(start+end)/2;

        long long cnt=0;

        for(int i=0;i<times.size();i++) cnt+=(mid/times[i]);
        
        if(cnt>=n) end=mid;
        else start=mid;
    }

    answer=end;

    return answer;
}

int main() {

    int n=6;
    vector<int> times={7,10};
    long long result=solution(n,times);

    printf("%lld\n",result);

    return 0;
}