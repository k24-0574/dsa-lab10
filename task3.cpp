#include <iostream>
using namespace std;

struct Node {
    int data; 
    Node* next; 
    Node(int d) : data(d), next(nullptr) {}
};

class PriorityQueue {
    Node* front; 
    public:
    PriorityQueue() : front(nullptr) {}

    ~PriorityQueue() {
        while (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if(!front || val > front->data){
            newNode->next= front;
            front = newNode;
        }
        else{
            Node* temp = front;
            while(temp->next && temp->next->data > val){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

    }
    int dequeue(){
        if(!front) return;
        Node* temp  = front;
        front = front->next;
        int data = temp->data;
        delete temp;
        return data;
    }
};

int KthLargest(int arr[], int size, int k){
    PriorityQueue Q;
    for(int i=0;i<size;i++) Q.insert(arr[i]);

    for (int i=0;i<k-1;i++) Q.dequeue();
    return Q.dequeue();
}

int main(){
	
	int arr1[] = {1, 23, 12, 9, 30, 2, 50};
    int K = 3;
    cout<<KthLargest(arr1, 7, K)<<endl;
    int arr2[] = {12, 3, 5, 7, 19};
    K = 2;

	cout<<KthLargest(arr2, 5, K);
   
	
	return 0;
}
