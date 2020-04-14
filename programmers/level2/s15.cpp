// 가장 큰 수
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;

    for(int i=0;i<numbers.size();i++) {
        v.push_back(to_string(numbers[i]));
    }

    sort(v.begin(),v.end(),cmp);
    
    if(v[0]=="0") return "0";

    for(int i=0;i<v.size();i++) answer+=v[i];

    return answer;
}

int main() {

    vector<int> numbers={10000,1000,100,10,1};

    string result=solution(numbers);
    cout<<result<<endl;

    return 0;
}