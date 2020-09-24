// 로봇 시뮬레이션
#include<bits/stdc++.h>
using namespace std;
struct p {
    int y,x,dir;
};
struct r {
    int num,dir;
};
struct input {
    int num,cnt;
    char command;
};
r arr[105][105];
vector<p> robot_v;
vector<input> v;
int n,m,r_cnt,com_cnt,dy[]={0,-1,0,1,0},dx[]={0,0,1,0,-1};
int main() {
    cin>>m>>n>>r_cnt>>com_cnt;
    robot_v.push_back({-1,-1,-1});
    for(int i=0;i<r_cnt;i++) {
        int y,x;char dir;cin>>x>>y>>dir;
        y=n-y;x--;
        int r_dir=0;
        if(dir=='N') r_dir=1;
        else if(dir=='E') r_dir=2;
        else if(dir=='S') r_dir=3;
        else r_dir=4;
        robot_v.push_back({y,x,r_dir});
        arr[y][x]={i+1,r_dir};
    }
    for(int i=0;i<com_cnt;i++) {
        int robot_num,cnt;char command;cin>>robot_num>>command>>cnt;
        v.push_back({robot_num,cnt,command});
    }
    for(int i=0;i<com_cnt;i++) {
        int robot_num=v[i].num,cnt=v[i].cnt;char command=v[i].command;
        p& robot=robot_v[robot_num];
        if(command=='F') {
            arr[robot.y][robot.x].num=0;arr[robot.y][robot.x].dir=0;
            for(int j=0;j<cnt;j++) {
                robot.y+=dy[robot.dir];robot.x+=dx[robot.dir];
                if(robot.y<0||robot.x<0||robot.y>=n||robot.x>=m) {
                    printf("Robot %d crashes into the wall\n",robot_num);
                    return 0;
                } else if(arr[robot.y][robot.x].num) {
                    printf("Robot %d crashes into robot %d\n",robot_num,arr[robot.y][robot.x]);
                    return 0;
                }
            }
            arr[robot.y][robot.x]={robot_num,robot.dir};
        } else if(command=='R') {
            for(int j=0;j<cnt;j++) {
                robot.dir++;
                if(robot.dir==5) robot.dir=1;
            }
        } else {
            for(int j=0;j<cnt;j++) {
                robot.dir--;
                if(robot.dir==0) robot.dir=4;
            }
        }
    }
    printf("OK\n");
    return 0;
}