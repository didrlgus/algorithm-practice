// 14889. 스타트와 링크
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int a[25][25];
int n;
bool check[25];

int min_=987987987;

void func(int player, int current) {
    // base condition
    if(current>=n/2) {
        vector<int> start,link;
        int sum1=0,sum2=0;

        for(int i=0;i<n;i++) {
            if(check[i]) start.push_back(i);
            else link.push_back(i); 
        }

        for(int i=0;i<start.size();i++) {
            for(int j=i+1;j<start.size();j++) {
                sum1+=a[start[i]][start[j]]+a[start[j]][start[i]];
                sum2+=a[link[i]][link[j]]+a[link[j]][link[i]];
            }
        }

        min_=min(min_,abs(sum1-sum2));
    } else {
        for(int i=player;i<n;i++) {
            if(!check[i]) {
                check[i]=true;
                func(i+1,current+1);
                check[i]=false;
            }
        }
    }
}

int main() {

    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf("%d", &a[i][j]);
    }

    func(0,0);

    printf("%d\n",min_);

    return 0;
}