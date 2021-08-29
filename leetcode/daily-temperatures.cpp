// daily-temperatures
#include<vector>
#include<algorithm>
#include<stack>
#include<stdio.h>

using namespace std;

struct p {
    int idx;
    int temperature;
};

stack<p> stk;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int N=temperatures.size();
    vector<int> ret(N,0);

    stk.push({0,temperatures[0]});
    
    for(int i=1;i<(int)temperatures.size();i++) {
        int cur_temperature=temperatures[i];
        while(!stk.empty() && stk.top().temperature<cur_temperature) {
            ret[stk.top().idx]=i-stk.top().idx;
            stk.pop();
        }
        stk.push({i,cur_temperature});
    }
    return ret;
}

int main() {

    vector<int> temp={73,74,75,71,69,72,76,73};
    vector<int> ret = dailyTemperatures(temp);

    for(auto it:ret) printf("%d ",it);

    return 0;
}