#include <bits/stdc++.h>
using namespace std;

//program to crash the code when memory to array is allocated at runtime
int main(){
    int n = 5;
    while (1)
    {
        int *arr = new int[n];
    }
    
    return 0;
}