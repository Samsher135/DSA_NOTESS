//pointers
//pointers are variables that store the address of another variable
//size of a pointer is 8 bytes always because it stores hexadecimal address

#include<iostream>
using namespace std;

//pointers basics
void basics() {
//accessing pointer pointing to null address or address which does not exist
   int *p = 0; 
//will give segmentation fault
   cout << *p << endl;

//important concept
   int i = 3;
   int *t = &i;
//below it is same as *t = *t + 1; means assign value pointed by t + 1 to the value pointed by t
   cout <<  (*t)++ << endl;
   *t = *t +1;
    cout << *t << endl;
    cout << " before t " << t << endl;
//below will increment the address of t by 4 bytes because int is of 4 bytes
    t = t + 1;
    cout << " after t " << t << endl;
    return;
}

//pointers and arrays

void p_a() {

    int arr[10] = {23, 122, 41, 67};

    cout <<" address of first memory block is " << arr << endl;
    cout << arr[0] << endl;
    cout <<" address of first memory block is " << &arr[0] << endl; // same as arr gives address of first memory block

    cout << "4th " << *arr << endl;
    cout << "5th " << *arr + 1 << endl; // same as arr[0] + 1
    cout << "6th " << *(arr + 1) << endl; // same as arr[1]
    cout << "7th " << *(arr) + 1 << endl; // same as arr[0] + 1
    cout << "8th " << arr[2] << endl;
    cout << "9th " << *(arr+2) << endl; // same as arr[2]

    int i = 3;
    cout << i[arr] << endl; // same as arr[3] not a syntax error


   int temp[10] = {1,2};
   cout << sizeof(temp) << endl; // 40 bytes because 4*10
   cout << " 1st " <<  sizeof(*temp) << endl; // 4 bytes because int is of 4 bytes
   cout << " 2nd " <<  sizeof(&temp) << endl; // 8 bytes because address is of 8 bytes

   int *ptr = &temp[0]; //same gives address of first memory block
   cout << sizeof(ptr) << endl ;
   cout << sizeof(*ptr) << endl ;
   cout << sizeof(&ptr) << endl ;



   int a[20] = {1,2,3,5};
   //cout << " ->" << &a[0] << endl;
  // cout << &a << endl;
   //cout << a << endl;

   int *p = &a[0];
   //cout << p << endl;
   //cout << *p << endl;
   cout << "-> " << &p << endl;


   int arr[10];

   //ERROR because we are changing the address of array mapped in symbol table
   //arr = arr+1;

    int *ptr = &arr[0];
    cout << ptr << endl;
    //here we can do this because we are changing the address stored in pointer not the address of pointer
    ptr = ptr + 1;
    cout << ptr << endl;

    return ;
}

//pointers and char arrays

void p_c() {

    int arr[5] = {1,2,3,4,5};
    char ch[6] = "abcde";


    cout << arr << endl; // prints address of first memory block
    //attention here
    cout << ch << endl; // prints the string abcde because implementation of char array is different in cout class
    
    char *c = &ch[0]; //store address of first memory block
    //prints entire string
    cout << c << endl; //again prints the whole string abcde till null character

    char temp = 'z';
    char *p = &temp; //bad practice because their is no null character at the end of temp and it will print garbage values

    cout << p << endl;

    return;
}

//pointers and functions
class p_f {
    int getSum(int arr[], int n) {//same as int *arr
        //here size of arr is not 4*6 because when we pass array to function the address is passed hence the size of address is 8 bytes 
        cout << endl << "Size : " << sizeof(arr) << endl;

        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += arr[i];
        }
        return sum;
    }
    public:
    void p_fun() {

        int arr[6] = {1,2,3,4,5,8};

        cout << "Sum is " << getSum(arr+3 ,3) << endl ;  

        return;
    }
};


//Types of pointers

//1. Null pointer
//A null pointer is a pointer pointing to nothing or address which does not exist
//Eg:-
//int *p = 0;
//int *p = NULL;

//2. double pointers
//double pointers are pointers that store the address of another pointer

class doub_p {
    public:
    void d_p() {
        int i = 10;
        int *p = &i;
        int **q = &p;

        cout << "i : " << i << endl;
        cout << "p : " << p << endl;
        cout << "*p : " << *p << endl;
        cout << "q : " << q << endl; //address of p
        cout << "*q : " << *q << endl; //address of i
        cout << "**q : " << **q << endl; //value of i
        return;
    }
};

//3. void pointer
//void pointer is a pointer that can point to any type of data but when using it we have to type to that specific data type
//Eg:-
void v_ptr(){
    int i = 10;
    void *p = &i;
    //cout << *p << endl; //error
    cout << *(int *)p << endl; //typecast to int and then dereference
    return;
}

//4. wild pointer
//A wild pointer is a pointer that is only declared but not initialized, so it points to some random address and becomes wild.
//Eg:-
void w_ptr(){
    int *p;
    cout << p << endl; //prints some random address
    return;
}

//5. dangling pointer
//A dangling pointer is a pointer that points to a memory location that is no longer valid i.e it is freed or deleted.
//There are three scenarios in which a pointer becomes dangling:-

//a.function call
//when a pointer is excepting address of a local variable from a function then it becomes dangling after the function call
//Eg:-
class dangling1 {
    public:
    int *fun() {
        int i = 10;
        return &i;
    }
    void d_p() {
        int *p = fun();
        cout << *p << endl; //error because i is destroyed after function call
        return;
    }
};

//b. deallocation of memory
//when a pointer is excepting address of a dynamically allocated memory then it becomes dangling after the memory is deallocated
//Eg:-
class dangling2 {
    public:
    void d_p() {
        int *p = new int(10);
        delete p;
        cout << *p << endl; //error because memory is deallocated
        return;
    }
};

//c. variable goes out of scope
//Eg:-
class dangling3 {
    public:
    void d_p() {
        int *p = new int(10);
        {
            int i = 10;
            p = &i;
        }
        cout << *p << endl; //error because i is destroyed after scope
        return;
    }
};  
