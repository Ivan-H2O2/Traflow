#include<iostream>
using namespace std;
#include <time.h>
#include <windows.h>
#include <vector>

long int MAX = 200; //<32767
template <class T>
void PrintArray(vector<T> &);
template <class T> 
void InsertionSort(vector<T>&);
template <class T> 
int InputArray(vector<T> &);

int main(int argc, char *argv[]){

    cout << "Insertion Sort:" << endl;
    vector<int> arr(MAX,0);
    InputArray(arr);
    InsertionSort(arr);
    PrintArray(arr);

    return 0;
}

template <class T> 
void InsertionSort(vector<T>& arr){
    int len = arr.size();
    int key = 0;
    for (int i = 1; i <= len-1; i++){
        key = arr[i];
        for (int j = 0; j < i;j++){
            if(arr[i] < arr[j]){
                for (int k = i; k >= j + 1; k--){
                    arr[k] = arr[k - 1];
                }
                arr[j] = key;
            }
        }
    }

}

template <class T> 
int InputArray(vector<T> & a){
    int n;
    cin >> n;
    a.resize(n,0);
    for(int i =0; i<n; ++i){
        cin >> a[i];
    }
    return n;
}

template <class T>
void PrintArray(vector<T>& arr){
    int len = arr.size();
    for (int i = 0; i < len;i++){
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;
}


