#include <string>
#include <iostream>

#include <boost/di.hpp>
namespace di = boost::di;

template <class BusinessLogic = class BusinessLogic, class GUI = class GUI>
class App {
public:
    App(BusinessLogic bl, GUI g): business_logic{bl}, gui{g} {}

    void start() {
        gui.msg(business_logic.rule());
    }
private:
    BusinessLogic business_logic;
    GUI gui;
};

auto statement = []{};

class BusinessLogic_XYZ {
public:
    BOOST_DI_INJECT(BusinessLogic_XYZ, (named=statement) std::string stmnt): statement{stmnt} {}
    std::string rule() { return statement; }
private:
    std::string statement;
};

class GUI_123 {
public:
    void msg(std::string m) { std::cout << m << std::endl; }
};

int main() {
    auto injector = di::make_injector(
        di::bind<BusinessLogic>().to<BusinessLogic_XYZ>(),
        di::bind<std::string>().named(statement).to("Profit!!"),
        di::bind<GUI>().to<GUI_123>()
    );
    auto app = injector.create<App>();
    app.start();

    return 0;
}
