#ifndef FACTORYMETHODDESIGNMODE_EXPORTOPERATE_H
#define FACTORYMETHODDESIGNMODE_EXPORTOPERATE_H
/*====================[creator]=====================*/
#include "exportFile.h"
/***************************************************
 *定义：
定义一个用于创建对象的接口，让子类决定实例化哪一个类；
工厂方法(factoryMethod)使一个类的实例化延迟到其子类(本质)。
 * *************************************************/


/*虚基类做为接口*/
class ExportOperate {
public:
    virtual ExportFileApi* factoryMethod() = 0; /*虚函数(子类必须实现)*/
    bool exportData(string data) {
        ExportFileApi* api = factoryMethod();
        return api->exportFile(data);
    }

};

class ExportTxtFileOperate : virtual public ExportOperate {
public:
    ExportTxtFileOperate(){ptr=NULL;}
    ~ExportTxtFileOperate()
    {
        if(NULL!=ptr){  delete ptr; }
    }

    /*C++11 中的 override 关键字，可以显式的在派生类中声明，哪些成员函数需要被重写，如果没被重写，则编译器会报错*/
    virtual ExportFileApi* factoryMethod() override
    {
        cout<<__FILE__<<"\t"<<__FUNCTION__<<"\t"<<__LINE__<<endl;

        ptr=new ExportTxtFile();
        return ptr;
    }

private:
    ExportFileApi*  ptr;
};

class ExportDBOperate : virtual public ExportOperate {
public:
    ExportDBOperate(){ptr=NULL;}
    ~ExportDBOperate()
    {
        if(NULL!=ptr){  delete ptr; }
    }

    /*C++11 中的 override 关键字，可以显式的在派生类中声明，哪些成员函数需要被重写，如果没被重写，则编译器会报错*/
    virtual ExportFileApi* factoryMethod() override
    {
        cout<<__FILE__<<"\t"<<__FUNCTION__<<"\t"<<__LINE__<<endl;

        ptr=new ExportDB();
        return ptr;
    }

private:
    ExportFileApi*  ptr;
};

#endif //FACTORYMETHODDESIGNMODE_EXPORTOPERATE_H
