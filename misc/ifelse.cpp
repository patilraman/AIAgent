#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <map>

using namespace std;

class camera{

};

class monochrome: public camera{
    public:
    monochrome(){
        cout<<"monochrome camera created"<<endl;
    }
};

class color: public camera{
    public:
    color(){
        cout<<"color camera created"<<endl;
    }
};

class factory{
    static vector<unique_ptr<camera>> vec;
    public: 
    static unique_ptr<camera> create_cam(std::type_info const *tid);
};

unique_ptr<camera> factory::create_cam(std::type_info const *tid)
{
    std::map<std::type_info const *, std::function<unique_ptr<camera>()>> mapping = {
        {&typeid(monochrome), [](){ return make_unique<monochrome>(); }},
        {&typeid(color), [](){ return make_unique<color>(); }},
    };

    auto it = mapping.find(tid);
    if (it != mapping.end()) {
        return it->second();
    }
    return nullptr;
};


int main()
{
    factory f;
    unique_ptr<camera> c1 = f.create_cam(&typeid(monochrome));
    unique_ptr<camera> c2 = f.create_cam(&typeid(color));
}