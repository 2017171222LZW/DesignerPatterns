#include <iostream>
#include <string>
using namespace std;

/*
*   发送查询的接口
*/
class SendQuery{
    public: virtual void send()=0;
};

/*
*   中国移动
*/
class ChinaMobile :public SendQuery{
    /*
    *   @overide
    * */
   public: void send(){
       cout << "Send Query Message to ChinaMobile" << endl;
   }
};

/*
*   中国联通
*/
class ChinaUnicom :public SendQuery{
    /*
    *   @overide
    * */
   public: void send(){
       cout << "Send Query Message to ChinaUnicom" << endl;
   }
};

/*
*   中国电信
*/
class ChinaTelecom :public SendQuery{
    /*
    *   @overide
    * */
   public: void send(){
       cout << "Send Query Message to ChinaTelecom" << endl;
   }
};

/*
*   SIM卡运营商分为：移动、电信、联通
*   不同的运营商，查询短信的命令不同
*/
class Factory1{
public: 
    SendQuery* Produce(string type){
        SendQuery* send;
        if (type=="CB"){
            send = new ChinaMobile();
        } else if (type=="CU"){
            send = new ChinaUnicom();
        } else if (type=="CT"){
            send = new ChinaTelecom();
        } else {
            cout << "Create Send Failed!" << endl;
        }
        return send;
    }
};

class Factory2{
public: 
    SendQuery* ProduceChinaMobile(){
        SendQuery* cb = new ChinaMobile();
        return cb;
    }
    SendQuery* ProduceChinaUnicom(){
        SendQuery* cu = new ChinaUnicom();
        return cu;
    }
    SendQuery* ProduceChinaTelecom(){
        SendQuery* ct = new ChinaTelecom();
        return ct;
    }
};

class Factory3{
public: 
    static SendQuery* ProduceChinaMobile(){
        SendQuery* cb = new ChinaMobile();
        return cb;
    }
    static SendQuery* ProduceChinaUnicom(){
        SendQuery* cu = new ChinaUnicom();
        return cu;
    }
    static SendQuery* ProduceChinaTelecom(){
        SendQuery* ct = new ChinaTelecom();
        return ct;
    }
};

class Provider{
virtual SendQuery* ProduceChinaTelecom();
};

class ChinaMobileProducer : public Provider{
    SendQuery* ProduceChinaTelecom(){
        SendQuery* cb = new ChinaMobile();
        return cb;
    }
};

class ChinaUnicomProducer : public Provider{
    SendQuery* ProduceChinaTelecom(){
        SendQuery* cb = new ChinaUnicom();
        return cb;
    }
};

class ChinaTelecomProducer : public Provider{
    SendQuery* ProduceChinaTelecom(){
        SendQuery* cb = new ChinaTelecom();
        return cb;
    }
};

// 发送短信方式是相同的，不因运营商而改变
void SendMsg(SendQuery* s){
    s->send();
}

int main(){
    SendQuery* send;
    send = Factory3::ProduceChinaMobile();
    SendMsg(send);
    send = Factory3::ProduceChinaTelecom();
    SendMsg(send);
    send = Factory3::ProduceChinaUnicom();
    SendMsg(send);
    getchar();
    return 0;
}