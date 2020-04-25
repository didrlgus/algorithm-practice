// [1차] 추석 트래픽
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

vector<string> split(string strToSplit, char delimeter) {
    stringstream ss(strToSplit);
    string item;
	vector<std::string> splittedStrings;
    while (getline(ss, item, delimeter)) {
		splittedStrings.push_back(item);
    }
	return splittedStrings;
}

// 24시간 -> 86400000ms
int a[86400000];
int solution(vector<string> lines) {
    int answer = -1;

    for(int i=0;i<lines.size();i++) {
        vector<string> v=split(lines[i],' ');

        // v[1]     20:59:57.421
        // h        v2[0]
        // m        v2[1]
        // s.ms     v2[2]
        vector<string> v2=split(v[1],':');

        // to millisecond
        int h=atoi(v2[0].c_str())*60*60*1000;    
        int m=atoi(v2[1].c_str())*60*1000;

        v2[2].erase(v2[2].begin()+2);
        int s=atoi(v2[2].c_str());

        // 0.351s
        v[2].pop_back();

        // 간격 데이터 동일하게 맞춰주기
        if(v[2].size()==1) v[2].push_back('.');
        while(v[2].size()<5) v[2].push_back('0');
        v[2].erase(v[2].begin()+1);

        int t=atoi(v[2].c_str());

        int end=h+m+s+999;          // 임의의 구간에서 1초단위로 카운팅 할 경우 end에서 +999ms까지는 동일하게 카운트 됨 (유효구간이 됨)
        int start=end-t+1-999;      // 임의의 구간에서 1초단위로 카운팅 할 경우 start에서 -999ms까지는 동일하게 카운트 됨

        if(start<0) start=0;
        if(end>86400000) end=86400000;

        for(int j=start;j<=end;j++) {
            a[j]++;
            if(answer<a[j]) answer=a[j];
        }
    }

    return answer;
}

int main() {

    vector<string> lines={"2016-09-15 00:00:00.000 3s"};

    int result=solution(lines);
    printf("%d\n",result);

    return 0;
}