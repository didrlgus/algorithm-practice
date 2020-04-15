// 단체사진 찍기
#include <string>
#include <vector>
#include <string.h>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

string s;
bool visited[15];
char r[15];
int answer;

// 두번째 매개변수 vector를 안쪽에 넣었을 경우 통과됨
void func(int current,vector<pair<char,pair<char,pair<char,int>>>> v) {
    if(current>=s.size()) {
        string rs;
        for(int i=0;i<current;i++) rs+=r[i];

        bool flag=false;
        for(int i=0;i<v.size();i++) {
            char c1=v[i].first;
            char c2=v[i].second.first;
            char o=v[i].second.second.first;
            int d=v[i].second.second.second;
            
            int dis=rs.find(c1)-rs.find(c2);
            dis=abs(dis)-1;

            if(o=='=') {
                if(dis!=d) flag=true;
            } else if(o=='>') {
                if(dis<=d) flag=true;
            } else {
                if(dis>=d) flag=true;
            }

            if(flag) break;
        }
        if(!flag) answer++;
    } else {
        for(int i=0;i<8;i++) {
            if(!visited[i]) {
                visited[i]=true;
                r[current]=s.at(i);

                func(current+1,v);

                visited[i]=false;
                r[current]='0';
            }
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    s="ACFJMNRT";
    memset(visited,false,sizeof(visited));
    memset(r,'0',sizeof(r));
    answer = 0;
    vector<pair<char,pair<char,pair<char,int>>>> v; 
    for(int i=0;i<n;i++) {
        v.push_back({data[i].at(0),{data[i].at(2),{data[i].at(3),data[i].at(4)-'0'}}});
    }

    func(0,v);

    return answer;
}

int main() {

    int n=2;
    vector<string> data={"N~F=0","R~T>2"};

    int result=solution(n,data);
    printf("%d\n",result);

    return 0;
}