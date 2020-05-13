// 팰린드롬 만들기
#include<bits/stdc++.h>

using namespace std;

string s;
int arr[110],cnt;
char mid;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>s;

    for(char c:s) arr[c]++;

    string ret="";
    for(int i='Z';i>='A';i--) {
        if(arr[i]) {            // 알파벳이 존재할 경우
            if(arr[i]&1) {      // 홀수일 경우
                cnt++;
                mid=char(i);
                arr[i]--;
            }
            if(cnt>=2) break;
            for(int j=0;j<arr[i];j+=2) {
                ret=char(i)+ret;
                ret+=char(i);
            }
        }
    }
    // 홀수개의 알파벳이 있는경우
    if(mid) ret.insert(ret.begin()+ret.size()/2,mid);
    
    if(cnt>=2) cout<<"I'm Sorry Hansoo\n";
    else cout<<ret<<"\n";

    return 0;
}
