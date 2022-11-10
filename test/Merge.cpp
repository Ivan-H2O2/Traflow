#include<iostream>
using namespace std;
#include <time.h>
#include <windows.h>
#include <vector>
long int MAX = 2000; //<32767

template <class T>
void PrintArray(vector<T> &);
template <class T> 
vector<T>& MergeSort(vector<T>&);
template <class T>
int InputArray(vector<T> &);

int main(int argc, char *argv[]){
    
    cout << "MERGE:" << endl;
    vector<int> arr(MAX,0);
    InputArray(arr);
    MergeSort(arr);
    PrintArray(arr);
    
    return 0;
}

template <class T> 
vector<T>& MergeSort(vector<T>& arr){
    int len = arr.size();
    if(len <= 1){
        return arr;
    }
    else{
        vector<T> v1(arr.begin(), arr.begin() + (len + 1) / 2);
        vector<T> v2(arr.begin() + (len + 1) / 2, arr.end());
        arr.resize(0);
        v1 = MergeSort(v1);
        v2 = MergeSort(v2);

        int i, j = 0;
        for (i = 0, j = 0; (i < v1.size()) && (j < v2.size());)
        {
            if(v1[i] < v2[j]){
                arr.push_back(v1[i]);
                i++;
            }
            else{
                arr.push_back(v2[j]);
                j++;
            }
        }
        if(i>=v1.size()){
            for (j = j; j < v2.size();j++){
                arr.push_back(v2[j]);
            }          
        }
        else{
            for (i = i; i < v1.size();i++){
                arr.push_back(v1[i]);
            }
        }
        v1.resize(0);v2.resize(0);
        return arr;
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
