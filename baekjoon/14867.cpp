// 물통
#include<bits/stdc++.h>

using namespace std;

int a,b,c,d,level;
map<pair<int,int>,bool> mp;
queue<pair<int,int>> q;

void func(int y,int x) {
    if(!mp[{y,x}]) {
        mp[{y,x}]=true;
        q.push({y,x});
    }
}

int bfs(int y,int x) {
    mp.insert({{y,x},true});
    q.push({y,x});

    while(!q.empty()) {
        int size=q.size();
        while(size--) {
            tie(y,x)=q.front(); q.pop();

            if(y==c&&x==d) return level;

            func(a,x);
            func(y,b);
            func(0,x);
            func(y,0);
            y+x<=b?func(0,x+y):func(y-(b-x),b);
            y+x<=a?func(y+x,0):func(a,x-(a-y));
        }
        level++;
    }
    return -1;
}

int main() {
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int ret=bfs(0,0);
    printf("%d\n",ret);
    
    return 0;
}