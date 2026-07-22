#include<iostream>
#include<vector>

using namespace std;

void merge (vector<int>&arr,int left,int mid,int right){
    
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