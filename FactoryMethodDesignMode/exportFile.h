#ifndef FACTORYMETHODDESIGNMODE_EXPORTFILEAPI_H
#define FACTORYMETHODDESIGNMODE_EXPORTFILEAPI_H
/*====================[product]=====================*/
#include <iostream>
using namespace std;

/*虚基类做为接口*/
class ExportFileApi {
public:
   virtual bool exportFile(string data)=0; /*虚函数(子类必须实现)*/

};

class ExportTxtFile : virtual  public ExportFileApi
 {
 public:
     virtual bool exportFile(string data) override /*虚函数重写*/
     {
        cout<<__FILE__<<"\t"<<__FUNCTION__<<"\t"<<__LINE__<<"\t";
        cout<<data<<endl;
        return true;
    }
 };

class ExportDB : virtual  public ExportFileApi
{
public:
    virtual bool exportFile(string data) override /*虚函数重写*/
    {
        cout<<__FILE__<<"\t"<<__FUNCTION__<<"\t"<<__LINE__<<"\t";
        cout<<data<<endl;
        return true;
    }
};



#endif //FACTORYMETHODDESIGNMODE_EXPORTFILEAPI_H
