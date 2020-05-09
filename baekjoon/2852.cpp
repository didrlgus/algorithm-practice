// NBA 농구
#include<bits/stdc++.h>

using namespace std;

int n;
int team1[2900];
int team2[2900];
vector<int> v1,v2;

string func(int a,int b) {
    string rs;
    if(a<10) rs+='0';
    rs+=to_string(a);

    rs+=':';

    if(b<10) rs+='0';
    rs+=to_string(b);

    return rs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n; cin.ignore();

    for(int i=0;i<n;i++) {
        string s;
        getline(cin,s);
        
        int team,minute,second;

        team=atoi(s.substr(0,1).c_str());
        minute=atoi(s.substr(2,3).c_str());
        second=atoi(s.substr(5).c_str());

        if(team==1) {
            v1.push_back(minute*60+second);      // 초로 변환
        } else {
            v2.push_back(minute*60+second);
        }
    }   
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    for(int i=0;i<v1.size();i++) {
        for(int j=v1[i];j<2880;j++) team1[j]=i+1;
    }

    for(int i=0;i<v2.size();i++) {
        for(int j=v2[i];j<2880;j++) team2[j]=i+1;
    }

    int lead1=0,lead2=0;
    for(int i=0;i<2880;i++) {
        if(team1[i]>team2[i]) lead1++;
        else if(team1[i]<team2[i]) lead2++;
    }
    
    int a=(lead1/60), b=(lead1%60);
    int c=(lead2/60), d=(lead2%60);
    
    cout<<func(a,b)<<"\n";
    cout<<func(c,d)<<"\n";
    
    return 0;
}