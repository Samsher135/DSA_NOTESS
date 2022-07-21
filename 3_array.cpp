#include <bits/stdc++.h>
using namespace std;


//if element in array is twice xor operation will cancel duplicate element and will give the unique element.
int findDuplicate(vector<int> &arr) 
{
    // Write your code here
	int n = arr.size();
    int xo1=0,xo2=0;
    for(int i=0; i<n; i++){
        xo1 ^= arr[i];
    }
    
    for(int i=1; i<=n-1; i++){
        xo2 ^= i;
    }
    
    return xo1 ^ xo2;
}


// Sort the array in ascending order. Time complexity O(n * log(n))
// Start with two indices - left and right. The left one points to the first element in the array; the right one points to the last.
// Check if the sum of the elements present at the ‘left’ and the ‘right’ indices is equal to ‘s’.
// If this sum is less than ‘s’, increment the left index. Since the array is sorted, incrementing this index will give us a larger element, and the sum would increase.
// If this sum is more than ‘s’, decrement the left index. Since the array is sorted, decrementing this index will give us a smaller element, and the sum would decrease.
// If the sum is ‘s’, 
// If the ‘left’ and the ‘right’ elements are unequal, get the count of elements which are equal to them. The number of pairs in the result would be the product of the two counts.
// If the ‘left’ and the ‘right’ elements are equal, the number of pairs that can be generated is c * (c-1) / 2, where c is the number of times the element is present.
// After counting, move the ‘left’ and ‘right’ indices past the repeated elements.
// If ‘left’ is lesser than ‘right’, go to Step 3.
// The time complexity of Steps 3 to 7 is O(n).
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    vector<vector<int>> ans;
    int n = arr.size();
    sort(arr.begin(),arr.end());
    int st = 0;
    int e = n-1;
    int times;
    while(st<e){
        if(arr[st] + arr[e] < s){
            st++;
        }else if(arr[st] + arr[e] == s){
            int count = 1;
            int count1 = 1;            
            if(arr[st] != arr[e]){
                while(arr[st] == arr[st+1] && st<=e){
                    st++;
                    count1++;
                }
                while(arr[e] == arr[e-1] && st<=e){
                    e--;
                    count++;
                }
                times = count*count1;
                for(int i=1; i<=times; i++){
                    ans.push_back({arr[st],arr[e]});
                }
                st++;
                e--;
            }else{
                while(arr[st] == arr[st+1] && st<=e){
                    st++;
                    count++;
                }
                times = (count*(count-1))/2;
                for(int i=1; i<=times; i++){
                    ans.push_back({arr[e],arr[e]});
                }
                break;
            }
        }else{
            e--;
        }
    }
    return ans;
}

// to find 3SUM in an array
// sort the array in ascending order. Time complexity O(n * log(n))
// Start with two indices - left and right. 
// The left one points to the i+1 in the array; the right one points to the last.
// compare the sum of the elements present at the 'i',‘left’ and the ‘right’ indices
// also use while loop to avoid duplicate element.

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
    vector<vector<int>> res;       
        if(n <=2) return res;
         
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
             
           if(i>0 && arr[i] == arr[i-1])  // avoid duplicate triplets count
                continue;
            
             
            for(int l=i+1, r=n-1; l<r; ) {
                 
                if(arr[i]+arr[l]+arr[r] > K)                    
                    r--;
                 
                else if (arr[i]+arr[l]+arr[r] < K)
                    l++;
                 
                else {
                    // arr[l] + arr[r] == K
                    res.push_back({arr[i], arr[l], arr[r]});
 
                    // skip duplicates
                    while( l<n-1 && arr[l]==arr[l+1]) l++;
                    while( r>0 && arr[r]==arr[r-1]) r--;
                                             
                    l++;
                    r--;                   
                     
                }
                 
            }                                 
             
        }
        return res;
}

//to sort 0 & 1 in an array
// swap 0  with low value and increase the low value by 1 and ignore 1.
void segregate0and1(int arr[], int n)
{
    int low = 0, ele = 0;
    while (ele < n)
    {
        if (arr[ele] == 0)
        {
            swap(arr[low], arr[ele]);
            low++;
        }
        ele++;
    }
}

//if element to short is 0,1,2 then sort element swap 0 to left and 2 to right ignore 1.

//if element to short is 0,1,2,3 then sort element swap 0 to left and 3 to right ignore 1&2 
//then again in a new loop swap 1 to left and 2 will be shifted to right automatically.

//if element to short is 0,1,2,3,4 then sort element swap 0 to left and 4 to right ignore 1&2&3
//then again in a new loop swap swap 1 to left and 3 to right ignore 2.

//this is applicaple if element to short is known;

// Function to sort the array having
// array element only 0, 1, 2, and 3
void sortArray(int arr[], int N)
{
	int i = 0, j = N - 1, mid = 0;

	// Iterate until mid <= j
	while (mid <= j) {

		// If arr[mid] is 0
		if (arr[mid] == 0) {

			// Swap integers at
			// indices i and mid
			swap(arr[i], arr[mid]);

			// Increment i
			i++;

			// Increment mid
			mid++;
		}

		// Otherwise if the value of
		// arr[mid] is 3
		else if (arr[mid] == 3) {

			// Swap arr[mid] and arr[j]
			swap(arr[mid], arr[j]);

			// Decrement j
			j--;
		}

		// Otherwise if the value of
		// arr[mid] is either 1 or 2
		else if (arr[mid] == 1
				|| arr[mid] == 2) {

			// Increment the value of mid
			mid++;
		}
	}

	// Iterate until i <= j
    int low = i, ele=i;
	while (ele <= j) {
     	if(arr[ele]==1){
       	swap(arr[low], arr[ele]);
           low++;
       }
      	ele++;
    }
}

//the logic is derived from creating an another array and storing the count of each element in the array
//in their respective index and then we can easily find the duplicate elements.
//but if the dulplicate elements is only twice then we can make the corresponding index according to the element to negative value.
//then after checking the value is less than 0 then we can find the duplicate elements.
vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(auto i:nums)
        {
            if(nums[abs(i)-1] < 0){
                res.push_back(abs(i));
            }
            nums[abs(i)-1] *= -1;
        }
        return res;
}


// rotate the array to the right by k steps

//The approach is derived from the (n-x)%n = x;
//for example consider an array [1,2,3,4,5,6,7]
//if k=3 then we need to rotate the array to the right by 3 steps
//for first index i = 0+3 it will gets new index i = 3
//but for last element i = 6+3 which is out of size of array so using formula as last element is n-1, therefore i = (n-1+3)%n = 2
//therefore last element get its new index as 2.

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        
        for(int i=0; i<n; i++){
            temp[((n-(n-i))+k)%n] = nums[i];
        }
        
        nums = temp;
    }





