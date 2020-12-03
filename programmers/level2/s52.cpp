// 수식 최대화
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
vector<char> op;
vector<vector<char>> vv={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
vector<char> oper={'-','+','*'};
ll solution(string expression) {
    ll answer=-2e18;
	string num="";
	for(auto it:expression) {
		if(it!='-'&&it!='+'&&it!='*') num+=it;
		else {
			v.push_back(atoi(num.c_str()));
			op.push_back(it);
			num="";
		}
	}
	v.push_back(atoi(num.c_str()));
	vector<ll> tmp_v=v;
	vector<char> tmp_op=op;
	for(int i=0;i<6;i++) {
		for(int j=0;j<3;j++) {
			char cur_op=oper[vv[i][j]];
			for(int k=0;k<(int)op.size();k++) {
				if(op[k]==cur_op) {
					ll a=v[k],b=v[k+1],insert_val;
					if(cur_op=='-') insert_val=a-b;
					else if(cur_op=='+') insert_val=a+b;
					else insert_val=a*b;
					v.erase(v.begin()+k,v.begin()+k+2);
					v.insert(v.begin()+k,insert_val);
					op.erase(op.begin()+k);
					k--;
				}
			}
		}
		answer=max(answer,abs(v[0]));
		v=tmp_v;
		op=tmp_op;
	}
    return answer;
}