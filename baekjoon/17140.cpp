// 이차원 배열과 연산
#include<bits/stdc++.h>
using namespace std;
struct p {
    int num,cnt;
};
int r,c,k,arr[105][105],r_size=3,c_size=3,ret;
bool cmp(p &p1,p &p2) {
    if(p1.cnt==p2.cnt) return p1.num<p2.num;
    return p1.cnt<p2.cnt;
}
int main() {
    cin>>r>>c>>k;
    for(int i=0;i<r_size;i++) {
        for(int j=0;j<c_size;j++) cin>>arr[i][j];
    }
    while(true) {
        if(arr[r-1][c-1]==k) break;
        if(ret>100) {
            cout<<-1<<'\n';
            return 0;
        }
        int mx_r_size=0,mx_c_size=0,tmp[105][105];
        memset(tmp,0,sizeof(tmp));
        if(r_size>=c_size) {
            for(int i=0;i<r_size;i++) {
                map<int,int> mp;
                vector<p> v;
                for(int j=0;j<c_size;j++) {
                    if(arr[i][j]==0) continue;
                    mp[arr[i][j]]++;
                }
                for(auto it:mp) v.push_back({it.first,it.second});
                mx_c_size=max(mx_c_size,(int)v.size()*2);
                sort(v.begin(),v.end(),cmp);
                int idx=0;
                int size_=min(50,(int)v.size());
                for(int j=0;j<size_*2;j+=2) {
                    tmp[i][j]=v[idx].num;
                    tmp[i][j+1]=v[idx].cnt;
                    idx++;
                }
            }
            c_size=mx_c_size;
        } else {
            for(int j=0;j<c_size;j++) {
                map<int,int> mp;
                vector<p> v;
                for(int i=0;i<r_size;i++) {
                    if(arr[i][j]==0) continue;
                    mp[arr[i][j]]++;
                }
                for(auto it:mp) v.push_back({it.first,it.second});
                mx_r_size=max(mx_r_size,(int)v.size()*2);
                sort(v.begin(),v.end(),cmp);
                int idx=0;
                int size_=min(50,(int)v.size());
                for(int i=0;i<size_*2;i+=2) {
                    tmp[i][j]=v[idx].num;
                    tmp[i+1][j]=v[idx].cnt;
                    idx++;
                }
            }
            r_size=mx_r_size;
        }
        memcpy(arr,tmp,sizeof(tmp));
        ret++;
    }
    cout<<ret<<'\n';
    return 0;
}