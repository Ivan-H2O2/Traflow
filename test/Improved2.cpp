#include<iostream>
#include<cmath>
using namespace std;
#include <time.h>
#include <windows.h>
#include <vector>
#define NUM 1999999
#define ORIMAX 2000
#define AMP 1e7
template <class T>
void PrintArray(vector<T> &);
template <class T> 
vector<T>& MergeSort(vector<T>&);
template <class T> 
void InsertionSort(vector<T>&);
template <class T> 
void InsertionSort2(vector<T>&);//refined Insertion Sort with BinarySearch
template <class T> 
vector<T>& CombineSort(vector<T>&,int);
double test_InsertionSort(int);
double test_MergeSort(int);
template <class T>
int InputArray(vector<T> &);
template <class T>
int InputArray(vector<T> &,int&);
template <class T>
double time_CombineSort(vector<T> &,int);
double test_CombineSort(int,int);
double user_CombineSort();
double cal_InsertionSort();
double cal_MergeSort();
template <class T>
int SelectK(vector<T> &);
int SelectK(int,int);

template <class T> 
int BinarySearch(T,vector<T>&,int,int);
template <class T> 
T AveArray(vector<T>&);
template <class T>
int FindMin(vector<T> &);

int main(int argc, char *argv[]){
    int MAX = 2000; //
    int step = 300;
    int maax = 30000;
    int k = 62;

    // /*1 CombineSort with user input array */
    // user_CombineSort();

    // // /*2  Output k with user input array */
    // vector<int> a;
    // SelectK(a);

    // // /*3 Output k in Theory and with the c1 c2 tested separatedly */
    // double c1 = cal_MergeSort();
    // double c2 = cal_InsertionSort();
    // double k_thesis = c1 / c2 / log(2);
    // cout << "K Thesis:  " << k_thesis << endl << endl;

    // /*4 Output k using statistic way, random array */
    // cout << "COMBINATION:" << endl;
    // MAX = 3000;
    // int times = 200;
    // times = 100;
    // int n0 = SelectK(MAX, times);

    // /*5 test combinesort with certain K */
    // for (MAX = ORIMAX/2; MAX <= maax; MAX+=step){
    //     test_CombineSort(MAX,k);
    //     //cout << endl;
    // }
    MAX = 30000;
    for (k = 1; k <= 250; k+=1){
        test_CombineSort(MAX,k);
        //cout << endl;
    }

    return 0;
}

//Given array, find k
template <class T>
int SelectK(vector<T> &a){
    InputArray(a);
    int MAX = a.size();
    vector<int> vn0;
    int n0;
    int times = 100;
    for (int i = 0; i < times; i++){
        vector<T> b(a);
        n0 = 1;
        int lp = 1, rp = MAX, mp = 0;
        double lp_time, rp_time, mp_time;
        bool p = 0;
        mp = (lp + rp) / 2;
        while(1){
            lp_time = time_CombineSort(b,lp);
            rp_time = time_CombineSort(b,rp);  
            mp_time = time_CombineSort(b,mp);
            if (mp_time <= rp_time && lp_time <= rp_time){
                rp = mp;
            }
            else{
                if (mp_time <= lp_time && rp_time <= lp_time){
                    lp = mp;
                }
                else{
                    //p = 1;
                    //break;
                }
            }
            mp = (lp + rp) / 2;

            if(lp == rp){
                break;
            }
        }
        if(p == 0){
            n0 = lp;
            cout << n0 << " ";
        }
        vn0.push_back(n0);
    }
    n0 = AveArray(vn0);
    cout << endl;
    cout << "n0:  "
         << n0 << endl;
    return n0;

}

//Given n and times, test random array to find k as statistic value
int SelectK(int MAX,int times){
    vector<int> vn0;
    cout << "MAX: " << MAX << "  "
         << "TIMES: " << times
         << endl;
    int n0;
    for (int i = 0; i < times; i++){
        n0 = 1;
        int lp = 1, rp = MAX, mp = 0;
        double lp_time, rp_time, mp_time;
        bool p = 0;
        mp = (lp + rp) / 2;
        while(1){
            lp_time = test_CombineSort(MAX,lp);
            rp_time = test_CombineSort(MAX,rp);     
            mp_time = test_CombineSort(MAX,mp);
            if (mp_time <= rp_time && lp_time <= rp_time){
                rp = mp;
            }
            else{
                if (mp_time <= lp_time && rp_time <= lp_time){
                    lp = mp;
                }
                else{
                    //p = 1;
                    //break;
                }
            }
            mp = (lp + rp) / 2;
            //lp = lp - 1;
            //rp = rp + 1;
            //Min3(lp, rp, mp);
            if(lp == rp){
                break;
            }
        }
        if(p == 0){
            n0 = lp;
            cout << n0 << " ";
        }
        vn0.push_back(n0);
    }
    n0 = AveArray(vn0);
    cout << endl;
    cout << "n0:  "
         << n0 << endl;
    return n0;
}

