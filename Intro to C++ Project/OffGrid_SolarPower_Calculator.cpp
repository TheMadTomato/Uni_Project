#include <iostream>//cin.peek() cin.clear cin.ignore
#include <cstdlib>//system("clear")
#include <string>//stoi() stod() to_string
#include <cmath>//ceil()
#include <cctype>//toupper()
#include <iomanip>//setw() setprecision() fixed

using namespace std;

// Function to input an integer value without errors
void inputInteger(int& INT) {
    while (true) {
        if (cin >> INT) {
            if (cin.peek() == '\n') {
                break;
            }
        }
        cout << "\033[33m------------------------------------------------------------------------------------------\n\033[0m\033[1m\033[43m"
             << "                                         Integer!                                         "
             << "\n\033[0m\033[33m------------------------------------------------------------------------------------------\033[0m\n"
             << "Choice: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}
// Function to input a double value without errors
void inputDouble(double& DBL) {
    while (true) {
        if (cin >> DBL) {
            if (cin.peek() == '\n') {
                break;
            }
        }
        cout << "\033[33m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[43m"
             << "                                          Double!                                         "
             << "\n\033[0m\033[33m------------------------------------------------------------------------------------------\033[0m\n"
             << "Choice: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}
// Function to search for a code inside an array
int codeSearch(int find[], int code){
    for (int index = 0; index < 22; index ++) if (find[index] == code) return index;
    return -1;
}
// Function to obtain the total power usage
void obtainPowerUsage(double &totalPowerUsage) {
    cout << "\033[34m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[44m"
         << "                                 Welcome to PowerFlow                          0 to Exit  "
         << "\033[0m\n\033[34m------------------------------------------------------------------------------------------\033[0m\n";
    int choice = 0;
    do{
        cout << "[1] Enter household power usage per day.\n[2] Obtain household power usage per day.\n\033[34m"
             << "------------------------------------------------------------------------------------------\033[0m\n"
             << "Choice: ";
        inputInteger(choice);
        if (choice == 0) break;
        if (choice != 1 && choice != 2) {
            system("cls");
            cout << "\033[34m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[44m"
                 << "                                           1 | 2                               0 to Exit  "
                 << "\033[0m\n\033[34m------------------------------------------------------------------------------------------\033[0m\n";
        }
    }while (choice != 1 && choice != 2);
    if (choice == 0) {
        system("cls");
        return;
    }
    system("cls");
    // Enter household total power usage per day
    if (choice == 1){
        do{ 
            cout << "\033[34m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[44m"
                 << "                                       1 - 40000 W                             0 to Exit  "
                 << "\033[0m\n\033[34m------------------------------------------------------------------------------------------\033[0m\n";
            cout << "Power usage: "; 
            inputDouble(totalPowerUsage);
        }while(totalPowerUsage < 0 || totalPowerUsage > 40000);
        system("cls");
    }
    // Obtain household total power usage per day
    else if (choice == 2) {
        string appliances[22][3] = {{"Air Conditioners (9000BTU)", "0", "0"}, {"Air Conditioners (12000BTU)", "0", "0"}, {"Air Fryers", "0", "0"},
                                    {"Chargers", "0", "0"}, {"Coffee Machines", "0", "0"}, 
                                    {"Dish Washers", "0", "0"}, 
                                    {"Electrical Ovens", "0", "0"}, {"Electrical Stoves", "0", "0"}, {"Electrical Water Heaters", "0", "0"},
                                    {"Fans", "0", "0"}, 
                                    {"Hair Dryers", "0", "0"}, {"Hoovers", "0", "0"}, 
                                    {"Irons", "0", "0"}, 
                                    {"LCD Televisions", "0", "0"}, {"LED Televisions", "0", "0"}, {"Lights", "0", "0"}, 
                                    {"Microwaves", "0", "0"}, 
                                    {"Radios", "0", "0"}, {"Refrigerators", "0", "0"},
                                    {"Security Cameras", "0", "0"}, 
                                    {"Washing Machines", "0", "0"}, {"Wifi Modems", "0", "0"}};
        int power_USAGE[22] = {800, 900, 1500, 5, 1000, 1800, 2500, 1500, 1125, 75, 1200, 1400, 1100, 44, 38, 10, 1000, 9, 400, 15, 850, 20};
        int total_APPLIANCES = 0;
        bool run = true;
        while (run) {
            int choice = 0;
            cout << "\033[34m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[44m"
                 << "                                       Data Entry                              0 to Exit  "
                 << "\033[0m\n\033[34m------------------------------------------------------------------------------------------\033[0m";
            do{
                cout << "\n[1] Enter data of all appliances."
                    << "\n[2] Edit data of appliances."
                    << "\n[3] View data of appliances."
                    << "\n\033[34m------------------------------------------------------------------------------------------\033[0m"
                    << "\nChoice: ";
                inputInteger(choice);
                if (choice == 0) break;
                if(choice < 1 || choice > 3) {
                    system("cls");
                    cout << "\033[34m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[44m"
                         << "                                           1 | 2 | 3                           0 to Exit  "
                         << "\033[0m\n\033[34m------------------------------------------------------------------------------------------\033[0m";
                }
            }while(choice < 1 || choice > 3);
            if (choice == 0) {
                system("cls");
                break;
            }
            switch (choice) {
                // Enter data of all appliances
                case 1: {
                    system("cls");
                    if (totalPowerUsage == 40000) {
                            cout << "\033[31m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[41m"
                                 << "                                   Total Power Reached!                                   "
                                 << "\033[0m\n\033[31m------------------------------------------------------------------------------------------\033[0m\n"
                                 << "Total appliances: \033[33m" << total_APPLIANCES << "\033[0m units\nTotal power usage: \033[36m" << fixed << setprecision(1) << totalPowerUsage << "\033[0m W\n";
                            break;
                        }
                    cout << "\033[34m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[44m"
                         << "  0 to Skip                                                                   -1 to Exit  "
                         << "\033[0m\n\033[34m------------------------------------------------------------------------------------------\033[0m\n";
                    int amount = 0;
                    int count = 0;
                    for (int code = 0; code < 22; code++) {
                        if (code != 0) cout << "\033[34m------------------------------------------------------------------------------------------\033[0m\n";
                        cout << "\033[1m[" << code + 1 << "] " << appliances[code][0] << ":\033[0m\n";
                        do{
                            cout << "    - Active amount in your house: ";
                            inputInteger(amount);
                            if (amount == -1) break;
                            if (amount < 0 || amount > 20) cout << "\033[34m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[44m"
                                                                << "                                          1 - 20                                        "
                                                                << "\033[0m\n\033[34m------------------------------------------------------------------------------------------\033[0m\n";
                        }while(amount < 0 || amount > 20);
                        if (amount == -1) {
                                    system("cls");
                                    break;
                                }
                        if (amount == 0) continue;
                        int limit = 24 * amount;
                        double hour = 0;
                        do{
                            cout << "    - Total running hours per day: ";
                            inputDouble(hour);
                            if (hour == -1) break;
                            if (hour <= 0 || hour > limit) cout << "\033[34m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[44m"
                                                                << "                                         0.1 - " << limit << "                                         "
                                                                << "\033[0m\n\033[34m------------------------------------------------------------------------------------------\033[0m\n";
                        }while(hour <= 0 || hour > limit);
                        if (hour == -1) {
                                    system("cls");
                                    break;
                                }
                        count ++;
                        double power = power_USAGE[code] * hour;
                        if (totalPowerUsage + power > 40000) {
                            system("cls");
                            power = 40000 - totalPowerUsage;
                            hour = power / power_USAGE[code];
                            cout << "\033[31m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[41m"
                                 << "                                   Total Power Reached!                                   "
                                 << "\033[0m\n\033[31m------------------------------------------------------------------------------------------\033[0m\n"
                                 << "Running hours for \033[1m" << appliances[code][0] << "\033[0m adjusted to: \033[31m" << fixed << setprecision(1) << hour << "\033[0m hours\n";
                        }
                        appliances[code][1] = to_string(stoi(appliances[code][1]) + amount);
                        appliances[code][2] = to_string(stoi(appliances[code][2]) + power);
                        total_APPLIANCES += amount;
                        totalPowerUsage += power;
                        if (totalPowerUsage == 40000){
                            cout << "\033[32m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[42m"
                                 << "                                       Data Saved!                                        "
                                 << "\033[0m\n\033[32m------------------------------------------------------------------------------------------\033[0m\n"
                                 << "Total appliances: \033[33m" << total_APPLIANCES << "\033[0m units\nTotal power usage: \033[36m" << fixed << setprecision(1) << totalPowerUsage << "\033[0m W\n";
                            break;
                        }
                    }
                    if (totalPowerUsage == 40000) break;
                    else if (count == 0 && amount == -1) {
                        system("cls");
                        cout << "\033[31m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[41m"
                             << "                                     No Data Saved!                                       "
                             << "\033[0m\n\033[31m------------------------------------------------------------------------------------------\033[0m\n"
                             << "Total appliances: \033[33m" << total_APPLIANCES << "\033[0m units\nTotal power usage: \033[36m" << fixed << setprecision(1) << totalPowerUsage << "\033[0m W\n";
                    }
                    else {
                        system("cls");
                        cout << "\033[32m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[42m"
                             << "                                      Data Saved!                                         "
                             << "\033[0m\n\033[32m------------------------------------------------------------------------------------------\033[0m\n"
                             << "Total appliances: \033[33m" << total_APPLIANCES << "\033[0m units\nTotal power usage: \033[36m" << fixed << setprecision(1) << totalPowerUsage << "\033[0m W\n";
                    }
                }break;
                // Edit data of appliances
                case 2: {
                    system("cls");
                    string add_delete;
                    do{
                        cout << "\033[34m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[44m"
                             << "                                      Add | Delete                             0 to Exit  "
                             << "\033[0m\n\033[34m------------------------------------------------------------------------------------------\033[0m\n"
                             << "Choice: ";
                        cin >> add_delete;
                        if (add_delete == "0") break;
                        for (char& c : add_delete) c = toupper(c);
                        system("cls");
                    }while(add_delete != "ADD" && add_delete != "DELETE");
                    if (add_delete == "0") {
                        system("cls");
                        break;
                    }
                    // Add data of appliances
                    if (add_delete == "ADD") {
                        system("cls");
                        bool more = true; 
                        while (more == true){
                            if (totalPowerUsage == 40000) {
                                cout << "\033[31m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[41m"
                                     << "                                   Total Power Reached!                                   "
                                     << "\033[0m\n\033[31m------------------------------------------------------------------------------------------\033[0m\n"
                                     << "Total appliances: \033[33m" << total_APPLIANCES << "\033[0m units\nTotal power usage: \033[36m" << fixed << setprecision(1) << totalPowerUsage << "\033[0m W\n";
                                break;
                            }
                            int code = 0;
                            do{
                                cout << "\033[32m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[42m"
                                     << "                                          Add Data                             0 to Exit  "
                                     << "\033[0m\n\033[32m------------------------------------------------------------------------------------------\033[0m\n";
                                for (int code = 0; code < 22; code++) {
                                    if (appliances[code][1] != "0") cout << "[" << code + 1 << "]\033[1m " << appliances[code][0] << "\033[0m: \033[33m" << appliances[code][1] << "\033[0m units | \033[36m" 
                                                                         << fixed << setprecision(1) <<  stod(appliances[code][2]) << "\033[0m W\n";
                                    else cout << "[" << code + 1 << "]\033[1m " << appliances[code][0] << "\033[0m\n";
                                }
                                cout << "\033[32m------------------------------------------------------------------------------------------\033[0m\n"
                                    << "Enter code of the appliance: ";
                                inputInteger(code);
                                if (code == 0) break;
                                system("cls");
                            }while(code < 1 || code > 22);
                            if (code == 0) {
                                    system("cls");
                                    cout << "\033[31m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[41m"
                                         << "                                     No Data Saved!                                       "
                                         << "\033[0m\n\033[31m------------------------------------------------------------------------------------------\033[0m\n"
                                         << "Total appliances: \033[33m" << total_APPLIANCES << "\033[0m units\nTotal power usage: \033[36m" << fixed << setprecision(1) << totalPowerUsage << "\033[0m W\n";
                                    break;
                                }
                            code--;
                            int amount = 0;
                            cout << "\033[32m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[42m"
                                 << "                                          Add Data                             0 to Exit  "
                                  << "\033[0m\n\033[32m------------------------------------------------------------------------------------------\033[0m\n";
                            cout << "\033[1m[" << code + 1 << "] " << appliances[code][0] << ":\033[0m\n";
                            do{
                                cout << " - Active amount in your house: ";
                                inputInteger(amount);
                                if (amount == 0) break;
                                if (amount < 1 || amount > 20) cout << "\033[32m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[42m"
                                                                    << "                                           1 - 20                                         "
                                                                    << "\033[0m\n\033[32m------------------------------------------------------------------------------------------\033[0m\n";
                            }while(amount < 1 || amount > 20);
                            if (amount == 0) {
                                    system("cls");
                                    cout << "\033[31m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[41m"
                                         << "                                     No Data Saved!                                       "
                                         << "\033[0m\n\033[31m------------------------------------------------------------------------------------------\033[0m\n"
                                         << "Total appliances: \033[33m" << total_APPLIANCES << "\033[0m units\nTotal power usage: \033[36m" << fixed << setprecision(1) << totalPowerUsage << "\033[0m W\n";
                                    break;
                                }
                            int limit = 24 * amount;;
                            double hour = 0;
                            do{
                                cout << " - Total running hours per day: ";
                                inputDouble(hour);
                                if (hour == 0) break;
                                if (hour <= 0 || hour > limit) cout << "\033[32m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[42m"
                                                                    << "                                         0.1 - " << limit << "                                         "
                                                                    << "\033[0m\n\033[32m------------------------------------------------------------------------------------------\033[0m\n";
                            }while(hour <= 0 || hour > limit);
                            if (hour == 0) {
                                    system("cls");
                                    cout << "\033[31m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[41m"
                                         << "                                     No Data Saved!                                       "
                                         << "\033[0m\n\033[31m------------------------------------------------------------------------------------------\033[0m\n"
                                         << "Total appliances: \033[33m" << total_APPLIANCES << "\033[0m units\nTotal power usage: \033[36m" << fixed << setprecision(1) << totalPowerUsage << "\033[0m W\n";
                                    break;
                                }
                            double power = power_USAGE[code] * hour;
                            system("cls");
                            if (totalPowerUsage + power > 40000) {
                                power = 40000 - totalPowerUsage;
                                hour = power / power_USAGE[code];
                                cout << "\033[31m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[41m"
                                     << "                                   Total Power Reached!                                   "
                                     << "\033[0m\n\033[31m------------------------------------------------------------------------------------------\033[0m\n"
                                     << "Running hours for \033[1m" << appliances[code][0] << "\033[0m adjusted to: \033[31m" << fixed << setprecision(1) << hour << "\033[0m hours\n";
                            }
                            appliances[code][1] = to_string(stoi(appliances[code][1]) + amount);
                            appliances[code][2] = to_string(stod(appliances[code][2]) + power);
                            total_APPLIANCES += amount;
                            totalPowerUsage += power;
                            cout << "\033[32m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[42m"
                                 << "                                       Data Added!                                        "
                                 << "\033[0m\n\033[32m------------------------------------------------------------------------------------------\033[0m\n"
                                 << "[" << code + 1 << "] \033[1m" << appliances[code][0] << "\033[0m: \033[33m" << appliances[code][1] << "\033[0m units | \033[36m"
                                 << fixed << setprecision(1) <<  stod(appliances[code][2]) << "\033[0m W\n";
                            string answer;
                            do{
                                cout << "\033[32m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[42m"
                                     << "                                         Yes | No                                         "
                                     << "\033[0m\n\033[32m------------------------------------------------------------------------------------------\033[0m\n"
                                     << "Add an additional appliance: ";
                                cin >> answer;
                                for (char& c : answer) c = toupper(c);
                                system("cls");
                            }while (answer != "YES" && answer != "NO");
                            if (answer == "NO") more = false;
                            system("cls");
                        }
                    }
                    // Delete data of appliances
                    else if (add_delete == "DELETE") {
                        system("cls");
                        bool more = true; 
                        while (more){
                            int count = 0;
                            for (int code = 0; code < 22; code++) if (appliances[code][1] != "0") count++;
                            if (count == 0) {
                                cout << "\033[31m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[41m"
                                     << "                                   No Data To Delete!                                     "
                                     << "\033[0m\n\033[31m------------------------------------------------------------------------------------------\033[0m\n"
                                     << "Total appliances: \033[33m" << total_APPLIANCES << "\033[0m units\nTotal power usage: \033[36m" << totalPowerUsage << "\033[0m W\n";
                                break;
                            }
                            else {
                                int search = 0;
                                int code = 0;
                                do{
                                    cout << "\033[31m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[41m"
                                         << "                                       Delete Data                             0 to Exit  "
                                         << "\033[0m\n\033[31m------------------------------------------------------------------------------------------\033[0m\n";
                                    int find[22];
                                    for (int code = 0; code < 22; code++) {
                                        if (appliances[code][1] == "0") continue;
                                        else {
                                            find[code] = (code + 1);
                                            cout << "[" << code + 1 << "]\033[1m " << appliances[code][0] << "\033[0m: \033[33m" << appliances[code][1] << "\033[0m units | \033[36m" 
                                            << fixed << setprecision(1) <<  stod(appliances[code][2]) << "\033[0m W\n";
                                        }
                                    }
                                    cout << "\033[31m------------------------------------------------------------------------------------------\033[0m\n"
                                        << "Enter code of the appliance: ";
                                    inputInteger(code);
                                    if (code == 0) break;
                                    search = codeSearch(find, code);
                                    system("cls");
                                }while((code < 1 || code > 22) || (search == -1));
                                if (code == 0) {
                                    system("cls");
                                    cout << "\033[31m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[41m"
                                         << "                                   No Data Deleted!                                       "
                                         << "\033[0m\n\033[31m------------------------------------------------------------------------------------------\033[0m\n"
                                         << "Total appliances: \033[33m" << total_APPLIANCES << "\033[0m units\nTotal power usage: \033[36m" << fixed << setprecision(1) << totalPowerUsage << "\033[0m W\n";
                                    break;
                                }
                                code--;
                                if (appliances[code][1] != "0") {
                                    total_APPLIANCES -= stoi(appliances[code][1]);
                                    totalPowerUsage -= stod(appliances[code][2]);
                                    appliances[code][1] = "0";
                                    appliances[code][2] = "0";
                                    cout << "\033[31m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[41m"
                                         << "                                      Data Deleted!                                       "
                                         << "\033[0m\n\033[31m------------------------------------------------------------------------------------------\033[0m\n"
                                         << "[" << code + 1 << "]\033[1m " << appliances[code][0] << "\033[0m: \033[31m" << appliances[code][1] << "\033[0m units | \033[36m" 
                                         << fixed << setprecision(1) <<  stod(appliances[code][2]) << "\033[0m W\n";
                                }
                                count = 0;
                                for (int code = 0; code < 22; code++) if (appliances[code][1] != "0") count++;
                                if (count == 0) {
                                    cout << "\033[31m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[41m"
                                         << "                                     No Data To Delete!                                   \033[0m\n\033[31m"
                                         << "------------------------------------------------------------------------------------------\033[0m\n"
                                         << "Total appliances: \033[33m" << total_APPLIANCES << "\033[0m units\nTotal power usage: \033[36m" << fixed << setprecision(1) << totalPowerUsage << "\033[0m W\n";
                                    break;
                                }
                                else {
                                    string answer;
                                    do{
                                        cout << "\033[31m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[41m"
                                             << "                                         Yes | No                                         "
                                             << "\033[0m\n\033[31m------------------------------------------------------------------------------------------\033[0m\n"
                                             << "Delete an additional appliance: ";
                                        cin >> answer;
                                        for (char& c : answer) c = toupper(c);
                                        system("cls");
                                    }while (answer != "YES" && answer != "NO");
                                    if (answer == "NO") more = false;
                                    system("cls");
                                }
                            }
                        }
                    }
                }break;
                // View data of appliances
                case 3: {
                    system("cls");
                    cout << "\033[35m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[45m"
                         << "                                     Appliance Data                                       "
                         << "\033[0m\n\033[35m------------------------------------------------------------------------------------------\033[0m\n";
                    int count = 0;  
                    for (int code = 0; code < 22; code++) {
                       if (appliances[code][1] != "0") {
                            count++;
                            cout << "[" << code + 1 << "]\033[1m " << appliances[code][0] << "\033[0m: \033[33m" << appliances[code][1] << "\033[0m units | \033[36m" 
                            << fixed << setprecision(1) <<  stod(appliances[code][2]) << "\033[0m W\n";
                        }
                    }
                    if (count == 0) {
                        system("cls");
                        cout << "\033[31m------------------------------------------------------------------------------------------\033[31m\n\033[1m\033[41m"
                             << "                                      No Data Saved!                                      "
                             << "\033[0m\n\033[31m------------------------------------------------------------------------------------------\033[0m\n";
                    }
                    else cout << "\033[35m------------------------------------------------------------------------------------------\033[0m\n";
                    cout << "Total appliances: \033[33m" << total_APPLIANCES << "\033[0m units\nTotal power usage: \033[36m" << totalPowerUsage << "\033[0m W\n";
                }break;
            }
        }
    }
}
// Function to obtain the components needed
void obtainComponents(double totalPowerUsage) {
    system("cls");
    if (totalPowerUsage == 0) {
        cout << "\033[31m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[41m"
             << "                                      No Data Saved!                                      "
             << "\033[0m\n\033[31m------------------------------------------------------------------------------------------\033[0m\n"
             << "Total appliances: \033[33m0\033[0m units\nTotal power usage: \033[36m" << fixed << setprecision(1) << totalPowerUsage << "\033[0m W\n";
        return;
    }
    string components[3][3] = { {"0", "0", "0"}, {"0", "0", "0"}, {"0", "0", "0"} };
    // Inverter
    if(totalPowerUsage <= 20000){
        components[0][0] = "1";
        if(totalPowerUsage <= 3000) {
            components[0][1] = "3000";
            components[0][2] = "5116";
        }
        else if(totalPowerUsage <= 4500) {
            components[0][1] = "4500";
            components[0][2] = "6140";
        }
        else if(totalPowerUsage <= 5000) {
            components[0][1] = "5000";
            components[0][2] = "6450";
        }
        else if(totalPowerUsage <= 7500) {
            components[0][1] = "7500";
            components[0][2] = "8111";
        }
        else if(totalPowerUsage <= 15000) {
            components[0][1] = "15000";
            components[0][2] = "14500";
        }
        else {
            components[0][1] = "20000";
            components[0][2] = "23125";
        }
    }
    else{
        components[0][0] = "2";
        int powerLeft = totalPowerUsage - 20000;
        if(powerLeft <= 3000) {
            components[0][1] = "23000";
            components[0][2] = "28241";
        }
        else if(powerLeft <= 4500) {
            components[0][1] = "24500";
            components[0][2] = "29265";
        }
        else if(powerLeft <= 5000) {
            components[0][1] = "25000";
            components[0][2] = "29575";
        }
        else if(powerLeft <= 7500) {
            components[0][1] = "27500";
            components[0][2] = "31236";
        }
        else if(powerLeft <= 15000) {
            components[0][1] = "35000";
            components[0][2] = "37625";
        }
        else {
            components[0][1] = "40000";
            components[0][2] = "46250";
        }
    }
    // Battery
    int batteriesRequired = ceil(stoi(components[0][1]) * 4 * 0.7 * 0.8 / (400 * 48));
    components[1][0] = to_string(batteriesRequired);
    components[1][1] = "400";
    components[1][2] = to_string(5100 * batteriesRequired);
    // Panel
    int panelsRequired = ceil(totalPowerUsage / 600);
    components[2][0] = to_string(panelsRequired);
    components[2][1] = "600";
    components[2][2] = to_string(200 * panelsRequired);
    // Output the results
    cout << "\033[34m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[44m"
         << "                                         Invoice                                          "
         << "\033[0m\n\033[34m------------------------------------------------------------------------------------------\033[0m\n"
         << "               ----------------------------------------------------------\n"
         << "               |\033[45m    Component    \033[0m|\033[46m   Power   \033[0m|\033[43m   Quantity   \033[0m|\033[42m   Price   \033[0m|\n"
         << "               ----------------------------------------------------------\n"
         << "               |\033[1m\033[35m   Inverters     \033[0m|\033[36m" << setw(7) << components[0][1] << "\033[0m W  |\033[33m" 
         << setw(12) << components[0][0] << "\033[0m  |  $\033[32m" << setw(7) << components[0][2] << "\033[0m |\n"
         << "               |\033[1m\033[35m   Batteries     \033[0m|\033[36m" << setw(7) << components[1][1] << "\033[0m Ah |\033[33m" 
         << setw(12) << components[1][0] << "\033[0m  |  $\033[32m" << setw(7) << components[1][2] << "\033[0m |\n"
         << "               |\033[1m\033[35m   Solar Panels  \033[0m|\033[36m" << setw(7) << components[2][1] << "\033[0m W  |\033[33m" 
         << setw(12) << components[2][0] << "\033[0m  |  $\033[32m" << setw(7) << components[2][2] << "\033[0m |\n"
         << "               ----------------------------------------------------------\n"
         << "               |\033]1m\033[41m      Total      \033[0m|\033[36m" << setw(7) << fixed << setprecision(1) << totalPowerUsage << "\033[0m W  |\033[33m" 
         << setw(12) << stoi(components[0][0]) + stoi(components[1][0]) + stoi(components[2][0]) << "\033[0m  |  $\033[32m" 
         << setw(7) << stoi(components[0][2]) + stoi(components[1][2]) + stoi(components[2][2]) << "\033[0m |\n"
         << "               ----------------------------------------------------------\n";
}
int main() {
    string answer;
    do{
        system("cls");
        double totalPowerUsage = 0;
        // Obtain total power usage
        obtainPowerUsage(totalPowerUsage);
        // Obtain components needed
        obtainComponents(totalPowerUsage);
        // Repeat the program
        do{
            cout << "\033[34m------------------------------------------------------------------------------------------\033[0m\n\033[1m\033[44m"
                 << "                                         Yes | No                                         "
                 << "\033[0m\n\033[34m------------------------------------------------------------------------------------------\033[0m\n"
                 << "Repeat the program: ";
            cin >> answer;
            for (char& c : answer) c = toupper(c);
            system("cls");
        }while (answer != "YES" && answer != "NO");
    }while(answer == "YES" && answer != "NO");
    system("cls");
return 0;
}