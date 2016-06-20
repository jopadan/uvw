#include <iostream>
#include <uvw.hpp>


void f(uvw::Loop &loop) {
    uvw::Handle<uvw::Tcp> handle = loop.handle<uvw::Tcp>();
    auto cb = [h{handle}](uvw::UVWError err){ std::cout << "---" << ((bool)err) << std::endl; };
    uvw::Tcp &tcp = handle;
    tcp.connect<uvw::Tcp::IPv4>(std::string{"127.0.0.1"}, 80, cb);
}


int main() {
    uvw::Loop loop;
    f(loop);
    loop.runWait();
}