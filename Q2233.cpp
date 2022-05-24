#include <iostream>
#include <vector>

using namespace std;


class timer{
public:
    clock_t start;
    clock_t end;
    string name;
    timer(string n){
        start=clock();
        name=n;
    }
    ~timer(){
        end=clock();
        printf("%s time: %f\n", name.c_str(),(end-start)*1.0/CLOCKS_PER_SEC*1000);
    }
    
};

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
    	timer t("maximumProduct");
    	int mod=1000000007;
    	make_heap(nums.begin(),nums.end(),greater<int>());

    	while(k--){
    		pop_heap(nums.begin(),nums.end(),greater<int>());
    		++nums.back();
    		push_heap(nums.begin(),nums.end(),greater<int>());
    	}
    	int res=1;
    	for(auto num:nums){
    		res=(long long)num*res%mod;
    	}
        return res;
    }
};


int main(){

	vector<int> nums;

	for(int i=0;i<3;i++){
		nums.push_back(i);
	}
	Solution sl;
    cout<<sl.maximumProduct(nums,3)<<endl;
	return 0;
}