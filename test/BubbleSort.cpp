#ifndef _A
#define _A
#include<iostream>
#include<vector>
using namespace std;
template <class T>
void printArray(vector<T> &);
template <class T> int BubbleSort(vector<T>&);
template <class T> vector<T>& EXAM(vector<T>&);

int main(int argc, char *argv[]){

    cout << LONG_MAX << endl;
    cout << LONG_MIN << endl;
    cout << ULONG_MAX << endl;
    cout << LLONG_MAX << endl;
    cout << INT_MAX << endl;
    cout << UINT_MAX << endl;
    cout << SHRT_MAX << endl;
    return 0;
    int MAX = 10;
    vector<float> arr={20,2,6,3,8,1,4,7,2,7.2};
    vector<float> tmp;
    arr.swap(tmp);
    arr.assign({1,2,3});
    cout << "size: " << arr.size() << endl;
    arr.resize(0);
    cout << "size: " << arr.size() << endl;
    //BubbleSort(arr);
    arr.assign({4,5,6});
    cout << "size: " << arr.size() << endl;
    arr=EXAM(arr);
    printArray(arr);
    //printArray(arr);
}
template <class T>
void printArray(vector<T>& arr){
    int len = arr.size();
    for (int i = 0; i < len;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <class T> 
int BubbleSort(vector<T>& arr){
    int temp;
    int len = arr.size();
    
    for (int i = len-1; i > 0;i--){
        //cout << "2" << endl;
        for (int j = 0; j < i;j++){
            //cout << "3" << endl;
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j + 1] = temp;
                //cout << "exchanged" << endl;
            }
        }
    }
    return 0;
}
template <class T> 
vector<T>& EXAM(vector<T>& arr){
    return arr;
}


#endif