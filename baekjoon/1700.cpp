// 멀티탭 스케줄링
#include<bits/stdc++.h>

using namespace std;

int n,k;
int arr[110];
bool visited[110];
vector<int> v;
// 현재 멀티탭에 꽂혀있는 전기용품 중 가장 나중에 사용될 전기용품의 플러그를 뽑는다
int main() {
    scanf("%d %d",&n,&k);
    for(int i=0;i<k;i++) scanf("%d",&arr[i]);
    
    int cnt=0;
    for(int i=0;i<k;i++) {
        if(!visited[arr[i]]) {
            if((int)v.size()==n) {
                int last_idx=0,pos;
                for(auto a:v) {
                    int here_pick=200;
                    for(int j=i+1;j<k;j++) {
                        if(a==arr[j]) {
                            here_pick=j;
                            break;
                        }
                    }
                    if(last_idx<here_pick) {
                        last_idx=here_pick;
                        pos=a;
                    }
                }
                visited[pos]=false;
                cnt++;
                v.erase(find(v.begin(),v.end(),pos));
            }
            visited[arr[i]]=true;
            v.push_back(arr[i]);
        }
    }
    printf("%d\n",cnt);
    return 0;
}