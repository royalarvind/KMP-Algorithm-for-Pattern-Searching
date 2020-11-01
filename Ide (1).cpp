#include <bits/stdc++.h>
using namespace std;

int main() {
	string str, ptr;
	cin>>str>>ptr;
	int n=str.length();
	int m = ptr.length();
	int lps[n];
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
	
	i=0,j=0;
	vector<int> v;
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
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	return 0;
}
