#include <fstream> // istream I/O
#include <iostream> // cout
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
//#include <time.h> // timer
#include <ctime>

using namespace std;

int main(int argc, char* argv[]) {

    clock_t start = clock();

    std::ifstream infile("factoring.in");

    vector<int> v;
    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        long int a;
        if (!(iss >> a) ){ 
            cout<<"hej"<<endl;
            break; } // error
            cout<<a<<endl;
        }   

    for(int i = 0; i < v.size(); ++i){
        cout<<v[i]<<endl;
    }

    return 0;
}
