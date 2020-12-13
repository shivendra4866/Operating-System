#include<bits/stdc++.h>
#include<thread>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;
// priority scheduling without premption
void priority()
{
    // {arr time , priority ,burst time ,procss id }
    // 1 is highly prioritised
    vector<vector<int> >process={{1,3,4,1},{0,1,2,3},{2,3,4,2}};
    sort(process.begin(),process.end());
    int curr_time=0;
    vector<int>completion_time((int)process.size()+1,-1);
    for(int i=0;i<(int)process.size();i++)
    {
        completion_time[process[i][3]]=max(curr_time,process[i][0])+process[i][2];
        curr_time=completion_time[process[i][3]];
    }
    cout<<"pid  completion time\n";
    for(int i=0;i<(int)completion_time.size();i++)
    {
     if(completion_time[i]!=-1)
     {
      cout<<i<<"   "<<completion_time[i]<<endl;
     }
    }
}

int main()
{
thread t1(priority);
t1.join();
return 0;
}