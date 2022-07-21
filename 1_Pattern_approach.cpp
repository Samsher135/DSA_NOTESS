#include <iostream>
using namespace std;

//1. find the number of rows and columns required in pattern.
//2. divide the pattern in subpatterns.
//3. find logic to print the subpatterns according to the columns.
//4. run the code to see complete pattern.

int main(){
    int n = 5;
    int counter = 1;
    int adder = 3;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n*2; j++){
            if(j<=(n+(i-1))){
                if(j<=(n-(i-1))){
                    cout << j << " ";
                }else{
                    cout << "* ";
                }
            }else{
                cout << (j-counter) << " ";
                counter += 2;
            }
        }
        cout << endl;
        counter = adder;
        adder += 2;
    }

    return 0;
}