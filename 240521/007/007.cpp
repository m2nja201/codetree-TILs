#include <iostream>
#include <string>

using namespace std;

class coding{
    public:
        string code, points;
        int time;

        coding(string code, string points, int time){
            this->code = code;
            this->points = points;
            this->time = time;
        }

        void printing(){
            cout << "secret code : "<< this->code << endl;
            cout << "meeting point : " << this->points << endl;
            cout << "time : " << this->time; 
        }
};

int main() {
    string code, points;
    int time;

    cin >> code >> points >> time;

    coding codes1 = coding(code, points, time);
    codes1.printing();
    return 0;
}