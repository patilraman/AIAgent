#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <class T>
class base{
    public:
    void func()
    {
        static_cast<T*>(this)->derivedclass_func();
    }
};

class derived : public base<derived>{
    public:
    void derivedclass_func()
    {
        cout<<"derived class func"<<endl;
    }
};

template <class T>
void func(base<T> &c)
{
    c.func();
}

int main()
{
    derived d;
    func(d);
}
