#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hour; 
    int mins; 
    int secs;

public: 

    Time();

    void setTime(int setHour, int setMins, int setSecs) {
        hour = setHour;
        mins = setMins;
        secs = setSecs;
    }

    void addHours(int plusHours) {
        hour += plusHours;

        hour > 12 ? hour %= 12 : hour;
        hour == 0 ? hour = 12 : hour;
    }

    void addMins(int plusMins) {
        mins += plusMins;
        if(mins >= 60) {
            addHours(mins / 60);
            mins %= 60;
        }
    }

    void addSecs(int plusSecs) {
        secs += plusSecs;
        if(secs >= 60) {
            addMins(secs / 60);
            secs %= 60;
        }
    }

    void displayTime() {
        cout << endl << "TIME: " << setfill('0') << setw(2) << hour << ":" << setw(2) << mins << ":" << setw(2) << mins << endl;
    }
};

int main() {
    Time time;
    int x,y,z;
    cout << "Enter a time: h, m, s: ";
    cin >> x >> y >> z;
    time.setTime(x,y,z);
    int number = 1;
    while (number != 0) {
        cout << "Select 1: add3Hours\nSelect 2: add30Mins\nSelect 3: add30Secs\nSelect 4: displayTime\nSelect 0: To QUIT\n";
        cin >> number;
        switch(number) {
            case 1: time.addHours(3); break;
            case 2: time.addMins(30); break;
            case 3: time.addSecs(30); break;
            case 4: time.displayTime(); break;
            case 0: break;
            default: cout << "Enter a proper number: \n";
        }
        cout << endl;
    }
    return 0;
}

Time::Time() {
    hour = mins = secs = 0;
}