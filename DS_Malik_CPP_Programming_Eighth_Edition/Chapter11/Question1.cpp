#include <iostream>
#include <string>
using namespace std;

class clockType{
    protected:
        int hours;
        int minutes;
        int seconds;

    public:
        clockType(int h = 0, int m = 0, int s = 0) {
            hours = h;
            minutes = m;
            seconds = s;
        }

        void setTime(int h, int m, int s) {
            hours = h;
            minutes = m;
            seconds = s;
        }

        void printTime() const {
            cout << hours << ":" << minutes << ":" << seconds;
        }
};
class extClockType : public clockType{
    private:    
        string timez = "";
    public:
        extClockType(int h = 0, int m = 0, int s = 0, string timez = "") : clockType(h, m , s){
            this -> timez = timez;
        }
        void setTimeZone(string tz){
            timez = tz;
        }
        void printTimeZone()const{
            cout<<timez;
        }
        string getTimeZone(){
            return timez;
        }
};

int main() {
    extClockType myExtClock(10, 30, 0, "GMT");

    cout << "Current time: ";
    myExtClock.printTime();
    cout << " " << myExtClock.getTimeZone() << endl;

    myExtClock.setTimeZone("EST");

    cout << "Updated time zone: " << myExtClock.getTimeZone() << endl;

    return 0;
}
