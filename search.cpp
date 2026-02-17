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

        for(int i = 0; i < r_count; i++){
        cout << "Room: " << info[i].getNumber()
             << " | Type: " << info[i].getTypePtr()->getType()
             << " | Price: " << info[i].getTypePtr()->getPrice()
             << " | Occupied: " 
             << (info[i].isOccupied() ? "YES" : "NO")
             << endl;
        }

        

    








}