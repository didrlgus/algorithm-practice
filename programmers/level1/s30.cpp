// 실패율
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool comp(pair<double, int>a, pair<double, int>b) {
	if (a.first == b.first) {
		return a.second < b.second; // 오름차순
	}
	else {
		return a.first > b.first;   // 내림차순
	}
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    queue<int> q;
    // 오름차순
    sort(stages.begin(),stages.end());

    for(int i=0;i<stages.size();i++) q.push(stages[i]);

    vector<pair<double,int>> v;

    for(int i=1;i<=N;i++) {
        if(!q.empty()) {
            int f=q.front();
            int s=q.size();
            int cnt=0;

            while(f==i) {
                q.pop();
                f=q.front();
                cnt++;
            }
            double d=cnt/(double)s;

            v.push_back({d,i});
        } else {
            v.push_back({0,i});
        }
    }

    sort(v.begin(),v.end(),comp);

    for(int i=0;i<v.size();i++) {
        answer.push_back(v[i].second);
    }

    return answer;
}

int main() {

    int N=5;
    vector<int> stages={2, 1, 2, 6, 2, 4, 3, 3};

    vector<int> answer=solution(N,stages);

    for(int i=0;i<answer.size();i++) printf("%d ",answer[i]);

    return 0;
}