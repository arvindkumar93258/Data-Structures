#include<bits\stdc++.h>
using namespace std;


/*
    angel = glean
	brag = grab
	cat = act
	inch = chin
    int arr[26];
    arr[0]=1;

*/
bool isAnagram(string s1, string s2)
{
    int arr[26];
    for(int i=0; i<26; i++)
    {
        arr[i]=0;
    }

    int length1 = s1.length();
    int length2= s2.length();

    int index1=0;
    while(index1<length1)
    {
        arr[s1[index1]-'a'] +=1;//anagram
        index1++;
    }

    int index2=0;
    while(index2<length2)
    {
        arr[s2[index2]-'a']-=1;
        index2++;
    }
    for(int i=0; i<26; i++)
    {
        if(arr[i]!=0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str = "angel";
    string str2= "gleann";

    cout<<isAnagram(str, str2);

    return 0;
}