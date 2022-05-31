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
    string multiply(string num1, string num2) {
        if(num1 =="0" || num2=="0"){
            return "0";
        }
        string ans;
        int m=num1.size(),n=num2.size();

        auto ansArr=std::vector<int>(m+n);

        for(int i=m-1;i>=0;i--){
            int x=num1.at(i)-'0';
            for(int j=n-1;j>=0;j--){
                int y=num2.at(j)-'0';
                ansArr[i+j+1] += x*y;
            }
        }

        for(int i=m+n-1;i>0;i--){
            ansArr[i-1] += ansArr[i]/10;
            ansArr[i] %= 10;
        }

        int index=ansArr[0]==0 ?1:0;
        while(index<m+n){
            ans.push_back(ansArr[index]);
            index++;
        }
        for(auto &c:ans){
            c += '0';
        }
        return ans;
    }
};

int main(){
    cout<<"main"<<endl;
    Solution sl;
   
    cout<<sl.multiply("123","456")<<endl;
    return 0;
}