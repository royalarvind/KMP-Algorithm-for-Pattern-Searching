#include <bits/stdc++.h>
using namespace std;
void Calculate_LPS(string str, string ptr, int* lps)
{
    int n=str.length();
	int m = ptr.length();
    int i=1,j=0;
	lps[0]=0;
	while(i<m)
	{
	    if(ptr[i]==ptr[j])
	    {j++;
	    lps[i]=j;
	    i++;}
	    else if(j==0)
	    {lps[i]=0;
	    i++;}
	    else
	    j = lps[j-1];
	}
}

void FindPatternIndex(string str, string ptr, int* lps, vector<int> &v)
{
    int n=str.length();
	int m = ptr.length();
    int i=0,j=0;
    while(i<n)
	{
	    if(j==m)
	    {
	        v.push_back(i-j);
	        j = lps[j-1];
	        continue;
	    }
	    if(str[i]!=ptr[j]&&j==0)
	    {
	        i++;
	        continue;
	    }
	    if(str[i]!=ptr[j])
	    {
	        j = lps[j-1];
	    }
	    if(str[i]==ptr[j])
	    {
	        i++;
	        j++;
	    }
	}
	if(j==m)
	    {
	        v.push_back(i-j);
	        
	    }
}
int main() {
	string str, ptr;
	cin>>str>>ptr;
	int n=str.length();
	
	// lps array stores Longest Proper prefix which is also a suffix upto that index in ptr string 
	int lps[n];
	
	// Calculate_LPS finds lps of any given string
	Calculate_LPS(str, ptr, lps);
	int i=0,j=0;
	
	//vector v stores indexes at which given pattern is found
	vector<int> v;
	
	// FInd the index at which pattern is found
	FindPatternIndex(str, ptr, lps, v);
	
	
	
	//Print all indexes where pattern is found
	for(int i=0;i<v.size();i++)
	{   
	    cout<<"Pattern found at index"<<" ";
	    cout<<v[i]+1<<endl;
	    
	}
	return 0;
}
