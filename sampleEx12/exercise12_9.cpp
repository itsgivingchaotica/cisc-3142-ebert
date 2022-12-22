#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::make_shared;

int main()
{
    int *q = new int(42);
    // object to white r points has value of 100
    int *r = new int(100);
    // r now points to object to which q points
    r = q;
    //
    auto q2 = make_shared<int>(42);
    cout << q2.use_count() << endl;
    auto r2 = make_shared<int>(100);
    cout << r2.use_count() << endl;
    r2 = q2;
    cout << r2.use_count() << endl;
    cout << q2.use_count() << endl;

    cout << *r << " " << *q << " " << *r2 << " " << *q2 << endl;
    return 0;
}