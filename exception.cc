#include <iostream>
using namespace std;
int main()
{
    std::cout<<"Hello World" << endl;
    
    try {
        cout << "trying" << endl;
        throw runtime_error("runtime error");
    } catch (const exception& err){
        cout << "error=" << err.what() << endl;
    }

    return 0;
}
