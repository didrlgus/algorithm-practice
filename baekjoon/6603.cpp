// 6603. 로또
#include<iostream>
using namespace std;

int a[15];
int result[15];
int k;
 
void dfs(int current, int depth) {
    
    if(depth == 6) {                    
        for(int i=0; i<6; i++) {
            cout << result[i] << ' ';    
        }
        cout << '\n';
        return;
    }
                                        
    for(int i=current; i<k; i++) {      
        result[depth] = a[i];    
        dfs(i+1, depth+1);
    }
    
}
 
int main() {
    while(cin >> k && k) {            
        for(int i=0; i<k; i++) cin >> a[i];
        
        dfs(0,0);
        cout << '\n';
    }
    return 0;
}