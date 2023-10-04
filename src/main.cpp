#include <string>
#include <iostream>

#include <boost/di.hpp>
namespace di = boost::di;

class Named;

template <class T = Named>
class Exclamator {
public:
    Exclamator(T a): x{a} {}

    void f() {
        std::cout << x.name() << std::endl;
    }
private:
    T x;
};

class A {
public:
    std::string name() { return "A"; }
};

class B {
public:
    std::string name() { return "B"; }
};

class C {} ;

int main() {
/*    auto injector = di::make_injector(
        di::bind<Named>().to<A>()
    );

    auto xa = injector.create<Exclamator>();
    xa.f();*/

    A a;
    Exclamator xa {a};
    xa.f();

    B b;
    Exclamator xb {b};
    xb.f();

    C c;
    Exclamator xc {c};
//    xc.f();

    return 0;
}
