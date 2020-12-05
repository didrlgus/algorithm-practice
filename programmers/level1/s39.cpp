// x만큼 간격이 있는 n개의 숫자
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> solution(int x,int n) {
	vector<ll> answer;
	answer.push_back(x);
	for(int i=1;i<n;i++) answer.push_back(answer.back()+x);
	return answer;
}