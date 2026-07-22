#include<iostream>
#include<vector>

using namespace std;

void merge (vector<int>&arr,int left,int mid,int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors
    vector<int> L(n1);
    vector<int> R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp vectors back into arr[left..right]
    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}



void mergesort(vector<int>&arr,int left,int right){
    if(left>=right){
        return;
    }

    int mid = left + (right-left)/2;
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);

    merge(arr,left,mid,right);
}


int main(){

    vector<int> arr = {22,0,65,4,7,1};
    cout<<"original vector : ";
    for(int num : arr){
        cout<<num<< " ";
    }
    mergesort(arr,0,arr.size()-1);
    return 0;
}