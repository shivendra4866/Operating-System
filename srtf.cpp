#include<bits/stdc++.h>
using namespace std;
struct process{
int arr_time,burst_time,pid;
};
bool compare(process p1, process p2) { 
    return (p1.arr_time < p2.arr_time); 
} 
struct comp { 
    bool operator()(process const& p1, process const& p2) { 
        return p1.burst_time > p2.burst_time; 
    } 
}; 
void srtf(){
    vector<process>p={{1,4,1},{0,2,3},{2,4,2}};
    sort(p.begin(),p.end(),compare);
    priority_queue<process,vector<process>,comp>pq;
    int curr_time=p[0].arr_time;
    pq.push(p[0]);
    int i=1;
    vector<int>completion_time((int)p.size()+1,-1);
    while(!pq.empty() || i<(int)p.size()){
     while(i<(int)p.size() && p[i].arr_time<=curr_time){
         pq.push(p[i]);
         i++;
     }
     if(!pq.empty()){
          process pr=pq.top();
          pq.pop();
          pr.burst_time--;
          if(pr.burst_time>0){
           pq.push(pr);
          }
          else{
          completion_time[pr.pid]=curr_time+1;   
          }
     }
     curr_time++;
    }
    cout<<"pid       completion time\n";
    for(int i=0;i<(int)completion_time.size();i++)   {
        if(completion_time[i]!=-1){
            cout<<i<<"        "<<completion_time[i]<<endl;
        }
    }
}
int main()
{
srtf();
return 0;
}