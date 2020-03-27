// 14501. 퇴사
#include<cstdio>
#include<vector>

using namespace std;

int n;
struct s {
    int t;
    int p;
};

vector<s> v;
int max_=-987987987;

void dfs(int current,int sum) {
    if(current==n) {
        max_=max(max_,sum);
        return;
    }
    if(current>n) return;

    // pick
    dfs(current+v[current].t,sum+v[current].p);
    // pass
    dfs(current+1,sum);
}

int main() {

    scanf("%d",&n);

    for(int i=0
    ;i<n;i++) {
        int a,b;
        scanf("%d %d",&a,&b);

        v.push_back({a,b});
    }

    dfs(0,0);

    printf("%d\n",max_);

    return 0;
}