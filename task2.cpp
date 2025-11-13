#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n){
    for (int i=0; i <=(n-2)/2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        //children are less than parent, otherwise not max-heap
        if (left<n && arr[i]<arr[left] ) return false;
        if (right<n && arr[i]<arr[right] ) return false;
    }
    return true;
}

void heapify(int arr[], int n, int i){ //max heap
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left<n && arr[left]>arr[largest])
        largest = left;
    if (right<n && arr[right]>arr[largest])
        largest = right;

    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    
    for(int i = n/2-1; i >= 0; i--) heapify(arr, n, i);

    for(int i =n-1; i>0; i--){
        swap(arr[0], arr[i]);  
        heapify(arr, i, 0); 
    }
}



int main(){
	
	int val[5] = {8, 7 , 6 ,5 , 4};
    cout<<"Array before: ";
    for(int i=0;i<5;i++) cout<<val[i]<<" ";
    cout<<endl;

    if(isMaxHeap(val, 5)) cout<<"array is max heap"<<endl;
    else cout<<"array is not max heap"<<endl;

    heapSort(val, 5);
    cout<<"Array after sorting: ";
    for(int i=0;i<5;i++) cout<<val[i]<<" ";
    cout<<endl;

	
   
	
	return 0;
}
