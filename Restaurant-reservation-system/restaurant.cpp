#include<bits/stdc++.h>

using namespace std;
struct Reservation {
    string name;
    string contactNumber;
    string date;
    string time;

    Reservation() : name(""), contactNumber(""), date(""), time("") {}

    Reservation(const string& name, const string& contactNumber, const string& date, const string& time)
        : name(name), contactNumber(contactNumber), date(date), time(time) {}

    bool operator<(const Reservation& other) const {
        return time < other.time;
    }

    bool operator==(const Reservation& other) const {
        return name == other.name && date == other.date && time == other.time;
    }
};

class Restaurant {
private:
    int capacity;
    unordered_map<string, unordered_map<string, int>> reservationsByDateTime;
    map<string, vector<Reservation>> reservationsByDate;
    unordered_map<string, int> tablesAvailable;

public:
    Restaurant(int capacity) : capacity(capacity) {
        setInitialTables("00:00", 1);
    }

    void makeReservation(const Reservation& reservation) {
        if (!isValidTime(reservation.time) ||!isValidDate(reservation.date)) {
            cout << "Invalid time or date format. Please enter time in HH:MM format and date in DD-MM-YYYY format." << endl;
            return;
        }

        if (reservationsByDateTime.find(reservation.date)!= reservationsByDateTime.end() &&
            reservationsByDateTime[reservation.date].find(reservation.time)!= reservationsByDateTime[reservation.date].end()) {
            if (reservationsByDateTime[reservation.date][reservation.time] + 1 > capacity || tablesAvailable[reservation.time] == 0) {
                cout << "Sorry, the requested date and time are not available for the desired capacity." << endl;
                return;
            }
        }

        reservationsByDateTime[reservation.date][reservation.time]++;
        reservationsByDate[reservation.date].push_back(reservation);
        tablesAvailable[reservation.time]--;
        sort(reservationsByDate[reservation.date].begin(), reservationsByDate[reservation.date].end());
        cout << "Reservation successfully made!" << endl;
    }

    void cancelReservation(const Reservation& reservation) {
        reservationsByDateTime[reservation.date][reservation.time]--;
        auto& reservations = reservationsByDate[reservation.date];
        auto it = find(reservations.begin(), reservations.end(), reservation);
        if (it != reservations.end()) {
            reservations.erase(it);
            tablesAvailable[reservation.time]++;
            cout << "Reservation for " << reservation.name << " at " << reservation.time << " on " << reservation.date << " cancelled successfully." << endl;
            if (reservations.empty()) {
                reservationsByDate.erase(reservation.date);
                cout << "All reservations on " << reservation.date << " have been cancelled. Date removed." << endl;
            }
        } else {
            cout << "No reservation found for " << reservation.name << " at " << reservation.time << " on " << reservation.date << "." << endl;
        }
    }

    void displayReservations() {
        if (reservationsByDate.empty()) {
            cout << "\nNo reservations yet." << endl;
            return;
        }

        cout << "\nCurrent Reservations:" << endl;
        for (const auto& dateEntry : reservationsByDate) {
            cout << "Date: " << dateEntry.first << endl;
            for (const auto& reservation : dateEntry.second) {
                cout << setw(10) << "Time: " << reservation.time << ", ";
                cout << setw(15) << "Name: " << reservation.name << endl;
            }
        }
    }

    void setInitialTables(const string& time, int numTables) {
        tablesAvailable[time] = numTables;
    }

private:
    bool isValidTime(const string& time) {
        if (time.length()!= 5) return false;
        if (time[2]!= ':') return false;
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        return hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60;
    }

    bool isValidDate(const string& date) {
        if (date.length()!= 10) return false;
        if (date[2]!= '-' || date[5]!= '-') return false;
        int day = stoi(date.substr(0, 2));
        int month = stoi(date.substr(3, 2));
        int year = stoi(date.substr(6, 4));
        return day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 2022 && year <= 2032;
    }
};

int main() {
    Restaurant restaurant(20);
    restaurant.setInitialTables("00:00", 20);

    while (true) {
        cout << "\n1. Make Reservation\n2. Cancel Reservation\n3. Display Reservations\n4. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string name, contactNumber, date, time;
            cout << "Enter name: ";
            cin>>name;
            cout << "Enter contact number: ";
            cin>>contactNumber;
            cout << "Enter date (DD-MM-YYYY): ";
            cin>>date;
            cout << "Enter time (HH:MM): ";
            cin>>time;

            Reservation reservation(name, contactNumber, date, time);
            restaurant.makeReservation(reservation);
        } else if (choice == 2) {
            string name, date, time;
            cout << "Enter name: ";
            cin>>name;
            cout << "Enter date (DD-MM-YYYY): ";
            cin>>date;
            cout << "Enter time (HH:MM): ";
            cin>>time;

            Reservation reservation(name,"", date, time);
            restaurant.cancelReservation(reservation);
        } else if (choice == 3) {
            restaurant.displayReservations();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}