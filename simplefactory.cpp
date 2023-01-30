#include <iostream>
#include <memory> 

using namespace std;

class base {};
class derived : public base {};

std::unique_ptr<base> create (int i) {
    if (i==1){
        cout << "in base" << endl;
        return unique_ptr<base>();
    }
    else{ 
        cout << "in derived" << endl;
        return unique_ptr<derived>();
    }
}


int main()
{
    cout<<"factory demo";
    
    create(1);
    create(2);

    return 0;
}
