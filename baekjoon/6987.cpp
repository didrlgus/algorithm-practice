// 월드컵
#include<bits/stdc++.h>
using namespace std;
int team1[]={0,0,0,0,0,1,1,1,1,2,2,2,3,3,4};
int team2[]={1,2,3,4,5,2,3,4,5,3,4,5,4,5,5};
int arr[5][10][5],result[10][5];
bool ret[5];
void dfs(int round) {
	if(round==15) {
		for(int tc=0;tc<4;tc++) {
			if(ret[tc]) continue;
			bool flag=false;
			for(int i=0;i<6;i++) {
				for(int j=0;j<3;j++) {
					if(arr[tc][i][j]!=result[i][j]) {
						flag=true;
						break;
					}
				}
				if(flag) break;
			}
			if(!flag) ret[tc]=true;
		}
		return;
	}
	int t1=team1[round],t2=team2[round];
	result[t1][0]++;
	result[t2][2]++;
	dfs(round+1);
	result[t1][0]--;
	result[t2][2]--;

	result[t1][1]++;
	result[t2][1]++;
	dfs(round+1);
	result[t1][1]--;
	result[t2][1]--;

	result[t1][2]++;
	result[t2][0]++;
	dfs(round+1);
	result[t1][2]--;
	result[t2][0]--;
	return;
}
int main() {
	for(int tc=0;tc<4;tc++) {
		for(int i=0;i<6;i++) {
			for(int j=0;j<3;j++) scanf("%d",&arr[tc][i][j]);
		}
	}
	dfs(0);
	for(int i=0;i<4;i++) printf("%d ",ret[i]);
	return 0;
}