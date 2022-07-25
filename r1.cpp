#include <bits/stdc++.h>
using namespace std;

int palindromeCost(string str, int x, int y)
{
	int start =0;
    if(str.length()%2!=0)
    {
        return -1;
    }
	int end = str.length()-1;
    

	int cost = 0;
	//  aba/bab/
	while(start<end)
	{
		if(str[start]==str[end]){
			start++;
			end--;
			continue;
		}
		if(str[start]=='/' || str[end]=='/')
		{
			if(str[start]=='/'){
				if(str[end]=='a'){
					cost+=x;
				}
				else if(str[end]=='b'){
					cost+=y;
				}else{
					return -1;
				}
			}
			else{
				if(str[start]=='a'){
                    cost+=x;
                }
				else if(str[start]=='b'){
                    cost+=y;
                }
				else{
                    return -1;
                }
			}
			start++; end--;
		}
		else {  return -1; }

	}
    return cost;
}

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T)
	{
		string str;
		cin>>str;
		int x;
		cin>>x;
		int y;
		cin>>y;
		cout<<palindromeCost(str, x, y)<<endl;
        T--;

	}
	return 0;
}
