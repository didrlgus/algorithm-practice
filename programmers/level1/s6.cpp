// 2016년
#include <string>
#include <vector>

using namespace std;

int date[] = {31,29,31,30,31,30,31,31,30,31,30,31};
string day[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    
string solution(int a, int b) {
    string answer = "";
    
    int d = a-1;        // 4
    int x = 0;
    
    for(int i=0;i<d;i++) {
        x+=date[i];
    }
    
    x+= b-1;
    
    int r = (5 + (x%7))%7;
    
    answer = day[r];
    
    return answer;
}

int main() {

    string result = solution(5, 24);

    for(int i=0;i<result.size();i++) printf("%c",result[i]);

    return 0;
}