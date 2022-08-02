#include <bits/stdc++.h>
using namespace std;

//references in c++
//When a variable is declared as a reference, it becomes an alternative name for an existing variable. 
//A variable can be declared as a reference by putting ‘&’ in the declaration. 


//static memory allocation
//In static memory allocation, the memory is allocated at compile time.
//It is also get automatically deallocated when the program or scope ends.
//disadvantage is that we have to specify the size of array at compile time else the program will crash because of following reasons:-
//1. In static memory allocation, the stack memory is used.
//2. The stack memory is limited in size which is decided at compile time.
//3. If we try to allocate more memory in run time than the stack size, the program will crash.
//Eg:-
void runtimestaticalloc(){
    int n;
    cin>>n;
    int arr[n]; //if we give n > 1000000 in run time then the program will crash
    memset(arr,0,sizeof(arr));
    for(int i=0; i<n; i++){
        cout << arr[i];
    }
    return;
}

//dynamic memory allocation
//In dynamic memory allocation, the memory is allocated at run time.
//The memory is allocated in heap memory.
//The memory is allocated using new operator, it returns the address of the first memory block of the allocated memory.
//The memory is deallocated using delete operator.
//Eg:-
void runtimedynamicalloc(){
    int n;
    cin>>n;
    int *arr = new int[n]; //if we give n > 1000000 in run time then the program will not crash
    //fill all values of array with 1
    for(int i=0; i<n; i++){
        arr[i] = 1;
    }
    for(int i=0; i<n; i++){
        cout << arr[i];
    }
    delete [] arr;
    return;
}


//Note:-
//1. The memory allocated in heap memory is not automatically deallocated when the program or scope ends.
//2. We have to deallocate the memory manually using delete operator.
//3. If we do not deallocate the memory, it will lead to memory leak or program will crash.
//Eg:-
void memoryleak(){
    int n = 5;
    //This pointer *arr is stored in stack memory and it is automatically freed 
    //but this array of size n is stored in heap memory and it is not automatically freed    
    while (1)
    {        
        int *arr = new int[n];
    }
    return;
}

//dynamic memory allocation of 2d array
//first create array of pointers of size n and store the first address of this array of pointers in a double pointer
//then create array of size m and store the first address of this array in each pointer of array of pointers
//Eg:-
void runtimedynamicalloc2d(){
    int n,m;
    cin>>n>>m;
    int **arr = new int*[n]; //int* arr[n] creates array of pointers of size n
    for(int i=0; i<n; i++){
        arr[i] = new int[m]; //at each index of array of pointers create array of size m and the first address.
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << arr[i][j];//arr[i][j] is same as *(*(arr+i)+j)
        }
    }
    for(int i=0; i<n; i++){
        delete [] arr[i];
    }
    delete [] arr;
    return;
}

//jagged array
//It is an array of arrays in which each row can have a different number of columns.
//we can do it in both static and dynamic way
void jagged(){
    int n;
    cin>>n;
    //array to store size of each row
    int *rowSize = new int[n];
    int **arr = new int*[n];
    for(int i=0; i<n; i++){
        int m;
        cin>>m;
        rowSize[i] = m;
        arr[i] = new int[m];
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<rowSize[i]; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //delete the memory
    for(int i=0; i<n; i++){
        delete [] arr[i];
    }
    delete [] arr;
    return;
}

int main(){
    runtimedynamicalloc();
    return 0;
}