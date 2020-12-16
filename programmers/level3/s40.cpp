// 보석 쇼핑
#include<bits/stdc++.h>
using namespace std;
int n,lo,hi,cnt;
set<string> st;
map<string,int> mp;
vector<int> answer;
vector<int> solution(vector<string> gems) {	
	vector<pair<int,int>> v;
	for(auto it:gems) st.insert(it);
	n=(int)st.size();
	while(hi<(int)gems.size()) {
		if(cnt<n) {
			if(!mp[gems[hi]]) cnt++;
			mp[gems[hi]]++;
			hi++;
			if(cnt==n) {
				v.push_back({hi-lo-1,lo});
			}
		} else {
			mp[gems[lo]]--;
			if(!mp[gems[lo]]) cnt--;
			lo++;
			if(cnt==n) v.push_back({hi-lo-1,lo});
		}
	}
	while(lo<(int)gems.size()) {
		mp[gems[lo]]--;
		if(!mp[gems[lo]]) cnt--;
		lo++;
		if(cnt>=n) v.push_back({hi-lo-1,lo});
		else break;
	}
	sort(v.begin(),v.end());
	answer.push_back(v[0].second+1);
	answer.push_back(v[0].second+v[0].first+1);
    return answer;
}
int main() {
	vector<string> gems={"EM", "DIA", "EM", "DIA", "AWS"};
	vector<int> ret=solution(gems);
	for(auto it:ret) printf("%d ",it);
	return 0;
}