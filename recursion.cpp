#include <iostream>
#include <string>
using namespace std;

bool palin(string val, int str, int end);

int main() {
string name="ka";
cout<<palin(name,0,name.length()-1)<<endl;
    return 0;
}

bool palin(string val, int str, int end){
if(str>=end){
    return true;
}
if(val[str]!=val[end]){
    return false;
    }
return true;
}