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
    float auc(std::vector<float> predicts,std::vector<int> labels){
        timer t("auc");
        int numerator=0;
        int denominator=0;

        for(int i=0;i<predicts.size()-1;i++){
            for(int j=i;j<predicts.size();j++){
                if (labels[i] != labels[j]){
                    denominator+=1;
                    if((labels[i]>labels[j] && predicts[i]>predicts[j])
                        ||(labels[i]<labels[j]&&predicts[i]<predicts[j])){
                        numerator+=1;
                    }
                }
            }
        }
        cout<<numerator<<":"<<denominator<<endl;
        if(denominator==0)
            return 0.0;
        return (float)numerator/denominator;
    }
};

int main(){
    cout<<"main"<<endl;

    vector<float> predicts;
    float predicts_arr[10]={0.9, 0.4, 0.3, 0.1, 0.35, 0.6, 0.65, 0.32, 0.8, 0.7};

    for(int i=0;i<sizeof(predicts_arr)/sizeof(predicts_arr[0]);i++){
        predicts.push_back(predicts_arr[i]);
    }

    vector<int> labels;
    int labels_arr[10]={1,   0,   0,   0,   1,    0,   1,    0,    0,   1};

    for(int i=0;i<sizeof(labels_arr)/sizeof(labels_arr[0]);i++){
        labels.push_back(labels_arr[i]);
    }

    Solution sl;
    cout<<sl.auc(predicts,labels)<<endl;
    return 0;
}