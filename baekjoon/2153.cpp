// 소수 단어
#include<bits/stdc++.h>
using namespace std;
string s;
int sum;
bool isPrime(int x) {
  if(x==0) return false;
  if(x==1) return true;
  for(int i=2;i<=sqrt(x);i++) {
    if(x%i==0) return false;
  }
  return true;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>s;
    for(auto c:s) {
        if(c>='a'&&c<='z') sum+=c-'a'+1;
        else if(c>='A'&&c<='Z') sum+=c-'A'+27;
    }
    if(isPrime(sum)) cout<<"It is a prime word."<<'\n';
    else cout<<"It is not a prime word."<<'\n';
    return 0;
}