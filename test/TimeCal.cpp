#include<iostream>
using namespace std;
#include <time.h>
#include <windows.h>
#include <vector>
#define NUM 1999999
#define ORIMAX 2000
long int MAX = 2000; //<32767
//int MergeProtectKey = 0;
template <class T>
void PrintArray(vector<T> &);
template <class T> 
void InsertionSort(vector<T>&);
template <class T> 
vector<T>& MergeSort(vector<T>&);
template <class T> 
vector<T>& ReverseMergeSort(vector<T>&);
template <class T> 
vector<T>& MergeSort(vector<T>&,long long int &,bool flag=0);
int test_InsertionSort();
int test_MergeSort();
template <class T>
int InputArray(vector<T> &a);

int main(int argc, char *argv[]){
    
    int step = 500;
    int maax = 30000;
    //int maax = 2000;
    
    //MAX = 10;
    //maax = 10;

    cout << "MERGE:" << endl;
    for (MAX = 1000; MAX <= 20000; MAX+=step){
        test_MergeSort();     
    }
    // cout << "Insertion:" << endl;
    // for (MAX = ORIMAX; MAX <= maax; MAX+=step){
    //     test_InsertionSort();       
    // }
    
    return 0;
}

int test_InsertionSort(){
    srand((unsigned)time(NULL));  
    vector<int> arr(MAX,0);
    //cout << 'a' << endl;
    for(int i =0; i<MAX; ++i){
        arr[i] = rand() % NUM;
    }
    double start, cost;
    start = clock();
    InsertionSort(arr); 
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
    ReverseMergeSort(arr);
    long long int m=0;
    //PrintArray(arr);
    double start, cost;
    LARGE_INTEGER t1,t2,tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);

    MergeSort(arr); 
    QueryPerformanceCounter(&t2);
    //PrintArray(arr);
    cout << MAX <<" ";
    double time=1e3*(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart;
    cout << " " << time << endl; 

    return 0;
}

template <class T> 
void InsertionSort(vector<T>& arr){

    int len = arr.size();
    int key = 0;
    for (int i = 1; i <= len-1; i++){
        //cout << "2" << endl;
        key = arr[i];
        for (int j = 0; j < i;j++){
            //cout << "3" << endl;
            if(arr[i] < arr[j]){
                for (int k = i; k >= j + 1; k--){
                    arr[k] = arr[k - 1];
                }
                arr[j] = key;
                //cout << "exchanged" << endl;
            }
        }
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
vector<T>& MergeSort(vector<T>& arr,long long int &m,bool flag){

    int len = arr.size();
    if(len <= 1){
        return arr;
    }
    else{
        vector<T> v1(arr.begin(), arr.begin() + (len + 1) / 2);
        vector<T> v2(arr.begin() + (len + 1) / 2, arr.end());
        arr.resize(0);
        v1 = MergeSort(v1,m);
        v2 = MergeSort(v2,m);
        int i, j = 0;
        for (i = 0, j = 0; (i < v1.size()) && (j < v2.size());)
        {
            m++;
            if(v1[i] < v2[j]){
                arr.push_back(v1[i]);
                m++;
                i++;
            }
            else{
                arr.push_back(v2[j]);
                m++;
                j++;
            }
        }
        if(i>=v1.size()){
            for (j = j; j < v2.size();j++){
                arr.push_back(v2[j]);
                m++;
            }          
        }
        else{
            for (i = i; i < v1.size();i++){
                arr.push_back(v1[i]);
                m++;
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
vector<T>& ReverseMergeSort(vector<T>& arr){
    int len = arr.size();
    if(len <= 1){
        return arr;
    }
    else{
        vector<T> v1(arr.begin(), arr.begin() + (len + 1) / 2);
        vector<T> v2(arr.begin() + (len + 1) / 2, arr.end());
        arr.resize(0);
        v1 = ReverseMergeSort(v1);
        v2 = ReverseMergeSort(v2);
        int i, j = 0;
        for (i = 0, j = 0; (i < v1.size()) && (j < v2.size());)
        {
            //m++;
            if(v1[i] > v2[j]){
                arr.push_back(v1[i]);
                //m++;
                i++;
            }
            else{
                arr.push_back(v2[j]);
                //m++;
                j++;
            }
        }
        if(i>=v1.size()){
            for (j = j; j < v2.size();j++){
                arr.push_back(v2[j]);
                //m++;
            }          
        }
        else{
            for (i = i; i < v1.size();i++){
                arr.push_back(v1[i]);
                //m++;
            }
        }
        v1.resize(0);v2.resize(0);

        return arr;
    }
}

