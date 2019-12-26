#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct MyStruct {
  string s;
  char c;
};

bool cmp(const MyStruct& o1, const MyStruct& o2) {
    if(o1.c < o2.c) return true;        // c를 이용한 오름차순 정렬
    else if (o1.c==o2.c) {
        if(o1.s < o2.s) return true;    // s를 이용한 오름차순 정렬
    }
    return false;
}

vector<MyStruct> myVector;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    for(int i=0;i<strings.size();i++) {
        myVector.push_back({strings[i], strings[i][n]});
    }
    
    sort(myVector.begin(), myVector.end(), cmp);
    
    for(int i=0;i<myVector.size();i++)
        answer.push_back(myVector[i].s);
    
    return answer;
}

int main() {

    vector<string> strings;
    strings.push_back("sun");
    strings.push_back("bed");
    strings.push_back("car");

    vector<string> result = solution(strings, 1);
    
    for(int i=0;i<result.size();i++) {
        for(int j=0;j<result[i].size();j++) {
            printf("%c", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}