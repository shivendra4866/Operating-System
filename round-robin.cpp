#include<bits/stdc++.h>
#include <Windows.h>
#include<thread>
using namespace std;
void round_robin(){
    // {arr time,burst time} , here pid will be the index of process
    int quantum=1;
    vector<vector<int> >process={{2,4},{3,6},{4,5}};
    vector<int>rem_bt((int)process.size());
    for(int i=0;i<(int)process.size();i++){
        rem_bt[i]=process[i][1];
    }
    bool flag=false,f=false;
    int curr_time=0;
    vector<int>completion_time((int)process.size());
    int lapse=100000;
    while(!flag){
        flag=true;
        f=false;
        for(int i=0;i<(int)rem_bt.size();i++){
            if(process[i][0]<=curr_time && rem_bt[i]>0){
                flag=false;
                f=true;
                if(rem_bt[i]>quantum){
                    curr_time+=quantum;
                    rem_bt[i]-=quantum;
                }
                else{
                    curr_time+=rem_bt[i];
                    rem_bt[i]=0;
                    completion_time[i]=curr_time;
                }
            }
            if(process[i][0]>curr_time){
                lapse=min(lapse,process[i][0]);
                flag=false;
                }
        }
        if(!f){
            curr_time=lapse;
        }
        if(flag){
            break;
        }
    }
    cout<<"pid        completion time\n";
    for(int i=0;i<(int)completion_time.size();i++){
        cout<<i<<"         "<<completion_time[i]<<endl;
    }
}
int main(){
    round_robin();
    return 0;
}