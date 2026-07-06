//NVI: Non-virtual interface idiom
#include <iostream>
#include <vector>
#include <memory>

using namespace std;
class base{
    public:
    void nonvfunc()
    {
        cout<<"base class nonvfunc"<<endl;
        vfunc();
    }
    private:
    virtual void vfunc()
    {
        cout<<"base vfunc"<<endl;
    }
};

class derived : public base{
    private:
    void vfunc() override
    {
        cout<<"derived vfunc"<<endl;
    }
};

int main()
{
    unique_ptr<base> b = make_unique<derived>();
    b->nonvfunc();
    unique_ptr<derived> b1 = make_unique<derived>();
    b1->nonvfunc();
}