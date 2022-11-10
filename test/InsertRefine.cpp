#include<iostream>
using namespace std;
#include <time.h>
#include <windows.h>
#include <vector>
#define NUM 19999
#define ORIMAX 2000
int MAX = 2000; //<32767
//int MergeProtectKey = 0;
template <class T>
void PrintArray(vector<T> &);
template <class T> 
void InsertSort2(vector<T>&);
template <class T> 
vector<T>& MergeSort(vector<T>&);
int test_InsertSort();
int test_MergeSort();
template <class T> 
int BinarySearch(T,vector<T>&,int,int);
int test_BinarySearch();

int main(int argc, char *argv[]){
    
    int step = 1000;
    int maax = 30000;
    //int maax = 2000;

    //MAX = 10;
    //maax = 10;

    cout << "MERGE:" << endl;
    for (MAX = ORIMAX; MAX <= maax; MAX+=step){
        test_MergeSort();
    }

    // cout << "INSERT2:" << endl;
    // for (MAX = ORIMAX; MAX <= maax; MAX+=step){
    //     test_InsertSort();
    // }
    return 0;
}

int test_InsertSort(){
    srand((unsigned)time(NULL));  
    vector<int> arr(MAX,0);
    for(int i =0; i<MAX; ++i){
        arr[i] = rand() % NUM;
    }
    double start, cost;
    //PrintArray(arr);
    start = clock();
    InsertSort2(arr); 
    //Sleep(2);
    cost = clock() - start;
    //PrintArray(arr);
    cout << MAX <<" ";
    cout << " "<< cost << endl;
    return 0;
}

int test_MergeSort(){
    srand((unsigned)time(NULL));  
    vector<int> arr(MAX,0);
    for(int i =0; i<MAX; ++i){
        arr[i] = rand() % NUM;
    }
    //PrintArray(arr);
    double start, cost;
    start = clock();
    
    MergeSort(arr); 

    cost = clock() - start;
    //PrintArray(arr);
    cout << MAX <<" ";
    cout << " "<< cost << endl;
    return 0;
}

template <class T> 
void InsertSort2(vector<T>& arr){
    int len = arr.size();
    int key = 0;
    for (int i = 1; i <= len-1; i++){
        key = arr[i];
        int j= BinarySearch(key, arr, 0, i - 1);
        for (int k = i; k >= j + 1; k--){
            arr[k] = arr[k - 1];
        }
        arr[j] = key;   
    }
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

template <class T> 
vector<T>& MergeSort(vector<T>& arr){
    // MergeProtectKey++;
    // if(MergeProtectKey>100){
    //     //cout <<"shi"<< endl;
    //     return arr;
    // }
    int len = arr.size();
    if(len <= 1){
        return arr;
    }
    else{
        //cout << "arr_in"
        //     << ": ";
        //PrintArray(arr);
        vector<T> v1(arr.begin(), arr.begin() + (len + 1) / 2);
        vector<T> v2(arr.begin() + (len + 1) / 2, arr.end());
        //cout << "v1: ";
        //PrintArray(v1);
        //cout << "v2: ";
        //PrintArray(v2);
        arr.resize(0);
        v1 = MergeSort(v1);
        v2 = MergeSort(v2);
        //cout << "v1 size: " << v1.size() << endl;
        //cout << "v2 size: " << v2.size() << endl;
        int i, j = 0;
        for (i = 0, j = 0; (i < v1.size()) && (j < v2.size());)
        {
            if(v1[i] < v2[j]){
                arr.push_back(v1[i]);
                //cout << "add v11" << endl;
                i++;
            }
            else{
                arr.push_back(v2[j]);
                //cout << "add v21" << endl;
                j++;
            }
        }
        if(i>=v1.size()){
            for (j = j; j < v2.size();j++){
                arr.push_back(v2[j]);
                //cout << "add v22" << endl;
            }   
        }
        else{
            for (i = i; i < v1.size();i++){
                arr.push_back(v1[i]);
                //cout << "add v12" << endl;
            }
        }
        v1.resize(0);v2.resize(0);
        //cout << "arr_out"
        //     << ": ";
        //PrintArray(arr);
        return arr;
    }
}

template <class T> 
int BinarySearch(T key, vector<T>& a,int i,int j){
    int m = (i + j) / 2;
    int tmp = 0;
    while(i <= j){   
        if(key < a[m]) j = m-1;
        else i = m + 1;        
        m = (i + j) / 2;
    }
    return i;
}

int test_BinarySearch(){
    srand((unsigned)time(NULL));
    MAX = 10;
    vector<int> arr(MAX,0);
    for(int i =0; i<MAX; ++i){
        arr[i] = rand() % NUM;
    }
    MergeSort(arr);
    PrintArray(arr);
    int tmp;
    for (int i = 0; i < arr.size();i++){
        tmp = BinarySearch(arr[i], arr, 3, 7);
        cout << tmp << endl;
    }

        return 0;
}



