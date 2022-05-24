#include <iostream>
#include <vector>

using namespace std;

//字符的最短距离：给你一个字符串 s 和一个字符 c ，且 c 是 s 中出现过的字符。
//返回一个整数数组 answer ，其中 answer.length == s.length 且 answer[i] 是 s 中从下标 i 到离它 最近 的字符 c 的 距离 。

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
    vector<int> shortestToChar(string s, char c) {
        timer t("shortestToChar");
        int n=s.length();
        vector<int> answer(n);
        for(int i=0,idx=-n;i<n;i++){
            if(s[i]==c){
                idx=i;
            }
            answer[i]=i-idx;
        }

        for(int i=n-1,idx=2*n;i>=0;--i){
            if(s[i]==c){
                idx=i;
            }
            answer[i]=min(answer[i],idx-i);
        }   
        return answer;
    }

    vector<int> shortestToChar_2(string s,char c){
        timer t("shortestToChar_2");
        int n = s.size();
        vector<int> p;
        for(int i=0; i<n; i++){
            if(s[i] == c){
                p.push_back(i);
            }
        }
        vector<int> res;
        for(int i=0; i<n; i++){
            if(s[i] == c){
                res.push_back(0);
            }else{
                int t = INT_MAX;
                for(auto c : p){
                    if(abs(c-i) < t){
                        t = abs(c-i);
                    }
                }
                res.push_back(t);
            }
        }
        return res;
    }
};

int main(){
    cout<<"main"<<endl;

    string s="loveleetcode";
    char c='e';

    Solution sl;
    vector<int> ans;
    ans=sl.shortestToChar(s,c);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}