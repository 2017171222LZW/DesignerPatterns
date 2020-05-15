#include <iostream>
#include <mutex>
#include <vector>
using namespace std;

class Singleton{
private:
    //私有构造函数，防止直接创建对象
    Singleton(){};
public:
    //获取对象
    static Singleton* getSingleton();
    void setNumber(int n);
    int getNumber();
    vector<int>* getPropertis();
    void UpdateProperties();//使用影子更新属性

private:
    //静态的对象，只存在仅此一个
    static Singleton* singleton;
    //static mutex m;
    int number;
    vector<int> *propertis = nullptr;
};
//饿汉模式
Singleton* Singleton::singleton = new Singleton();
//懒汉模式初始化
//Singleton* Singleton::singleton = nullptr;
//mutex Singleton::m;

Singleton* Singleton::getSingleton(){
    //懒汉模式
    /*
    static once_flag flag;
    m.lock();
    call_once(flag, [&](){
        singleton = new Singleton();
    });
    m.unlock();
    */
    return singleton;
}

void Singleton::setNumber(int n){
    number = n;
}

int Singleton::getNumber(){
    return number;
}

vector<int>* Singleton::getPropertis(){
    return propertis;
}

void Singleton::UpdateProperties(){
    Singleton shadow;
    propertis = shadow.getPropertis();
}

int main(void){
    Singleton *singleton1 = Singleton::getSingleton();
    Singleton *singleton2 = Singleton::getSingleton();
    singleton1->setNumber(10);
    cout << singleton1->getNumber() << endl;
    cout << singleton2->getNumber() << endl;
    return 0;
}
