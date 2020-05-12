// [1차] 셔틀버스
#include<bits/stdc++.h>

using namespace std;

string toHourStr(int a) {
    int t=a/60;
    int m=a%60;

    string s;

    if(t<10) s+='0';
    s+=to_string(t);
    s+=':';

    if(m<10) s+='0';
    s+=to_string(m);

    return s;
}

int toMinute(string a) {
    string s1=a.substr(0,2), s2=a.substr(3);

    int h=atoi(s1.c_str()), m=atoi(s2.c_str());

    return h*60+m;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    sort(timetable.begin(),timetable.end());
    vector<map<string,vector<string>>> bus;
    queue<string> q;
    for(auto iter:timetable) q.push(iter);

    int nine=60*9;
    string lastStr;
    for(int i=0;i<n;i++) {
        if(i>0) nine+=t;

        string s=toHourStr(nine);
        vector<string> v;
        map<string,vector<string>> mp;

        for(int j=0;j<m;j++) {
            if(!q.empty() && s>=q.front()) {
                v.push_back(q.front());     // 대기열의 크루 태우기
                q.pop();
            }
            else break;
        }

        mp.insert({s,v});
        bus.push_back(mp);

        if(i==n-1) lastStr=s;
    }

    // 막차 정보
    map<string,vector<string>> last=bus.back();
    if(last[lastStr].size()==m) {   // 만석일 경우
        string c=last[lastStr].back();
        int minute=toMinute(c);
        answer=toHourStr(minute-1);
    } else {                        // 만석이 아닐 경우
        answer=lastStr;
    }    

    return answer;
}

int main() {

    int n=2,t=1,m=2;
    vector<string> timetable={"09:00", "09:00", "09:00", "09:00"};

    string result=solution(n,t,m,timetable);
    cout<<result<<"\n";

    return 0;
}