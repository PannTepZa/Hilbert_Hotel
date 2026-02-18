#include "hotel_class.h"

int main(){
    fstream files;
    files.open("D:\\CPP\\Hilbert_Hotel\\Hotel_Room.txt");
    if (!files) {
        cout << "Cannot open file\n";
        return 0;
    }
    Room rooms[5];
    RoomInfo info[20];
    int t_count = 0;
    string line;
    while (getline(files, line) && t_count < 5) {
        stringstream ss(line);

        string type, guest_s, bedcount_s, bedtype, bath, living_s, price_s;

        getline(ss, type, ',');
        getline(ss, guest_s, ',');
        getline(ss, bedcount_s, ',');
        getline(ss, bedtype, ',');
        getline(ss, bath, ',');
        getline(ss, living_s, ',');
        getline(ss, price_s, ',');

        int guest = stoi(guest_s);
        int bedcount = stoi(bedcount_s);
        bool living = (living_s == "Y");
        double price = stod(price_s);

        map<string,int> bed;
        bed[bedtype] = bedcount;

        rooms[t_count].set_data(type, guest, bed, bath, living, price);

        t_count++;
    }

        map<string, Room*> typeMap;
        for(int i = 0; i < t_count; i++){
            typeMap[rooms[i].getType()] = &rooms[i];
        }

        int r_count = 0;
        while (r_count < 20 && getline(files, line)) {
            if(line.empty()) continue;   

            stringstream ss(line);

            string num_s, type, occ_s;

            getline(ss, num_s, ',');
            getline(ss, type, ',');
            getline(ss, occ_s, ',');

            int num = stoi(num_s);
            bool occ = (occ_s == "YES");

            Room* rtype = typeMap[type];   

            info[r_count].setRoom(num, rtype, occ);
            r_count++;
        }


        cout << "------------------------" << endl;
        cout << "WELCOME TO HILBERT HOTEL" << endl;
        cout << "------------------------" << endl;
        char respond;
        int people;
        string bed_size,bath_size;
        double price;
        Date record;

        cout << "Are you a customer? (Y/N) : ";
        cin >> respond;
        if (respond == 'N') return 0;
        while (true){
            cout << "Please select date you want to check in" << endl;
            cout << "Years (in A.D) : ";
            cin >> record.years;
            cout << "Month (1-12) : ";
            cin >> record.month;
            if (daysInMonth(record.month,record.years) == 31) cout << "Date (1-31) : ";
            if (daysInMonth(record.month,record.years) == 30) cout << "Date (1-30) : ";
            if (daysInMonth(record.month,record.years) == 29) cout << "Date (1-29) : ";
            if (daysInMonth(record.month,record.years) == 28) cout << "Date (1-28) : ";
            cin >> record.day;
            cout << "You want to check in at "<< record.day << "/" << record.month << "/" << record.years << endl;
            cout << "Do you want to confirm? (Y/N) :";
            cin >> respond;
            if (respond == 'N') continue;
            cout << "Please select date you want to check out" << endl;
        }
        
        


        


        

        

    








}