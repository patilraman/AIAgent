#include <iostream>
#include <vector>
#include <memory>
#include "pimpl.h"

using namespace std;

class camera_impl{
    public:
    void capture(){
        cout<<"camera_impl:capturing image"<<endl;
    }
};

camera::camera():
    pimpl(new camera_impl()/*,[](camera_impl* pimpl){
        cout<<"camera_impl destroyed"<<endl;
        delete pimpl;
    }*/)
{
    cout<<"camera created"<<endl;
}

void camera::capture(){
    pimpl->capture();
}

int main()
{
    camera c;
    c.capture();
}