#include <iostream>
using namespace std;

int main() {
  int n,key;
  int arr[10];

  cout<<"Enter number of element";
cin>> n;

cout<<"Enter elements \n";
for(int i=0; i<n; i++){
    cin>> arr[i];
}

cout<<"Enter element to search:";
cin>>key;

for(int i=0; i<n; i++){
    if(arr[i]==key){
        cout<< "Elements foud at index" <<i;
        return 0;
    }
}
cout<<"Element not found";
return 0;}