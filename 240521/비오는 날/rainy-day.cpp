#include <iostream>
using namespace std;
#include <string>

class info{
    public:
        string date, day, weather;

        info(string date=" ", string day=" ", string weather=" "){
            this->date = date;
            this->day = day;
            this->weather = weather;
        }

        int isRain(){
            if (this->weather == "Rain"){
                return 1;
            } else return 0;
        }
};  

int main() {
    int n;
    cin >> n;

    info *infos = new info[n];
    for (int i=0; i < n; i++){
        string strs[3];
        cin >> strs[0] >> strs[1] >> strs[2];
        infos[i] = info(strs[0], strs[1], strs[2]);
    }

    string tmp_date = "2101-12-31";
    int tmp_idx = 0;
    for (int i = 0; i < n; i++){
        if (infos[i].isRain()){
            if (tmp_date > infos[i].date){
                tmp_date = infos[i].date;
                tmp_idx = i;
            }
        }
    }
    cout << infos[tmp_idx].date << " " << infos[tmp_idx].day << " " << infos[tmp_idx].weather;

    return 0;
}