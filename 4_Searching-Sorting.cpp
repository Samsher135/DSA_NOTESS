#include <bits/stdc++.h>
using namespace std;

// binary search using iterative method
// time complexity analysis for binary search:
// The size of array gets half in every iteration.
// after kth iteration, the size of array is 1.
// n/2^k = 1. log(n) = k.
int binarysearch(vector<int> &arr, int s, int e, int x)
{
    int st = s;
    int en = e;
    while (st <= en)
    {
        int mid = st + (en - st) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] < x)
        {
            st = mid + 1;
        }
        else
        {
            en = mid - 1;
        }
    }
    return -1;
}

// First and Last Position of an Element In Sorted Array
// This is also used to find the count of an element in a sorted array.
class Firstlast
{
public:
    int firstOcc(vector<int> &arr, int n, int key)
    {

        int s = 0, e = n - 1;
        int mid = s + (e - s) / 2;
        int ans = -1;
        while (s <= e)
        {

            if (arr[mid] == key)
            {
                ans = mid;
                e = mid - 1;
            }
            else if (key > arr[mid])
            { // Right me jao
                s = mid + 1;
            }
            else if (key < arr[mid])
            { // left me jao
                e = mid - 1;
            }

            mid = s + (e - s) / 2;
        }
        return ans;
    }

    int lastOcc(vector<int> &arr, int n, int key)
    {

        int s = 0, e = n - 1;
        int mid = s + (e - s) / 2;
        int ans = -1;
        while (s <= e)
        {

            if (arr[mid] == key)
            {
                ans = mid;
                s = mid + 1;
            }
            else if (key > arr[mid])
            { // Right me jao
                s = mid + 1;
            }
            else if (key < arr[mid])
            { // left me jao
                e = mid - 1;
            }

            mid = s + (e - s) / 2;
        }
        return ans;
    }

    pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
    {
        pair<int, int> p;
        p.first = firstOcc(arr, n, k);
        p.second = lastOcc(arr, n, k);

        return p;
    }
};

// the following approach is used to find peak element in an array.
// the idea is to find the middle element and check element is in increasing or decreasing line.
// if the mid element is smaller than the next element, then the mid is in increasing line.
// if the mid element is greater than the next element, then the mid is in decreasing line or peak element.
int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

class Sorted_rotated
{
    // to search element in a sorted rotated array following the below steps:
    // 1. find the pivot point:-
    // 1a The sorted and rotated array is divided into two parts or line.
    // 1b we can find that we are in first line or second line by comparing with the first element.
    // 1c accordingly we will move start and end pointer to the pivot element.
    // 2. binary search:-
    // 2a comparing pivot element and key, we can find search space.

    int pivots(vector<int> &arr, int n)
    {
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;

        while (s < e)
        {
            if (arr[mid] >= arr[0])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
            mid = s + (e - s) / 2;
        }
        return s;
    }

    int binarySearch(vector<int> &arr, int start, int end, int key)
    {

        int mid = start + (end - start) / 2;

        while (start <= end)
        {

            if (arr[mid] == key)
            {
                return mid;
            }

            // go to right wala part
            if (key > arr[mid])
            {
                start = mid + 1;
            }
            else
            { // key < arr[mid]
                end = mid - 1;
            }

            mid = start + (end - start) / 2;
        }

        return -1;
    }

    int findPosition(vector<int> &arr, int n, int k)
    {
        // Write your code here.
        // Return the position of K in ARR else return -1.
        int s, e;
        int pivot = pivots(arr, n);
        if (k >= arr[pivot] && k <= arr[n - 1])
        {
            s = pivot;
            e = n - 1;
            return binarySearch(arr, s, e, k);
        }
        else
        {
            s = 0;
            e = pivot - 1;
            return binarySearch(arr, s, e, k);
        }
    }
};

