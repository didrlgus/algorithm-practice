// 주사위 윷놀이
#include<bits/stdc++.h>
using namespace std; 

int arr[15],score[105],horse[4];
vector<int> graph[35];
int n=10;
int mx=-987654321;

void add(int a,int b) {
    graph[a].push_back(b);
}
void setMap() {
    for(int i=0;i<=19;i++) add(i,i+1);
    add(5,21);add(21,22);add(22,23);add(23,24);
    add(10,27);add(27,28);add(28,24);add(24,25);
    add(15,29);add(29,30);add(30,31);add(31,24);
    add(25,26);add(26,20);add(20,100);  // 도착점 100

    int a=2;
    for(int i=1;i<=19;i++) {
        score[i]=a;
        a+=2;
    }
    score[20]=40;score[21]=13;score[22]=16;score[23]=19; 
	score[24]=25;score[25]=30;score[26]=35;score[27]=22;
	score[28]=24;score[29]=28;score[30]=27;score[31]=26;
}

int move(int start_idx,int cnt) {
    if(start_idx==100) return 100;
    if(graph[start_idx].size()>1) {             // 지름길로 가는 경우
        start_idx=graph[start_idx][1];
        cnt--;
    }
    if(cnt>0) {
        queue<int> q;
        q.push(start_idx);
        int next_idx;
        while(!q.empty()) {
            int prev_idx=q.front(); q.pop();
            next_idx=graph[prev_idx][0];
            q.push(next_idx);
            cnt--;
            if(next_idx==100) break;
            if(cnt==0) break;
        }
        return next_idx;
    } else return start_idx;
}

bool check(int next_idx,int h) {
    if(next_idx==100) return true;
    for(int i=0;i<4;i++) {
        if(i==h) continue;
        if(horse[i]==next_idx) return false;
    }
    return true;
}

void dfs(int current,int sum) {
    if(current==n) {
        mx=max(mx,sum);
        return;
    }

    for(int i=0;i<4;i++) {
        int tmp_idx=horse[i];
        int next_idx=move(tmp_idx,arr[current]);    // 인자->현재위치,움직일 칸
        
        if(!check(next_idx,i)) continue;

        horse[i]=next_idx;
        dfs(current+1,sum+score[next_idx]);
        horse[i]=tmp_idx;
    }
}

int main(){
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    setMap();
    dfs(0,0);
    printf("%d\n",mx);
    return 0;
}

