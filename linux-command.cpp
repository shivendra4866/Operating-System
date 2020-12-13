#include<bits/stdc++.h>
using namespace std;

int lcs( string X, string Y, int m, int n )  
{  
    int L[m + 1][n + 1];  
    int i, j;  
    for (i = 0; i <= m; i++)  
    {  
        for (j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            L[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            L[i][j] = L[i - 1][j - 1] + 1;  
      
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
        }  
    }  
    return L[m][n];  
}  
int main()
{
ifstream fin;
ofstream fout;
string s;
while(true)
{
cout<<"\n$";
cin>>s;
       if(s=="echo")
       {
         string t;
         cin>>t;
         cout<<t;
        }
        else if(s=="cmp")
        {
         string t1,t2;
         cin>>t1>>t2;
         cout<<lcs(t1,t2,t1.length(),t2.length());
         }
         else if(s=="diff")
        {
        string t1,t2;
        cin>>t1>>t2;
        cout<<t1.length()-lcs(t1,t2,t1.length(),t2.length());
         }
        else if(s=="cat")
        {
        string t;
        cin>>t;
        fin.open(t,ios::in);
         cout<<"file created successfully";
         fin.close();
         }
         else if(s=="copy")
         {
        string t1,t2;
        cin>>t1>>t2;
        fin.open(t1,ios::in);
        fin.open(t2,ios::out);
        char ch;
        char line[75];
        int i = 1;
        while(fin.get(ch))
        {
               fin.get(line,75,'.');
               fout<<"Line "<<i<<" : "<<line<<endl;
                i++;
        }
        fin.close();
        fout.close();
        }
        else if(s=="q")
        {
        break;
        }
        else if(s=="h" || s=="help")
        {
            cout<<"cmp : to compare 2 strings\ndiff : find the difference between two string\n cat : create file\n q : exit";
            cout<<"\nh or help : to find help";
        }
        else{
        cout<<"command not found";
        }
}
return 0;
}
