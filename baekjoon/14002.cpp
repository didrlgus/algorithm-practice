// 가장 긴 증가하는 부분 수열 4
#include <bits/stdc++.h>
using namespace std;

int arr[1005];
int dp[1005];
int v[1005];
int mx=-987654321;
stack<int> st;
// void go(int p) {
//     if(p == 0) return;
//     go(v[p]);
//     printf("%d ",arr[p]);
// }
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin >> arr[i];
    // dp[i] -> i번째 수를 마지막으로 사용하는 부분수열 중 최대길이
    dp[0]=1;
    for(int i=1;i<n;i++){
        dp[i]=1;                                    // 자기자신
        for(int j=0;j<i;j++) {
            if(arr[j]<arr[i] && dp[i]<dp[j]+1) {    // arr[i]보다 작은 원소여야 arr[i]의 앞에 쓸 수 있으므로
                dp[i]=dp[j]+1;
                v[i]=j;                             // 최대길이 부분수열 이전요소의 인덱스로 최종적으로 갱신됨
            }
        }
    }
    int p=0;
    for(int i=0;i<n;i++) {
        if(mx<dp[i]) {
            mx=dp[i];
            p=i;
        }
    }
    printf("%d\n",mx);
    st.push(p);
    mx--;
    while(mx--) {
        st.push(v[p]);
        p=v[p];
    }
    while(!st.empty()) {
        printf("%d ",arr[st.top()]);
        st.pop();
    }
    printf("\n");

    return 0;
}