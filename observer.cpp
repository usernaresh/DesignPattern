#include <iostream>
#include <vector>

using namespace std;

class observer;

class subject{
 public:
  virtual void registerObs(observer* obs) = 0;
  virtual void deRegisterObs(observer* obs) = 0;
  virtual void notify() =0;
};


class observer{
    public: 
    virtual void update() =0;
};

class obs1: public observer {
    public:
    void update(){
        
        cout << "update of obs1 " << endl;
    }
};


class obs2: public observer {
    public:
    void update(){
        
        cout << "update of obs2 " << endl;
    }
};

class workstation: public subject {
 vector <class observer*> ptrobs;
 public:
  void registerObs(observer* obs){
      ptrobs.push_back(obs);
  }
  
  void deRegisterObs(observer* obs){
      ptrobs.pop_back();
  } 
  
  virtual void notify() {
    for (auto i= 0; i< ptrobs.size(); i++){
      ptrobs[i]->update();  
    }
  }
}; 


int main()
{
    cout<<"Hello World" << endl;
    obs2 o2;
    obs1 o1;
    
    cout <<" observers intialized " << endl;
    workstation ws;
    cout << "workstation intialized" << endl;
    ws.registerObs(&o1);
    ws.registerObs(&o2);
    cout << "observers registerd " << endl;
    ws.notify();

    return 0;
}
