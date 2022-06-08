/*
You want to design a function that takes a single line of arbitrarily long text,
and then inserts newlines so that no single line is longer than 40 characters long,
 and new line characters are not inserted inside of words, but only inside whitespace
 characters. Ensure that each line is as close to 40 characters as possible.
 */

#include <bits/stdc++.h>
using namespace std;

string splitWords(string str)
{
    int length = str.length();

    int count = 40;
    vector<string> result;

    int index = 0;
    while (length>0)
    {
        int count = 0;
        int initial = index;
        int lastWordIndex = index;
        string sentence = "";
        while (count < 40)
        {  
            lastWordIndex = index;//7
            string word;
            while (str[index] != ' ')
            {
                word.push_back(str[index]);
                index++;
                count++;
            }

            if (count < 40)
            {
                sentence = sentence + " "+ word;
                count++;
                index++;
            }
            else
            {
                index = lastWordIndex;
            }
        }
        result.push_back(sentence);

        // select word

        length-=(index-initial);
    }
    for(int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<endl;
    }

    return "";
}

int main()
{

    string str = "Arvind Gaurav Ruchi Amrendra";
    string s = splitWords(str);


    return 0;
}
