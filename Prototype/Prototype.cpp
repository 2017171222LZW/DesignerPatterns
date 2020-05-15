#include <iostream>
#include <string>
using namespace std;

/**
 * 克隆人例子
 */
class Person{
    public:
    /**
     * 构造函数
     */ 
        Person(){};
        Person(string n, int id):name(n),uniqueID(id){};
    /**
     * 克隆函数
     */ 
        virtual Person* Clone(){cout << "Person is go on." << endl;};

        virtual void Show(){
            cout << "Person Show." << endl;
            cout << name << ":" << uniqueID << endl;
        }
    protected:
        string name;//名字
        int uniqueID;//编号
};

class ClonePerson: public Person{
    public:
    /**
     * 构造函数
     */ 
        ClonePerson();
        ClonePerson(string n, int id):Person(n,id){};
    /**
     * 拷贝构造函数
     */ 
        ClonePerson(ClonePerson &p){
            this->name = p.name;
            this->uniqueID = p.uniqueID;
        }
    /**
     * 克隆函数
     */ 
        virtual Person* Clone(){
            cout << "ClonePerson is go on." << endl;
            return new ClonePerson(*this);
        };

        virtual void Show(){
            cout << "ClonePerson Show." << endl;
            cout << name << ":" << uniqueID << endl;
        }
};

int main(void){
    Person* p1 = new ClonePerson("xiaoming", 1);
    Person* p2 = p1->Clone();
    p1->Show();
    delete p1;
    p2->Show();
    delete p2;
    getchar();
    return 0;
}
