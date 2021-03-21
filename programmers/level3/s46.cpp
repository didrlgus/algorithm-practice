// 광고 삽입
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[360001],start_time,end_time,ret;
vector<int> pv,av;
ll cur_val,mx;
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    for(int i=0;i<8;i+=3) {
        pv.push_back((play_time[i]-'0')*10+(play_time[i+1]-'0'));
        av.push_back((adv_time[i]-'0')*10+(adv_time[i+1]-'0'));
    }
    int play_time_sec=pv[0]*3600+pv[1]*60+pv[2],adv_time_sec=av[0]*3600+av[1]*60+av[2];
    for(auto log:logs) {
        string s,e;
        for(int i=0;i<8;i++) s+=log[i];
        for(int i=9;i<(int)log.size();i++) e+=log[i];
        int start_time_sec=stoi(s.substr(0,2))*3600+stoi(s.substr(3,2))*60+stoi(s.substr(6,2));
        int end_time_sec=stoi(e.substr(0,2))*3600+stoi(e.substr(3,2))*60+stoi(e.substr(6,2));
        arr[start_time_sec]++;arr[end_time_sec]--;      // 누적합 빠르게 구하기
    }
    for(int i=1;i<=play_time_sec;i++) arr[i]+=arr[i-1]; // 누적합 빠르게 구하기
    for(int i=0;i<adv_time_sec;i++) cur_val+=arr[i];
    mx=cur_val;
    for(int i=1;i<=play_time_sec-adv_time_sec;i++) {
        cur_val=cur_val-arr[i-1]+arr[i+adv_time_sec-1];
        if(cur_val>mx) {
            mx=cur_val;
            ret=i;
        }
    }
    int hour=ret/3600,minute=(ret%3600)/60,second=(ret%3600)%60;
    string ret_hour="",ret_minute="",ret_second="";
    if(hour<10) ret_hour+='0';
    if(minute<10) ret_minute+='0';
    if(second<10) ret_second+='0';
    answer+=ret_hour+to_string(hour)+":"+ret_minute+to_string(minute)+":"+ret_second+to_string(second);
    return answer;
}
int main() {
    string ret=solution("50:00:00", "32:37:27", {"15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"});
    cout<<ret<<'\n';
    return 0;
}