class Sqrtwithprecision
{
    // using search space from 0 to N we will find the largest element whose square is less than N.
    // we will get interger part of square root of N.
    long long int sqrtInteger(int n)
    {

        int s = 0;
        int e = n;
        long long int mid = s + (e - s) / 2;

        long long int ans = -1;
        while (s <= e)
        {
            long long int square = mid * mid;

            if (square == n)
                return mid;

            if (square < n)
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
    // for precision we will add factor/10 to integer part of square root until its square is less than N
    // in every iteration of precision.
    double morePrecision(int n, int precision, int tempSol)
    {

        double factor = 1;
        double ans = tempSol;

        for (int i = 0; i < precision; i++)
        {
            factor = factor / 10;

            for (double j = ans; j * j < n; j = j + factor)
            {
                ans = j;
            }
        }
        return ans;
    }
};

class searchspace
{
    //painters problem:-
    // we array of n paints containing time of painting each paint.
    // we have k painters we have to allot all paintings to each painter such that we get all paintings in minimum sufficient time.
    // if we allot paintings which takes 30 and 70 minutes to painter A and B respectively
    // then painter A will complete painting in 30 minutes and painter B will complete painting in 70 minutes but we get
    // all painting in 70 minutes, so it not maybe the best allocation combination.

    // so to find the best allocation we will create a search space from 0 to sum of all painting time and do the binary search.
    // suppose mid value is 50 minutes, then we will check if all painting gets allocated with time less than equal to 50 minutes to all painters.
    // if k painters are not sufficient to complete all painting in 50 minutes we require more painters
    // means 50 is not a valid solution we have to increase time by shifting s = mid + 1;
    // if k painters are sufficient to complete all painting in 75 minutes it means time greater than 75 minutes is also valid.
    // but we have to minimum sufficient time to complete all painting.
    // so we will shift e = mid - 1 and time will gets reduced.

    bool findpossiblesoln(vector<int> &boards, int n, int mid, int k)
    {
        int painter_count = 1;
        int tsum = 0;
        for (int i = 0; i < n; i++)
        {
            if (tsum + boards[i] <= mid)
            {
                tsum += boards[i];
            }
            else
            {
                painter_count++;
                if (painter_count > k || boards[i] > mid)
                {
                    return false;
                }
                tsum = boards[i];
            }
        }
        return true;
    }

    int findLargestMinDistance(vector<int> &boards, int k)
    {
        //    Write your code here.
        int n = boards.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += boards[i];
        }
        int s = 0;
        int e = sum;
        int mid = s + (e - s) / 2;
        int ans;
        while (s <= e)
        {
            if (findpossiblesoln(boards, n, mid, k))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }

    //aggressive cows:-
    //we have array of n stalls containing position of each stall.
    //we have place k cows in stalls such that they will not fight with the adjacent cows.
    //we will create a search space from 0 to max(stall position) which represent distance and do the binary search.
    //for mid = 6 we will check for any two stalls the distance is greater than equal to 6 because for less than 6 distance they will fight.
    //if 6 is not a valid solution we have to shift distance by shifting e = mid - 1 because k cows is not possible to place in 6 distance.
    //if 6 is a valid solution because k cows is possible to place in 6 distance but we have find largest distance in which they not fight.
    //so we will shift s = mid + 1;
    bool findposs(vector<int> &stalls,int n,int mid,int k){
    int cowcount=1;
    int lastpos = stalls[0];
    
    for(int i=0; i<n; i++){
        if(stalls[i]-lastpos >= mid){
            cowcount++;
            if(cowcount==k){
                return true;
            }
            lastpos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int s = 0;
    int e = *max_element(stalls.begin(), stalls.end());
    int mid = s + (e-s)/2;
    int ans;
    
    while(s<=e){
        if(findposs(stalls,n,mid,k)){
            ans = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

//cooking ninja:-
//we have array of n cooks containing rank of each cook.
//A cook with rank r can cook 1 dish in r minutes, next 1 dish in 2R minutes, next 1 dish in 3R minutes and so on.
//They are given m dishes to cook as early as possible.
//we have to find the minimum time required to cook all dishes.
//for this we will create a search space from 0 to 10^8 and do the binary search.
//for any mid we will check number of dish can be cooked by each cook in less than mid minutes.
//if number of dish is greater than equal to m then mid is a solution we will store it.
//also if it is a solution means time more than mid minutes is also valid, but we have to minimum sufficient time to cook all dishes.
//so we will shift e = mid - 1 and time will gets reduced.
//if number of dish is less than m then we will shift s = mid + 1;
//because time less than mid minutes is also not sufficient.
bool posiblesoln(vector<int> &rank,int n,int m,int mid){
    int dishes=0;
    int tsum=0;
    for(int i=0;i<n;i++){
        for(int j=1;tsum<=mid;j++){
            tsum += j*rank[i];
            dishes++;
        }
        dishes--;
        tsum=0;
    }
    if(dishes>=m){
        return true;
    }
    return false;
}

int minCookTime(vector<int> &rank, int m)
{
    // Write your code here
    int n = rank.size();
    int s = 0;
    int e = 10e8;
    int mid = s+(e-s)/2;
    int ans;
    
    while(s<=e){
        if(posiblesoln(rank,n,m,mid)){
            ans = mid;
            e = mid-1;
        }else{
            s=mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

};


                                                             //Sortings

//Some terminology meanings:
//Stable sort: The order of elements in the sorted array is same as in the original array.
//Unstable sort: The order of elements in the sorted array is not same as in the original array.
//In-place sort: The sorting takes place in the original array.
//Out-of-place sort: The sorting takes place in a new array.                                                            

//Selectionsort:-
//It is in-place and unstable sorting algorithm in which in each iteration 
//the smallest element is selected and swapped with the first element of unsorted part.

//use case:-
//when the size of array is small and their are memory constraints then we can use selection sort.

//Time Complexity:- O(n^2) & Omega(n^2)
//Space Complexity:- O(1)

//stable implementation of selection sort:-
//It can be combined with insertion sort i.e the minimum element is selected and inserted in place of the first element in unsorted part.

void selectionsort(vector<int> &arr, int n){
    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
}

//Bubble sort:-
//It is in-place and stable sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order.

//use case:-
//when in ith round the ith largest element gets its correct position.

//Time Complexity:- O(n^2) & Omega(n)
//Space Complexity:- O(1)

void bubblesort(vector<int> &arr, int n){
    for(int i=0; i<n-1; i++){
        int flag = 1;
        for(int j=0; j<(n-i)-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = 0;
            }
        }
        if(flag){
            break;
        }
    }
}

//Insertion sort:-
//It is in-place and stable sorting algorithm in which each element from unsorted part is picked
//and inserted in its correct position in sorted part.

//use case:-
//when the size of array is small and the array is partially sorted only some values are misplaced.

//Time Complexity:- O(n^2) & Omega(n)
//Space Complexity:- O(1)

//binary insertion sort:-
//using binary insertion sort we can sort the array in O(nlog(n)) time.

void insertionsort(vector<int> &arr, int n){
    for(int i=1; i<n; i++){
        int j = i;
        int ele = arr[i];
        while(j>0 && ele < arr[j-1]){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = ele; 
    }
}


int main(){
    vector<int> arr = {10,9,8,7,6,5,4,3,2,1};
    int n = arr.size();
    insertionsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}