double user_CombineSort(){
    int MAX = 3000;
    int k = 62;
    vector<int> arr(MAX,0);
    InputArray(arr,k);
    double time = time_CombineSort(arr, k);

    PrintArray(arr);
    // cout << MAX <<" ";
    // cout << time 
    // <<"  "<< k
    // << endl; // OutputTime /s
    return time;
}

template <class T> 
vector<T>& CombineSort(vector<T>& arr,int k){

    int len = arr.size();
    if(len <= k){
        InsertionSort2(arr);
        return arr;
    }
    else{
        vector<T> v1(arr.begin(), arr.begin() + (len + 1) / 2);
        vector<T> v2(arr.begin() + (len + 1) / 2, arr.end());
        arr.resize(0);
        v1 = CombineSort(v1,k);
        v2 = CombineSort(v2,k);
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
void InsertionSort2(vector<T>& arr){
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

double cal_InsertionSort(){
    cout << "Insertion:" << endl;
    int MAX = 2000; //
    int step = 500;
    int maax = 10000;
    vector<double> vc2;
    for (MAX = ORIMAX/2; MAX <= maax; MAX+=step){
        vc2.push_back(AMP*test_InsertionSort(MAX)/(double)(MAX*MAX));
    }
    double c2 = AveArray(vc2);
    cout << "c2: " << c2 << endl;
    cout << endl;
    return c2;
}

double cal_MergeSort(){
    int MAX = 2000; //
    int step = 500;
    int maax = 30000;
    cout << "Merge:" << endl;
    vector<double> vc1;
    for (MAX = ORIMAX/2; MAX <= maax; MAX+=step){

        vc1.push_back(AMP*test_MergeSort(MAX)/(double)(MAX));
    }
    double c1 = AveArray(vc1);
    cout << "c1: " << c1 << endl;
    cout << endl;
    return c1;
}

double test_InsertionSort(int MAX){
    srand((unsigned)time(NULL));  
    vector<int> arr(MAX,0);
    //cout << 'a' << endl;
    for(int i =0; i<MAX; ++i){
        arr[i] = rand() % NUM;
    }
    //double start, cost;
    LARGE_INTEGER t1,t2,tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);

    InsertionSort(arr); 

    QueryPerformanceCounter(&t2);
    //cout << MAX <<" ";
    double time=1e3*(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart;

    //PrintArray(arr);
    //cout << MAX <<"  "<< time << endl;
    return time;
}

double test_MergeSort(int MAX){
    srand((unsigned)time(NULL));  
    vector<int> arr(MAX,0);
 
    for(int i =0; i<MAX; ++i){
        arr[i] = rand() % NUM;
    }
    LARGE_INTEGER t1,t2,tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);

    MergeSort(arr); 

    QueryPerformanceCounter(&t2);
    //cout << MAX <<" ";
    double time=1e3*(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart;

    //PrintArray(arr);
    //cout << MAX <<"  "<< time << endl;
    return time;
}

double test_CombineSort(int MAX,int k){
    srand((unsigned)time(NULL));  
    vector<int> arr(MAX,0);
    for(int i =0; i<MAX; ++i){
        arr[i] = rand() % NUM;
    }
    double time = time_CombineSort(arr, k);
    // cout << MAX <<" ";
    cout << k <<"  "<< time 
    << endl; // OutputTime /s
    return time;
}


template <class T>
double time_CombineSort(vector<T> &arr,int k){
    LARGE_INTEGER t1,t2,tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);

    CombineSort(arr,k);

    QueryPerformanceCounter(&t2);
    
    double time=1e3*(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart;

    return time;
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

template <class T> 
T AveArray(vector<T>& a){
    int sum = 0;
    MergeSort(a);
    for (int i = 0; i < a.size(); i++){
        sum += a[i];
    }
    return sum / (a.size());
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
int InputArray(vector<T> &a,int& k){
    int n;
    cin >> n;
    cin >> k;
    a.resize(n,0);
    for(int i =0; i<n; ++i){
        cin >> a[i];
    }
    return n;
}