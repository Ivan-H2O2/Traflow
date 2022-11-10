#include<iostream>
using namespace std;
#include <time.h>
#include <windows.h>
#include <vector>
#define NUM 1999999
#define ORIMAX 2000
long int MAX = 2000; //<32767
int n0 = 1;
//int MergeProtectKey = 0;
template <class T>
void PrintArray(vector<T> &);
template <class T> 
void InsertSort(vector<T>&);
template <class T> 
vector<T>& MergeSort2(vector<T>&);
double test_InsertSort();
double test_MergeSort2();
template <class T>
int FindMin(vector<T> &);

int main(int argc, char *argv[]){
    
    int step = 1000;
    int maax = 30000;
    //int maax = 2000;

    //MAX = 10;
    //maax = 10;
    //cout << "MERGE:" << endl;
    cout << "COMBINATION:" << endl;

    vector<double> vcost;
    vector<double> vn0;
    cout << "MAX: " << MAX << endl;
    double min;
    n0 = 1;
    min = test_MergeSort2();
    int mp = 1;
    int quita = 0;
    for (MAX = NUM, n0 = 1; n0 <= MAX; n0 += 1)
    {
        
        cout << n0 << " ";
        vn0.push_back(n0);
        vcost.push_back(test_MergeSort2());
        if(*vcost.end()<min){
            mp = n0;
            min = *vcost.end();
            quita = 0;
        }
        else{
            quita++;
            //cout << "quita: " <<quita<< endl;
            if(quita>=30){
                break;
            }
        }
    }
    cout << "n0 when Min: " << vn0[FindMin(vcost)] << endl;
    //PrintArray(vcost);
    // for (MAX = NUM/10; MAX <= NUM; MAX+=NUM/10){
    //     vcost.push_back(test_MergeSort2());     
    // }
    // cout << "INSERT:" << endl;
    // for (MAX = ORIMAX; MAX <= maax; MAX+=step){
    //     test_InsertSort();       
    // }
    
    return 0;
}

double test_InsertSort(){
    srand((unsigned)time(NULL));  
    vector<int> arr(MAX,0);
    //cout << 'a' << endl;
    for(int i =0; i<MAX; ++i){
        arr[i] = rand() % NUM;
    }
    double start, cost;
    start = clock();
    InsertSort(arr); 
    //Sleep(2);
    cost = clock() - start;
    //PrintArray(arr);
    cout << MAX <<" ";
    cout << " "<< cost << endl;
    return cost;
}

double test_MergeSort2(){
    srand((unsigned)time(NULL));  
    vector<int> arr(MAX,0);
    for(int i =0; i<MAX; ++i){
        arr[i] = rand() % NUM;
    }
    //PrintArray(arr);
    double start, cost;
    start = clock();
    
    MergeSort2(arr); 

    cost = clock() - start;
    //PrintArray(arr);
    //cout << MAX <<" ";
    cout << " "<< cost << endl;
    return cost;
}

template <class T> 
void InsertSort(vector<T>& arr){

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
vector<T>& MergeSort2(vector<T>& arr){

    int len = arr.size();
    if(len <= n0){
        InsertSort(arr);
        return arr;
    }
    else{
        vector<T> v1(arr.begin(), arr.begin() + (len + 1) / 2);
        vector<T> v2(arr.begin() + (len + 1) / 2, arr.end());
        arr.resize(0);
        v1 = MergeSort2(v1);
        v2 = MergeSort2(v2);
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
void PrintArray(vector<T>& arr){
    for (int i = 0; i < arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;
}

template <class T>
int FindMin(vector<T> & arr){
    int min = 0;
    for (int i = 1; i < arr.size();i++){
        if(arr[i]<arr[min])
            min = i;
    }
    return min;
}




