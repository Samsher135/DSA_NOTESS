// to convert upper case to lower case
//(char - 'A') + 'a'

#include <bits/stdc++.h>
using namespace std;

// difference between character array and string
// 1. character array is a fixed size array
// 2. string is a dynamic size array
int main()
{
    // null character in both cases
    // case 1
    char arr[] = "hel\0lo";
    // after null character there is no more character stored
    string str = "hel\0lo";
    // case 2
    char a[9];
    string b;
    for (int i = 0; i < 6; i++)
    {
        if (i == 3)
        {
            a[i] = '\0';
            // null character is not stored in string and skipped
            b.push_back('\0');
        }
        else
        {
            a[i] = 'a';
            b.push_back('a');
        }
    }

    cout << a << endl;
    cout << b << endl;
    cout << arr << endl;
    cout << str << endl;
    return 0;
}

// output:-
//  aaa
//  aaaaa
//  hel
//  hel

// Function to find the maximum occurring character in a string.
// The approach is uses the concept of position of every character from 1 to 26
// and stores the count of each character in the array.
char getMaxOccuringChar(string str)
{
    // Your code here
    int n = str.size();
    int index;
    vector<int> v(26, 0);

    for (int i = 0; i < n; i++)
    {
        index = str[i] - 'a';
        v[index]++;
    }

    int max = INT_MIN, max_index = 0;

    for (int i = 0; i < 26; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
            max_index = i;
        }
    }

    return max_index + 'a';
}


//replace spaces with @40
//The approach is derived from the idea resize the string by stlen + (spacecount * 2) also their are spaces in the string
//we will traverse the string from the end and if space not found then we will copy the character to the new space
//if space found then we will start copying the @40 characters.
string replaceSpaces(string &str)
{
    // Write your code here.
    int j = 0, count = 0;
    int stlen = str.length();
    for (j = 0; j < stlen; j++)
    {
        if (str[j] == ' ')
        {
            count++;
        }
    }

    int newlength = stlen + (count * 2);
    str.resize(newlength--, '0');
    int checklen2 = str.capacity();

    for (j = stlen - 1; j >= 0; j--)
    {
        if (str[j] == ' ')
        {
            str[newlength--] = '0';
            str[newlength--] = '4';
            str[newlength--] = '@';
        }

        else
        {

            str[newlength--] = str[j];
        }
    }
    return str;
}


//remove all occurances of a string part from a string s
//so we will find the part using find function and then erase the part from the string until the part is not found
string removeOccurrences(string s, string part) {
    int firstocc = s.find(part);
    int n = part.size();
    
    while(s.length() != 0 && firstocc < s.length()){
        s.erase(firstocc, n);
        firstocc = s.find(part);
    }
    return s;
}


class removepermutation {
private:
    bool countequal(int a[26],int b[26]){
        for(int i=0;i<26;i++){
            if(a[i] != b[i]){
                return false;
            }
        }
        return true;
    }
    
public:
    //program to remove all permutations of a string s1 from a string s2
    //we will store the count of each character in the array range 0 to 25
    //we will traverse the string s2 in a window size of s1 and check if the count of each character is equal to the count of s1
    bool checkInclusion(string s1, string s2) {
        int alphacount1[26] = {0};
        int alphacount2[26] = {0};
        
        int windowsize = s1.length();
        int n = s2.length();
        int index;
        
        for(int i=0; i<windowsize; i++){
            index = s1[i] - 'a';
            alphacount1[index]++;
        }
        
        int i=0;
        while(i<windowsize && i<n){
            index = s2[i] - 'a';
            alphacount2[index]++;
            i++;
        }
        
        if(countequal(alphacount1,alphacount2)){
            return true;
        }
        
        while(i<n){
            index = s2[i] - 'a';
            alphacount2[index]++;
            
            index = s2[i - windowsize] - 'a';
            alphacount2[index]--;
            
            i++;
            if(countequal(alphacount1,alphacount2)){
            return true;
            }
        }
        return false;
    }
};


//compress a string by replacing all the consecutive repeated characters with the count of the character
//we will count the character and store the count in the same string with the character.
//return the the length of the compressed part the driver code will print the compressed string
int compress(vector<char>& chars) {
    int n = chars.size();
    int count=1;
    int ans=0;
    string str;
    
    for(int i=0; i<n; i++){
        if(i!=(n-1) && chars[i]==chars[i+1]){
            count++;
        }else{
            chars[ans++] = chars[i];
            if(count!=1){
                str = to_string(count);
                for(char it: str){
                    chars[ans++] = it;
                }
            }    
            count = 1;
        }
    }
    return ans;
}