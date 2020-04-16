// 폰켓몬
#include <vector>
#include <set>
#include <cstdio>

using namespace std;

int solution(vector<int> nums) {
	int answer = 0;

    set<int> set;

    for(int i=0;i<nums.size();i++) set.insert(nums[i]);

    int n=nums.size()/2;
    if(n<=set.size()) {
        answer=n;
    } else {
        answer=set.size();
    }

	return answer;
}

int main() {

    vector<int> nums={3,3,3,2,2,4};
    int result=solution(nums);
    printf("%d\n",result);

    return 0;
}