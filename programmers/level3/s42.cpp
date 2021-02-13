// 풍선 터트리기
#include<bits/stdc++.h>
using namespace std;
int n;
priority_queue<int,vector<int>,greater<int>> pq;
map<int,bool> check;
int solution(vector<int> a) {
    int answer=2;
    n=(int)a.size();
    if(n<=2) return n;
    int lo=a[0];
    for(int i=2;i<n;i++) pq.push(a[i]);
    for(int i=1;i<n-1;i++) {
        int cur_num=a[i];
        check[cur_num]=true;
        int hi=pq.top();
        while(check[pq.top()]) pq.pop();
        if(lo<cur_num&&hi<cur_num) continue;
        else {
            answer++;
            if(cur_num<lo) lo=cur_num;
        }
    }
    return answer;
}
int main() {
    vector<int> a={-16,27,65,-2,58,-92,-71,-68,-61,-33};
    printf("%d\n",solution(a));
    return 0;
}