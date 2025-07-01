#include<iostream>
using namespace std;

int main(){
    int arr[7] = {64,43,76,45,34,90,66};
    int swapCount=0;
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original array: ";
    for(int i = 0; i<size ; i++){
        cout<<arr[i]<<" ";
    }

    for(int i = 1; i<size; i++){
        int j = i - 1;
        int current = arr[i];
        while( j >=0 && arr[j] > current){
            arr[j+1] = arr[j];  swapCount++;
            j--;
        }
        arr[j+1] = current;
    }

    cout<<endl<<"Sorted array: ";
    for(int i = 0; i<size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Number of exchange: "<<swapCount;
}

