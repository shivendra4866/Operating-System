#include<bits/stdc++.h>
#include<thread>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

void fcfs()
{
// {{arr time,burst_time},pid}
vector<pair<pair<int,int>,int>>process={{{1,2},1},{{2,4},2},{{4,5},3}};
sort(process.begin(),process.end());
int time=0;
vector<int>completion_time((int)process.size()+1,-1);
for(int i=0;i<(int)process.size();i++)
{
completion_time[process[i].second]=max(time,process[i].first.first)+process[i].first.second;
time=completion_time[process[i].second];
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
fcfs();
return 0;
}