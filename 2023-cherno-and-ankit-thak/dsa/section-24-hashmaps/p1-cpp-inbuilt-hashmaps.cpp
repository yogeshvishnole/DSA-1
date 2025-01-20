#include <iostream>
#include <unordered_map>
#include <utility>
#include <string>
using namespace std;

int main(int argc, char **argv)
{

    // unordered map creation
    unordered_map<string, int> hashmap;

    // insertion in unordered_map

    // 1. using the pair class
    pair<string, int> p1("hello", 1);
    hashmap.insert(p1);

    // 2. like array
    hashmap["def"] = 2;

    // find or access keys in unordered map
    cout << hashmap["hello"] << endl;
    cout << hashmap.at("hello") << endl;
    // The above two mwthods of accesss will work same if key isalready present,but if not
    // present than at will throw exception while the bracket one will insert the key
    // and initialize the value by 0.

    // check present of a key usingg count method
    if (hashmap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }
    else
    {
        cout << "not present" << endl;
    }

    // if key is present count will give 1 else 0

    // see the size(number of keys in map)
    cout << hashmap.size() << endl;

    // for removing an key we can use erase method
    hashmap.erase("def");

    cout << hashmap.size() << endl;
}
