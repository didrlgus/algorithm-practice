// [3차] 파일명 정렬
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<string,pair<string,int>> p1, pair<string,pair<string,int>> p2) {  // stable_sort -> &제거
    string p1Head=p1.first,p2Head=p2.first;
    for(int i=0;i<p1Head.size();i++) p1Head[i]=toupper(p1Head[i]);
    for(int i=0;i<p2Head.size();i++) p2Head[i]=toupper(p2Head[i]);

    string numStr1=p1.second.first,numStr2=p2.second.first;

    while(numStr1[0]=='0') numStr1=numStr1.substr(1);    
    int num1=atoi(numStr1.c_str());
    while(numStr2[0]=='0') numStr2=numStr2.substr(1);    
    int num2=atoi(numStr2.c_str());

    if(p1Head==p2Head) return num1<num2;
    return p1Head<p2Head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<string,pair<string,int>>> v;
    vector<string> t;

    for(int i=0;i<files.size();i++) {
        string s=files[i];
        
        // head 구하기
        string head;
        int idx;
        for(int j=0;j<s.size();j++) {
            if(s.at(j)<'0' || s.at(j)>'9') {        // 숫자가 아닐경우
                head+=s[j];
            } else {
                idx=j;
                break;
            }
        }
        
        // number 구하기
        string number;
        for(int j=idx;j<s.size();j++) {
            if(s.at(j)>='0' && s.at(j)<='9') {
                number+=s[j];
            } else {
                idx=j;
                break;
            }
            if(j==s.size()-1) idx=j+1;
        }

        v.push_back({head,{number,i}});

        // tail 구하기
        string tail="";
        if(idx<s.size()) tail+=s.substr(idx);
        t.push_back(tail);
    }
    // 일반 sort를 사용할 경우 같은 조건에도 순서를 바꿔서 오답처리됨
    stable_sort(v.begin(),v.end(),cmp);     

    for(int i=0;i<v.size();i++) answer.push_back(v[i].first+v[i].second.first+t[v[i].second.second]);

    return answer;
}

int main() {

    vector<string> files={"img12     -...12345", "img10.png", "amg02.png", "img1.png", "IMG01.GIF", "img2.JPG"};

    vector<string> result=solution(files);

    for(int i=0;i<result.size();i++) cout<<result[i]<<endl;

    return 0;
}