// 거북이
#include<bits/stdc++.h>
using namespace std;
int tc;
string s;
int dy[]={-1,0,1,0};
int dx[]={0,-1,0,1};
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>tc;
    while(tc--) {
        cin>>s;
        int dir=0,y=0,x=0,mx_y=0,mx_x=0,mn_y=0,mn_x=0;
        for(auto c:s) {
            if(c=='F') {
                y+=dy[dir];x+=dx[dir];
                mx_y=max(mx_y,y);mx_x=max(mx_x,x);
                mn_y=min(mn_y,y);mn_x=min(mn_x,x);
            } else if(c=='B') {
                y-=dy[dir];x-=dx[dir];
                mx_y=max(mx_y,y);mx_x=max(mx_x,x);
                mn_y=min(mn_y,y);mn_x=min(mn_x,x);
            } else if(c=='L') dir=(dir+1)%4;
            else dir=dir-1<0?3:dir-1;
        }
        cout<<(mx_y-mn_y)*(mx_x-mn_x)<<"\n";
    }
    return 0;
}