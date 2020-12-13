#include <stdio.h> 
#include <sys/types.h> 
int main() 
{ 
    fork(); 
    fork(); 
    fork(); 
    cout<<"childs pid"<<getpid()<<"   parent pid"<<getppid()<<endl; 
    return 0; 
} 