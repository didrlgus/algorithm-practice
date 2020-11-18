// 좌표 정렬하기 2
#include<bits/stdc++.h>
using namespace std;
struct Point {
    int x,y;
};
bool cmp(Point p1,Point p2) {
    if(p1.y==p2.y) return p1.x<p2.x;
    return p1.y<p2.y;
}
int n;
vector<Point> v;
int main() {
    scanf("%d",&n);
    while(n--) {
        int x,y;scanf("%d%d",&x,&y);
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),cmp);
    for(auto it:v) printf("%d %d\n",it.x,it.y);
    return 0;
}