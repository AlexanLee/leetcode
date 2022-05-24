#include <iostream>
#include <vector>

using namespace std;
/**
给你一个下标从 0 开始的字符串 expression ，格式为 "<num1>+<num2>" ，其中 <num1> 和 <num2> 表示正整数。
请你向 expression 中添加一对括号，使得在添加之后， expression 仍然是一个有效的数学表达式，并且计算后可以得到 最小 可能值。左括号 必须 添加在 '+' 的左侧，而右括号必须添加在 '+' 的右侧。
返回添加一对括号后形成的表达式 expression ，且满足 expression 计算得到 最小 可能值。如果存在多个答案都能产生相同结果，返回任意一个答案。
生成的输入满足：expression 的原始值和添加满足要求的任一对括号之后 expression 的值，都符合 32-bit 带符号整数范围。

我们可以使用枚举的方法得到所有满足要求的表达式，计算每一个表达式的结果并选出最小值。

具体地，我们首先在给定的字符串 \textit{expression}expression 中定位到加号的位置，记为 \textit{mid}mid。由于「左括号必须添加在加号的左侧，右括号必须添加在加号的右侧」，因此我们可以枚举两个位置 ii 和 jj，将字符串分成五部分，即：

[0, i)[0,i)，对应的数值记为 pp；
[i, \textit{mid})[i,mid)，对应的数值记为 qq；
\textit{mid}mid 位置上的加号；
(\textit{mid}, j](mid,j]，对应的数值记为 rr；
(j, n)(j,n)，对应的数值记为 ss，其中 nn 是字符串 \textit{expression}expression 的长度；
那么表达式的值即为 p \times (q+r) \times sp×(q+r)×s。特别地，如果 i = 0i=0 或者 j = n-1j=n−1，那么 [0, i)[0,i) 或者 (j, n)(j,n) 是空串，我们可以特判其对应的数值为 11。
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
    string minimizeResult(string expression) {
        timer t("minimizeResult");
        string ans;
        int n=expression.size();
        int mid=expression.find("+");
        int best=INT_MAX;
        for(int i=0;i<mid;i++){
            for(int j=mid+1;j<n;j++){
                int p=(i==0?1:stoi(expression.substr(0,i)));
                int q=stoi(expression.substr(i,mid-i));
                int r=stoi(expression.substr(mid+1,j-mid));
                int s=(j==n-1?1:stoi(expression.substr(j+1,n-j-1)));
                int result=p*(q+r)*s;
                if(result<=best){
                    best=result;
                    ans=expression.substr(0,i)+"("+expression.substr(i,j-i+1)+")"+expression.substr(j+1,n-j-1);
                }
            }
        }
        return ans;
    }
};

int main(){
    cout<<"main"<<endl;
    Solution sl;
    cout<<sl.minimizeResult("10+11")<<endl;
    return 0;
}