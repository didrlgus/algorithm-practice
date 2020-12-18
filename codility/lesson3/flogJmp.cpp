#include<bits/stdc++.h>
using namespace std;
int solution(int x, int y, int d) {
    if((y-x)%d==0) return (y-x)/d;
    else return (y-x)/d+1;
}