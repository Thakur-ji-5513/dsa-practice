#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string,int> map;
    map["apple"] = 10;
    map["banana"] = 20;
    map["mango"] = 30;
    map["apple"]=40;
    cout<<"Apple count: "<<map["apple"]<<endl;
    cout<<"Banana count: "<<map["banana"]<<endl;
    cout<<"Mango count: "<<map["mango"]<<endl;
    cout<<"Grapes count: "<<map.at("mango")<<endl;
    // 2 operators can be used to acess valus in a unordere map:
    //1. map[key] - if key is not present, it will insert the key with default value
    //2. map.at(key) - if key is not present, it will throw an error

    // To check if a key is present in the map
    if(map.count("mango")>0)
    {
        cout<<"Mango is present in the map"<<endl;
    }
    else
    {
        cout<<"Mango is not present in the map"<<endl;
    }
    //2nd way to check if a key is present in the map
    if(map.find("mango")!=map.end())
    {
        cout<<"Mango is present in the map"<<endl;
    }
    else
    {
        cout<<"Mango is not present in the map"<<endl;
    }
    // To delete a key from the map
    map.erase("mango");
    // iterate over the map
    for(auto &pair:map){// here auto is used to automatically detect the type of pair and pair is the temporary variable that stores the key value pair and we used & to make it a reference variable
        cout<<"key: "<<pair.first<<" value: "<<pair.second<<endl;
    }

}