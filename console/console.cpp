#include "linked_list/linked_list.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using namespace Tlink;



int main() {
    setlocale(LC_ALL, "rus");
    size_t b[5] {1, 5, 3, 4, 5};
    LinkedList<string> a(5, b);
    auto c = add_string(a);
    cout << c << endl;
    ofstream file;
    file.open(c);
    if (!file)
    {
        cout << "Файл не открыт"<<endl;
        file.close();
        string line;
        ifstream file_c(re_string(c));
        if (file_c.is_open())
        {
            while (std::getline(file_c, line))
            {
                std::cout << line << std::endl;
            }
        }
        if (file_c) {
            cout << "Файл открыт, всё круто" << endl;
        }
        file_c.close();

    }
    else {
        cout << "Файл открыт, всё круто" << endl;
    }


    
    return 0;

}
