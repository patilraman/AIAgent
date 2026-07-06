

using namespace std;

class camera_impl;
class camera {
    unique_ptr<camera_impl/*,void(*)(camera_impl*)*/> pimpl;
    public:
    camera();
    void capture();
};