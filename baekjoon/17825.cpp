// 주사위 윷놀이
#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
int n=10,arr[15],score[105],horse[5];
vector<int> adj[35];
void add(int a,int b) {
	adj[a].push_back(b);
}
void init() {
	for(int i=0;i<=19;i++) add(i,i+1);
	add(5,21);add(21,22);add(22,23);add(23,24);add(24,25);add(25,26);add(26,20);add(20,100);
	add(10,27);add(27,28);add(28,24);
	add(15,29);add(29,30);add(30,31);add(31,24);
	for(int i=0;i<=20;i++) score[i]=i*2;
	score[21]=13;score[22]=16;score[23]=19;score[24]=25;score[25]=30;score[26]=35;
	score[27]=22;score[28]=24;
	score[29]=28;score[30]=27;score[31]=26;
}
int move(int current_idx,int cnt) {
	if(adj[current_idx].size()>1) {
		current_idx=adj[current_idx][1];
		cnt--;
	} 
	if(cnt>0) {
		queue<int> q;
		q.push(current_idx);
		int next_idx;
		while(!q.empty()) {
			current_idx=q.front();q.pop();
			next_idx=adj[current_idx][0];
			cnt--;
			if(cnt==0||next_idx==100) break;
			q.push(next_idx);
		}
		return next_idx;
	} else return current_idx;
}
bool check(int idx,int horse_num) {
	if(idx==100) return true;
	for(int i=0;i<4;i++) {
		if(i==horse_num) continue;
		if(horse[i]==idx) return false;
	}
	return true;
}
int dfs(int current) {
	if(current==n) return 0;
	int ret=0;
	for(int i=0;i<4;i++) {
		int current_idx=horse[i];
		if(current_idx==100) continue;
		int next_idx=move(current_idx,arr[current]);
		if(!check(next_idx,i)) continue;
		horse[i]=next_idx;
		ret=max(ret,dfs(current+1)+score[next_idx]);
		horse[i]=current_idx;
	}
	return ret;
}
int main() {
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	init();
	printf("%d\n",dfs(0));
	return 0;
}