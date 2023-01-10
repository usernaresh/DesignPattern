#include <iostream>
#include <vector>

using namespace std;

class sort_algo_context {
    public:
    virtual void sort(vector<int>&) = 0;
    virtual void sort_print(const vector<int>) =0;
};

class bubble_sort : public sort_algo_context{
public:
    void sort(vector<int> &ary) {
        cout << " in bubble sort " << endl;
        for(int i=0; i< ary.size(); i++)
            for(int j=i; j< (ary.size()-1); j++)
                if(ary[j] > ary[j+1]){
                    int temp = ary[j+1];
                    ary[j+1] = ary [j];
                    ary[j] = temp;
                }
    }
    
    void sort_print(const vector<int> ary){
        for(int i: ary)
            cout << i << endl;
    }
};  

class selection_sort : public sort_algo_context{
public:
    void sort(vector<int>& ary) {    
        cout << " in selection sort " << endl;
    }
    
    void sort_print(const vector<int> ary){
        for(int i: ary)
            cout << i << endl;
    }
}; 

class algo_strategy{
    
sort_algo_context* sortptr;
public:
    void setup_sort_algo(sort_algo_context* sc){
        sortptr = sc;
    }
    
    void sort_algo(vector<int>& ary){
        sortptr->sort(ary);    
    }
    
    void sort_print(const vector<int> ary){
        sortptr->sort_print(ary);
    }
};

int main()
{
    cout<<" The strategy algo \n";
    //int arr[] = {1,8,3,7,5,2,4};
    vector<int> arr{1,8,3,7,5,2,4};
    bubble_sort bs;
    selection_sort ss;
    algo_strategy as;
    as.setup_sort_algo(&bs);
    //cout << "size of: " << sizeof(arr)  << endl;
    as.sort_algo(arr);
    as.sort_print(arr);
    as.setup_sort_algo(&ss);
    as.sort_algo(arr);
    as.sort_print(arr);
    return 0;
}
