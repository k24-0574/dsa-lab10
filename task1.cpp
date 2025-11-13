#include <iostream>
using namespace std;
#define MAXsize 100
class maxHeap{
	int arr[MAXsize];
	int currSize;
	int parent(int i){ return (i-1)/2; }
	int left(int i){ return 2*i+1; }
	int right(int i){ return 2*i+2; }
	
	void heapifyUp (int index){
		while(index!=0 && arr[index] > arr[parent(index)] ){
			swap (arr[index], arr[parent(index)]);
			index = parent(index);
		}
	}
	
	void heapifyDown(int index){
		int largest = index;
		int l = left(index), r = right(index);
		
		if(l<currSize && arr[l] > arr[largest]) largest = l;
		if(r<currSize && arr[r] > arr[largest]) largest = r;
		
		if(largest != index) {
			swap (arr[index], arr[largest]);
			heapifyDown(largest);
		}
	}
		
	public:
		maxHeap(){
			currSize =0;
		}
		
		void insert(int data){
			if(currSize == MAXsize) {
				cout<<"Overflow";
				return;
			}
			
			arr[currSize] = data;
			heapifyUp(currSize);
			currSize++;
		}
		
		void deleteMax(){
			if(currSize==0){
				cout<<"Underflow";
				return;
			}
			
			arr[0] = arr[currSize-1];
            currSize--;
			heapifyDown(0);
		}
		
		
		void display(){
			for(int i=0;i<currSize;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
		
		void update_key(int i, int new_val){
            if(i<0||i>currSize) {
                cout<<"invalid index"; return;
            }
            int old_val =  arr[i];
            arr[i] = new_val;
            if(new_val>old_val) heapifyUp(i);
            if(new_val<old_val) heapifyDown(i);

            cout<<endl<<"After updating: ";
            display();


            //now delete
            arr[i] = arr[currSize-1]; //last element at i index
            currSize--;
            heapifyDown(i); // arr[i] is replaced by a smaller value and last index will have smaller value
            cout<<endl<<"After deleting: ";
            display();
        }
		
};


int main(){
	
	int val[5] = {8, 7 , 6 ,5 , 4};
	maxHeap h1;
	
	for(int i=0;i<5;i++){
		h1.insert(val[i]);
	}
	
	h1.display();
    h1.update_key(3, 3); //3rd pos = 5, replaced with 3 and then deleted
	
	return 0;
}
