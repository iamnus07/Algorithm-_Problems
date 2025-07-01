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
    cout<<endl;

    for(int i = 0; i<size-1 ; i++){
            bool swap = false;
        for(int j = 0; j<size-1-i; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap = true;
                swapCount++;
            }
            //cout<<i<<j<<endl;
        }
        if(swap == false){
            break;
        }
    }

    cout<<"Sorted array: ";
    for(int i = 0; i<size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Number of exchange: "<<swapCount;
}

