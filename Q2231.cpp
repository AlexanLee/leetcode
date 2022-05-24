#include <iostream>
#include <vector>

using namespace std;
/**
 * 给你一个正整数 num 。你可以交换 num 中 奇偶性 相同的任意两位数字（即，都是奇数或者偶数）。返回交换 任意 次之后 num 的 最大 可能值。
 */

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
    int largestInteger(int num) {
        string s=to_string(num);
        for(int i=0;i<s.size();i++){
            // for(int j=s.size()-1;j>=i;j--){
            for(int j=i+1;j<s.size();j++){
                if(s[j]>s[i] && (s[j]-s[i])%2 == 0){
                    swap(s[i],s[j]);
                }
            }
        }
        return stoi(s);
    }
};

int main(){
    cout<<"main"<<endl;

    int num=12345;
    Solution sl;
    cout<<sl.largestInteger(num)<<endl;

    return 0;
}