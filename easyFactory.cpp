#include <iostream>

using namespace std;

/*纯虚基类*/
/**************************************************
 * 纯虚函数的类不能实例化:
 * Parent * parent=new Parent()编译出错
 * ************************************************/
class Parent {
public:

    Parent()
    {
        cout << __FILE__ <<"\t" <<__FUNCTION__ << "\t" <<__LINE__ << "\t Parent()" << endl;
        this->userName="Parent";
    }

    string  userName;

    /*纯虚函数:纯虚函数是用来定义接口的,也就是基类中定义一个纯虚函数,基类不用实现,让子类来实现。*/
    virtual void operation() = 0;


};

/*虚拟基类是为解决多重继承而出现的二义性*/
class Child_A : public virtual Parent {

public:
    Child_A()
    {
        cout << __FILE__ <<"\t" <<__FUNCTION__ << "\t" <<__LINE__ <<  "\t Child_A()" << endl;
        userName="Child_A";
    }

    virtual void operation() {
        cout << __FILE__ <<"\t" <<__FUNCTION__ << "\t" <<__LINE__ << "\t Child_A" << endl;
    }
};

/*虚拟基类是为解决多重继承而出现的二义性*/
class Child_B : public virtual Parent {
public:
    Child_B()
    {
        cout << __FILE__ <<"\t" <<__FUNCTION__ << "\t" <<__LINE__ << "\t Child_B()" << endl;
        userName="Child_B";
    }

    virtual void operation() {
        cout << __FILE__ <<"\t" <<__FUNCTION__ << "\t" <<__LINE__ <<  "\t Child_B" << endl;
    }
};


class Child_C : public  Parent {
    virtual void operation() {
        cout << __FILE__ <<"\t" <<__FUNCTION__ << "\t" <<__LINE__ <<  "\t Child_C" << endl;
    }
public:
    Child_C(){
        cout << __FILE__ <<"\t" <<__FUNCTION__ << "\t" <<__LINE__ << "\t Child_C()" << endl;
        userName="Child_C";
    }
};


class Child_D : public  Parent {
    virtual void operation() {
        cout << __FILE__ <<"\t" <<__FUNCTION__ << "\t" <<__LINE__ <<  "\t Child_C" << endl;
    }
public:
    Child_D(){
        cout << __FILE__ <<"\t" <<__FUNCTION__ << "\t" <<__LINE__ << "\t Child_D()" << endl;
        userName="Child_D";
    }
};

/************************************************************************************
 *虚拟基类是为解决多重继承而出现的二义性.
 *构造了爷爷类(Parent),再构造第一个继承的父类(Child_A),最后继承第二个继承的父类(Child_B).
 ************************************************************************************/
class Child_E:public Child_A, public Child_B{
public:
    Child_E()
    {
        cout << __FILE__ <<"\t" <<__FUNCTION__ << "\t" <<__LINE__ << "\t Child_E()" << endl;
        userName="Child_E";
    }

    virtual void operation() {
        cout << __FILE__ <<"\t" <<__FUNCTION__ << "\t" <<__LINE__ <<  "\t Child_D" << endl;
    }

};

/*没有使用虚基类,多个父类继承自同一个爷爷类,就会产生歧义,到底是不是同一个爷爷？*/
class Child_F:public Child_C, public Child_D{
public:
    Child_F()
    {
        cout << __FILE__ <<"\t" <<__FUNCTION__ << "\t" <<__LINE__ << "\t Child_F()" << endl;
        //userName="Child_F";  /*编译错误,歧义:没法指定userName是指定那一个*/
    }

    virtual void operation() {
        cout << __FILE__ <<"\t" <<__FUNCTION__ << "\t" <<__LINE__ <<  "\t Child_F" << endl;
    }

};

/****************************
 * 简单工厂的本质是：选择实现
 * **************************/
class EasyFactory {
public:
    static Parent* createObject(int option)
    {
        Parent *obj = NULL;
        switch (option) {
            case 1:
                obj = new Child_A();
                break;
            case 2:
                obj = new Child_B();
                break;
            case 3:
                obj = new Child_C();
            case 4:
                obj = new Child_E();
            default:
                //obj = new Child_F(); /*Parent是Child_F的有歧义的基类;没有使用虚基类,到底是不是同一个爷爷？*/
                break;
        }
        return obj;
    }
};

int main() {
    /*
     Parent  *child_a= EasyFactory::createObject(1);
    child_a->operation();
    Parent  *child_b= EasyFactory::createObject(2);
    child_b->operation();
    Parent  *child_c= EasyFactory::createObject(3);
    child_c->operation();
     */
    Parent  *child_e= EasyFactory::createObject(4);
    child_e->operation();
    cout<<child_e->userName<<endl;

    return 0;
}

/****************************输出结果****************************
/root/CLionProjects/DesignMode/main.cpp	Parent	15	 Parent()
/root/CLionProjects/DesignMode/main.cpp	Child_A	33	 Child_A()
/root/CLionProjects/DesignMode/main.cpp	Child_B	47	 Child_B()
/root/CLionProjects/DesignMode/main.cpp	Child_E	88	 Child_E()
/root/CLionProjects/DesignMode/main.cpp	operation	93	 Child_D
Child_E
****************************************************************/