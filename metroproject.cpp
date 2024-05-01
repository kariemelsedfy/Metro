#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <typeinfo>
using namespace std;


int currentDay = 15, currentmonth = 4, currentyear = 2024;


struct DATE
{
    int day = currentDay, month = currentmonth, year = currentyear;
};
struct ride_histoy
{
    int userId = 0;
    string start_station, end_station, userName, subscriptionType;
    DATE  DOP;
}HISTORY[500];
struct SUBSCRIPTION
{
    bool is_subscribed = 0;
    string type = "null";
    DATE START_date, END_date;
    int rides = 0, stage = 0, available_stations = 0;
};
struct USER
{
    int ride_index = 0, wallet_balance = 0;
    string  name, password, phone;
    char type = 0; //D for admin C for customer
    int id = 0;
    float balance = 0;
    SUBSCRIPTION SUB;
}users[50];


struct price_of {
    int stage1 = 6, stage2 = 8, stage3 = 12, stage4 = 15;
    int student_stage1 = 33, student_stage2 = 41, student_stage3 = 50, student_stage4 = 65;
    int publicMonth_stage1 = 230, publicMonth_stage2 = 290, publicMonth_stage3 = 340, publicMonth_stage4 = 450;
    int publicYear_stage1 = 1500, publicYear_stage2 = 2500, publicYear_stage3 = 3500, publicYear_stage4 = 4500;
    int wallet_limit = 400;
}price;


string stations[3][100] = {
    // line 1    
    { "      New Marg      ","      El-marg       ","   Ezbet El-Nakhl   ","      Ain Shams     ","    El-Matareyya    ","Helmeyet El-Zaitoun "
     ," Hadayeq El-Zaitoun ","   Saray El-Qobba   ","  Hammamat El-Qobba ","   Kobri El-Qobba   ","   Manshiet El-Sadr ","    El-Demerdash    "
     ,"       Ghamra       ","     Al-shohadaa    ","        Orabi       ","       Nasser       ","        Sadat       ","   Saad Zaghloul    "
     ,"  Al-Sayeda Zeinab  ","  El-Malek El-Saleh ","     Mar Girgis     ","      El-Zahraa     ","     Dar El-Salam   ","   Hadayek El-Maadi "
     ,"        Maadi       ","  Sakanat El-Maadi  ","     Tora El-Balad  ","       Kozzika      ","    Tura El-Esmant  ","      Elmasraa      "
     ,"   Hadayek Helwan   ","      Wadi Hof      ","  Helwan University ","     Ain Helwan     ","       Helwan       " },
    // line 2   
   { " Shubra Al-Khaimah  ","   Koliet El-Zeraa  ","      Mezallat      ","      Khalafawy     ","     St. Teresa     ","    Rod El-Farag    "
    ,"       Masarra      ","     Al-shohadaa    ","       Attaba       ","   Mohamed Naguib   ","        Sadat       ","       Opera        "
    ,"        Dokki       ","      El-Bohoth     ","   Cairo University ","       Faisal       ","        Giza        ","   Omm El-Masryeen  "
    ,"    Sakiat Mekky    ","       El_Monib     " },
    // line 3
   { "     Rod Elfarag    ","     Ring Road      ","     Al-Qawmeya     ","      El-Bohy       ","       Imbaba       ","        Sudan       "
    ,"       Kit Kat      ","    Safaa Hegazy    ","       Maspero      ","       Nasser       ","       Attaba       ","   Bab El Shaaria   "
    ,"      El Geish      ","     Abdou Pasha    ","      Abbassia      ","    Ard El maared   ","       Stadium      ","   Koleyet El-Banat "
    ,"       Al-Ahram     ","       Haroun       ","      Heliopolis    ","     Alf Maskan     ","    Nadi El-Shams   ","      El-Nozha      "
    ,"   Hesham Barakat   ","        Qobaa       "," Omar Ibn El-Khattab","    El Haykestep    ","    Adly Mansour    " }
};


string nameOFcommonL1_L2 = "     Al-shohadaa    ";
const int shohadaa_index_in_line1 = 13;
const int shohadaa_index_in_line2 = 7;
string nameOFcommonL1_L3 = "       Nasser       ";
const int nasser_index_in_line1 = 15;
const int nasser_index_in_line3 = 9;
string nameOFcommonL2_L3 = "       Attaba       ";
const int attaba_index_in_line2 = 8;
const int attaba_index_in_line3 = 10;




int station_num[3] = { 35, 20, 29 };



// changing date manually by user
void change_date() {
    cout << "enter the current day : "; cin >> currentDay;
    cout << "enter the current month : "; cin >> currentmonth;
    cout << "enter the current year : "; cin >> currentyear;
}
void REGISTRATION();
void LOG_IN();
void main_menu();      // the main menu which contains registration, login and exit functions
void user_menu();      /* user menu which contains functions like buy and manage subscription,
                          show and update personal info, view stations and making ride */
void Purchase_sub();   // details about subscription types 
void choice_subs();    // fun. makes user choose which type and which stage
void uptade_balance(); // showing and updating balance
void show_inf();       // show personal informations and changing it if user wanted
void mangeSUBS();      // view and Manages subscription info.
void view_station();   // view stations and making ride
void make_ride(int, int, int, int);
void save_rides_history(int, int, int, int);
void view_rides_history_forUSER();
void admin_menu();
void user_management();
void subscription_plan_management();
void printing_stations(int, int, int, int, int, int, int);






void view_rides_history_forADMIN();
void station_management();
void fare_management();
void admin_sub_manag();
void admin_user_manag();
void showStation();
void add_station(string, int);
void removeStation(int, int);
void editStation(int, string, int);




int main() {
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t===============================\n\n"
        << "\t\t\t\t\t\t\t\t\t\t\t\t WELCOME TO METRO MATE SYSTEM\n\n"
        << "\t\t\t\t\t\t\t\t\t\t\t\t===============================\n";


    main_menu();
    return 0;
}


void main_menu() {


    cout << "\t\t\t\t\t\t\t\t\t\t\t\t-------------------------------\n"
        << "\t\t\t\t\t\t\t\t\t\t\t\t          main menu\n"
        << "\t\t\t\t\t\t\t\t\t\t\t\t-------------------------------\n";
    char choice;
    bool exit_program = false;
    cout << " [1] Register/Sign Up \n";
    cout << " [2] Log In\n";
    cout << " [3] EXIT Program!!\n\n";
    cout << " | Please enter your choice : ";
    cin >> choice;


    switch (choice)
    {
    case '1':
        system("cls");
        REGISTRATION();
        main_menu();
        break;
    case '2':
        system("cls");
        LOG_IN();
        break;
    case '3':
        exit(0);
        break;
    default:
        system("cls"); // Use appropriate clear screen command for your OS.
        cout << "Please select from the options given\n";
        main_menu();
    }


}


void user_menu()
{


    char choice;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t------------------------------\n"
        << "\t\t\t\t\t\t\t\t\t\t\t\t          user menu\n"
        << "\t\t\t\t\t\t\t\t\t\t\t\t-------------------------------\n";


    cout << "  [1] Purchase Subscription\n"
        << "  [2] Manage Subscription\n"
        << "  [3] Update Balance\n"
        << "  [4] Check-In/Check-Out for Rides\n"
        << "  [5] View Ride History\n"
        << "  [6] Update Personal Information\n"
        << "  [7] Change Current Date\n"
        << "  [8] Log Out\n\n"
        << "  Please enter your choice : ";
    cin >> choice;


    switch (choice)
    {
    case '1':
        system("cls");
        Purchase_sub();
        user_menu();
        break;
    case '2':
        system("cls");
        mangeSUBS();
        user_menu();
        break;
    case '3':
        system("cls");
        uptade_balance();
        user_menu();
        break;
    case '4':
        system("cls");
        view_station();
        user_menu();
        break;
    case '5':
        view_rides_history_forUSER();
        user_menu();
        break;
    case '6':
        system("cls");
        show_inf();
        user_menu();
        break;
    case '7':
        change_date();
        user_menu();
        break;
    case '8':
        system("cls");
        cout << " |logout DONE\n";
        main_menu();
        break;
    default:
        system("cls");
        cout << " Please select from the options given\n";
        user_menu();
        break;
    }
}
int index = 0;
void REGISTRATION()
{
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t------------------------------\n"
        << "\t\t\t\t\t\t\t\t\t\t\t\t        Registration Page\n"
        << "\t\t\t\t\t\t\t\t\t\t\t\t-------------------------------\n";


    char userType;
    do {
        cout << "  TYPE (admin(D), customer(C)): ";
        cin >> userType;
        userType = toupper(userType); // Convert input to uppercase
        if (userType != 'C' && userType != 'D') {
            cout << " | Invalid input! The user type should be 'C' for customer or 'D' for Admin.\n";
        }
    } while (userType != 'C' && userType != 'D');


    users[index].type = userType;
    users[index].id = 100 + rand() % 200;  // getting random id from 100 to 200
    cin.ignore(); // Clear input buffer
    cout << "  User Name    : "; getline(cin, users[index].name);
    cout << "  phone number : "; cin >> users[index].phone;
    cout << "  PASSWORD     : "; cin >> users[index].password;
    cout << "  your id is   : " << users[index].id << endl;
    cout << "  Registration has done\n\n";
    index++;
}
int login_index = -1;  // index to be used in whole program as element in users array to access single user
void LOG_IN()
{
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t------------------------------\n"
        << "\t\t\t\t\t\t\t\t\t\t\t\t          Login Page\n"
        << "\t\t\t\t\t\t\t\t\t\t\t\t-------------------------------\n";
    int id;
    string pass;


    for (int attempt = 0; attempt < 3; attempt++)
    {
        cout << " | Enter your ID and password\n";
        cout << " | ID       : "; cin >> id;
        cout << " | Password : "; cin >> pass;


        bool found = false;
        for (int i = 0; i < index; i++)
        {
            if (users[i].id == id && users[i].password == pass)
            {
                if (users[i].type == 'c' || users[i].type == 'C')
                {
                    found = true;
                    system("cls");


                    cout << " | Login successful!\n"
                        << " | WELCOME " << users[i].name << endl;
                    login_index = i;
                    user_menu();
                }
                else if (users[i].type == 'd' || users[i].type == 'D')
                {
                    found = true;
                    system("cls");
                    cout << " | Login successful!\n"
                        << "  =================================\n"
                        << "   WELCOME " << users[i].name << endl
                        << "  =================================\n";


                    login_index = i;
                    admin_menu();
                }
            }
        }


        cout << " | Invalid ID or password. Please try again.\n";
    }


    cout << " | You have exceeded the maximum number of login attempts. Exiting.\n";
}


void price_list_stage() {
    cout << " | Metro Stages:\n"
        << " #1 => " << price.stage1 << " LE from 1 station to 9 stations\n"
        << " #2 => " << price.stage2 << " LE from 10 station to 16 stations\n"
        << " #3 => " << price.stage3 << " LE from 17 station to 23 stations\n"
        << " #4 => " << price.stage4 << " LE greater than 23 stations\n\n";
}


void price_list_sub() {
    cout << "\t----------------------\n"
        << "\t|    Purchase page     |\n"
        << "\t----------------------\n";


    cout << " | Here you all details about the subscriptions\n ---------------------------------------------\n";
    cout << "\n (Students)\n ----------\n\n | Student pay fixed amount of money every 3 monthsfor 180 trips for limited stations\n";
    cout << " | you have to pay\n"
        << "  " << price.student_stage1 << " LE for stage #1\n"
        << "  " << price.student_stage2 << " LE for stage #2\n"
        << "  " << price.student_stage3 << " LE for stage #3\n"
        << "  " << price.student_stage4 << " LE for stage #4\n\n";


    cout << " (Public Cards)\n ---------------\n\n | Person pays fixed amount of money every 1 monthfor 60 trips or every 1 year for 730 trips for limited stations\n";
    cout << " | For month payment you will pay\n"
        << "  " << price.publicMonth_stage1 << " LE for stage #1\n"
        << "  " << price.publicMonth_stage2 << " LE for stage #2\n"
        << "  " << price.publicMonth_stage3 << " LE for stage #3\n"
        << "  " << price.publicMonth_stage4 << " LE for stage #4\n\n";


    cout << " | For year payment you will pay\n"
        << "  " << price.publicYear_stage1 << " LE for stage #1\n"
        << "  " << price.publicYear_stage2 << " LE for stage #2\n"
        << "  " << price.publicYear_stage3 << " LE for stage #3\n"
        << "  " << price.publicYear_stage4 << " LE for stage #4\n\n";


    cout << " (Cash Wallet Cards)\n ------------------\n\n"
        << " | Person pay amount of money (Multiples of 10) any time\n"
        << " | Card limit can not exceed " << price.wallet_limit << " LE  X\n"
        << " | Card is not limited to a specific period\n"
        << " | Card charges individual tickets according to metro stages\n\n";
}


void Purchase_sub()
{
    price_list_stage();
    price_list_sub();
    char choice;
    cout << " [1] Continue\n"
        << " [2] User Menu\n\n"
        << " | Please enter your choice : ";
    cin >> choice;
    switch (choice)
    {
    case '1':
        choice_subs();
        break;
    case '2':
        system("cls");
        user_menu();
        break;
    default:
        system("cls");
        cout << "Please select from the options given \n";
    }


}


void choice_subs()
{
    char choice;
    cout << " [1] for students\n"
        << " [2] for public cards within a month\n"
        << " [3] for public cards within a year\n"
        << " [4] for Cash Wallet Cards\n"
        << "Please enter your choice : ";
    cin >> choice;


    switch (choice)
    {
    case '1':            // 1 for students 
        users[login_index].SUB.type = "students";
        char stage_std;
        cout << " | select which stage (1) or (2) or (3) or (4) : ";
        cin >> stage_std;


        switch (stage_std)
        {
        case '1':        // 1 for stage 1 for 33 LE.      
            if (users[login_index].balance < price.student_stage1)
            {
                system("cls");
                cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                user_menu();
                break;
            }
            users[login_index].balance -= price.student_stage1;
            users[login_index].SUB.rides = 180;
            users[login_index].SUB.END_date.month += 3;
            users[login_index].SUB.stage = 1;
            users[login_index].SUB.is_subscribed = true;
            users[login_index].SUB.available_stations = 9;
            system("cls");
            cout << "\n | you joined students subscription successfully \n";
            break;
        case '2':        // 2 for stage 2 for 41 LE.      
            if (users[login_index].balance < price.student_stage2)
            {
                system("cls");
                cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                user_menu();
                break;
            }
            users[login_index].balance -= price.student_stage2;
            users[login_index].SUB.rides = 180;
            users[login_index].SUB.END_date.month += 3;
            users[login_index].SUB.stage = 2;
            users[login_index].SUB.is_subscribed = true;
            users[login_index].SUB.available_stations = 16;
            system("cls");
            cout << "\n | you joined students subscription successfully \n";
            break;
        case '3':        // 3 for stage 1 for 50 LE.      
            if (users[login_index].balance < price.student_stage3)
            {
                system("cls");
                cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                user_menu();
                break;
            }
            users[login_index].balance -= price.student_stage3;
            users[login_index].SUB.rides = 180;
            users[login_index].SUB.END_date.month += 3;
            users[login_index].SUB.stage = 3;
            users[login_index].SUB.is_subscribed = true;
            users[login_index].SUB.available_stations = 23;
            system("cls");
            cout << "\n | you joined students subscription successfully \n";
            break;
        case '4':        // 4 for stage 4 for 65 LE.      
            if (users[login_index].balance < price.student_stage4)
            {
                system("cls");
                cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                user_menu();
                break;
            }
            users[login_index].balance -= price.student_stage4;
            users[login_index].SUB.rides = 180;
            users[login_index].SUB.END_date.month += 3;
            users[login_index].SUB.stage = 4;
            users[login_index].SUB.is_subscribed = true;
            users[login_index].SUB.available_stations = 35; // not effectiont but used as example to the 30 stations only in line 3 metro
            system("cls");
            cout << "\n | you joined students subscription successfully \n";
            break;


        default:
            cout << " | select only from choices please.\n";
            choice_subs();
            break;
        }


        break;


    case '2':
        users[login_index].SUB.type = "public for month";
        char stage_pub_month;
        cout << " select which stage (1) or (2) or (3) or (4) : ";
        cin >> stage_pub_month;
        switch (stage_pub_month)
        {
        case '1':  // 1 for stage 1 for 230 LE.     
            if (users[login_index].balance < price.publicMonth_stage1)
            {
                system("cls");
                cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                user_menu();
                break;
            }
            users[login_index].balance -= price.publicMonth_stage1;
            users[login_index].SUB.rides = 60;
            users[login_index].SUB.END_date.month += 1;
            users[login_index].SUB.stage = 1;
            users[login_index].SUB.is_subscribed = true;
            users[login_index].SUB.available_stations = 9;
            system("cls");
            cout << "\n | you joined public for month subscription successfully \n";
            break;
        case '2':  // 2 for stage 2 for 290 LE.     
            if (users[login_index].balance < price.publicMonth_stage2)
            {
                system("cls");
                cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                user_menu();
                break;
            }
            users[login_index].balance -= price.publicMonth_stage2;
            users[login_index].SUB.rides = 60;
            users[login_index].SUB.END_date.month += 1;
            users[login_index].SUB.stage = 2;
            users[login_index].SUB.is_subscribed = true;
            users[login_index].SUB.available_stations = 16;
            system("cls");
            cout << "\n | you joined public for month subscription successfully \n";
            break;
        case '3':  // 3 for stage 3 for 340 LE.     
            if (users[login_index].balance < price.publicMonth_stage3)
            {
                system("cls");
                cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                user_menu();
                break;
            }
            users[login_index].balance -= price.publicMonth_stage3;
            users[login_index].SUB.rides = 60;
            users[login_index].SUB.END_date.month += 1;
            users[login_index].SUB.stage = 3;
            users[login_index].SUB.is_subscribed = true;
            users[login_index].SUB.available_stations = 23;
            system("cls");
            cout << "\n | you joined public for month subscription successfully \n";
            break;
        case '4':  // 4 for stage 4 for 450 LE.     
            if (users[login_index].balance < price.publicMonth_stage4)
            {
                system("cls");
                cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                user_menu();
                break;
            }
            users[login_index].balance -= price.publicMonth_stage4;
            users[login_index].SUB.rides = 60;
            users[login_index].SUB.END_date.month += 1;
            users[login_index].SUB.stage = 4;
            users[login_index].SUB.is_subscribed = true;
            users[login_index].SUB.available_stations = 35;  // not effectiont but used as example to the 30 stations only in line 3 metro
            system("cls");
            cout << "\n | you joined public for month subscription successfully \n";
            break;
        default:
            cout << " | select from the choices only please";
            choice_subs();
        }
        break;


    case '3':
        users[login_index].SUB.type = "public for year";
        char stage_pub_year;
        cout << " | select which stage (1) or (2) or (3) or (4) : ";
        cin >> stage_pub_year;
        switch (stage_pub_year)
        {
        case '1':  // 1 for stage 1 for 1500 LE.     
            if (users[login_index].balance < price.publicYear_stage1)
            {
                system("cls");
                cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                user_menu();
                break;
            }
            users[login_index].balance -= price.publicYear_stage1;
            users[login_index].SUB.rides = 730;
            users[login_index].SUB.END_date.year += 1;
            users[login_index].SUB.stage = 1;
            users[login_index].SUB.is_subscribed = true;
            users[login_index].SUB.available_stations = 9;
            system("cls");
            cout << "\n | you joined public for year subscription successfully \n";
            break;
        case '2':  // 2 for stage 2 for 2500 LE.     
            if (users[login_index].balance < price.publicYear_stage2)
            {
                system("cls");
                cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                user_menu();
                break;
            }
            users[login_index].balance -= price.publicYear_stage2;
            users[login_index].SUB.rides = 730;
            users[login_index].SUB.END_date.year += 1;
            users[login_index].SUB.stage = 2;
            users[login_index].SUB.is_subscribed = true;
            users[login_index].SUB.available_stations = 16;
            system("cls");
            cout << "\n | you joined public for year subscription successfully \n";
            break;
        case '3':  // 3 for stage 3 for 3500 LE.     
            if (users[login_index].balance < price.publicYear_stage3)
            {
                system("cls");
                cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                user_menu();
                break;
            }
            users[login_index].balance -= price.publicYear_stage3;
            users[login_index].SUB.rides = 730;
            users[login_index].SUB.END_date.year += 1;
            users[login_index].SUB.stage = 3;
            users[login_index].SUB.is_subscribed = true;
            users[login_index].SUB.available_stations = 23;
            system("cls");
            cout << "\n | you joined public for year subscription successfully \n";
            break;
        case '4':  // 4 for stage 4 for 4500 LE.     
            if (users[login_index].balance < price.publicYear_stage4)
            {
                system("cls");
                cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                user_menu();
                break;
            }
            users[login_index].balance -= price.publicYear_stage4;
            users[login_index].SUB.rides = 730;
            users[login_index].SUB.END_date.year += 1;
            users[login_index].SUB.stage = 4;
            users[login_index].SUB.is_subscribed = true;
            users[login_index].SUB.available_stations = 35;
            system("cls");
            cout << "\n | you joined public for year subscription successfully \n";
            break;
        default:
            cout << " | select from the choices only please";
            choice_subs();
        }
        break;


    case '4':
        users[login_index].SUB.type = "Cash Wallet Cards";
        cout << " | Enter a balance money multiples of 10\n"
            << " | But not more than " << price.wallet_limit << " LE. : ";


        cin >> users[login_index].wallet_balance;
        if (users[login_index].wallet_balance % 10 == 0 && users[login_index].wallet_balance <= price.wallet_limit && users[login_index].wallet_balance <= users[login_index].balance)
        {
            system("cls");
            cout << "\nyou joined Cash Wallet Cards subscription successfully\n\n";
            users[login_index].SUB.is_subscribed = true;
            users[login_index].balance -= users[login_index].wallet_balance;
            user_menu();
            break;
        }
        else {
            cout << "\n | you did not follow the instructions !!\n | kindly try ";
            choice_subs();
        }
        break;
    default:
        cout << " | Select from these numbers only\n";
        choice_subs();
    }
}


void uptade_balance()
{
    cout << " | your current balance is : " << users[login_index].balance;
    float add_balance;
    cout << "\n | add your balance : ";
    cin >> add_balance;
    users[login_index].balance += add_balance;
    cout << " | balance added \n | your new balance is : " << users[login_index].balance << endl;
}


void show_inf()
{
    cout << " ======================\n"
        << "  Personal Information\n"
        << " ======================\n"
        << " | User name    : " << users[login_index].name << endl
        << " | User type    : " << users[login_index].type << endl
        << " | Phone number : " << users[login_index].phone << endl
        << " | Pasword      : " << users[login_index].password << endl
        << " | ID           : " << users[login_index].id << endl
        << " | Aubscription : " << users[login_index].SUB.type << endl
        << " | Available st. : " << users[login_index].SUB.available_stations << endl
        << " | Balance      : " << users[login_index].balance << endl;
    if (users[login_index].SUB.type == "Cash Wallet Cards") {
        cout << " | cash wallet balance : " << users[login_index].wallet_balance << endl << endl;
    }
    cout << " [1] Update Name\n"
        << " [2] Update Password\n"
        << " [3] Add Balance\n"
        << " [4] Change Phone Number\n"
        << " [5] User Menu\n\n"
        << "Please enter your choice : ";
    char slct;       cin >> slct;
    string name;


    switch (slct)
    {
    case '1':
        cout << " | Enter your name : ";
        cin.ignore(); // Clear input buffer
        getline(cin, name);
        users[login_index].name = name;
        system("cls");
        show_inf();
        break;
    case '2':
        cout << " | Updating your password : ";
        cin >> users[login_index].password;
        system("cls");
        show_inf();
        break;
    case '3':
        uptade_balance();
        system("cls");
        show_inf();
        break;
    case '4':
        cout << " | Changing your phone number : ";
        cin >> users[login_index].phone;
        system("cls");
        show_inf();
        break;
    case '5':
        system("cls");
        user_menu();
        break;
    default:
        system("cls");
        cout << " | Chose only from given numbers plz\n";
        show_inf();
        break;
    }
}


void mangeSUBS()
{
    if (!(users[login_index].SUB.is_subscribed)) {
        cout << " | you are not subscribed yet!!\n";
    }
    else
    {
        cout << " | subscription type : " << users[login_index].SUB.type << endl
            << " | start date         : " << users[login_index].SUB.START_date.year << " / "
            << users[login_index].SUB.START_date.month << " / "
            << users[login_index].SUB.START_date.day << endl
            << " | end date           : " << users[login_index].SUB.END_date.year << " / "
            << users[login_index].SUB.END_date.month << " / "
            << users[login_index].SUB.END_date.day << endl
            << " | Rest rides         : " << users[login_index].SUB.rides << endl << endl;
        cout << " [1] for renew your subscribtion\n"
            << " [2] for change your subscribtion plan\n"
            << " [3] to back to user menu\n"
            << " | please enter your chioce : ";
        char chice;
        cin >> chice;
        switch (chice)
        {
        case '1':


            if (users[login_index].SUB.type == "students") {
                if (users[login_index].SUB.stage = 1) {
                    if (users[login_index].balance < price.student_stage1)
                    {
                        system("cls");
                        cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                        user_menu();
                        break;
                    }
                    users[login_index].balance -= price.student_stage1;
                    users[login_index].SUB.rides = 180;
                    users[login_index].SUB.END_date.month += 3;
                    users[login_index].SUB.is_subscribed = true;
                    cout << "you have renewed your plan suSuccessfully\n";
                }
                else if (users[login_index].SUB.stage = 2) {
                    if (users[login_index].balance < price.student_stage2)
                    {
                        system("cls");
                        cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                        user_menu();
                        break;
                    }
                    users[login_index].balance -= price.student_stage2;
                    users[login_index].SUB.rides = 180;
                    users[login_index].SUB.END_date.month += 3;
                    users[login_index].SUB.is_subscribed = true;
                    cout << "you have renewed your plan suSuccessfully\n";
                }
                else if (users[login_index].SUB.stage = 3) {
                    if (users[login_index].balance < price.student_stage3)
                    {
                        system("cls");
                        cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                        user_menu();
                        break;
                    }
                    users[login_index].balance -= price.student_stage3;
                    users[login_index].SUB.rides = 180;
                    users[login_index].SUB.END_date.month += 3;
                    users[login_index].SUB.is_subscribed = true;
                    cout << "you have renewed your plan suSuccessfully\n";
                }
                else if (users[login_index].SUB.stage = 4) {
                    if (users[login_index].balance < price.student_stage4)
                    {
                        system("cls");
                        cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                        user_menu();
                        break;
                    }
                    users[login_index].balance -= price.student_stage4;
                    users[login_index].SUB.rides = 180;
                    users[login_index].SUB.END_date.month += 3;
                    users[login_index].SUB.is_subscribed = true;
                    cout << "you have renewed your plan suSuccessfully\n";
                }
            }// end student renew


            else if (users[login_index].SUB.type == "public for month") {
                if (users[login_index].SUB.stage = 1) {
                    if (users[login_index].balance < price.publicMonth_stage1)
                    {
                        system("cls");
                        cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                        user_menu();
                        break;
                    }
                    users[login_index].balance -= price.publicMonth_stage1;
                    users[login_index].SUB.rides = 60;
                    users[login_index].SUB.END_date.month += 1;
                    users[login_index].SUB.is_subscribed = true;
                    cout << "you have renewed your plan suSuccessfully\n";
                }
                else if (users[login_index].SUB.stage = 2) {
                    if (users[login_index].balance < price.publicMonth_stage2)
                    {
                        system("cls");
                        cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                        user_menu();
                        break;
                    }
                    users[login_index].balance -= price.publicMonth_stage2;
                    users[login_index].SUB.rides = 60;
                    users[login_index].SUB.END_date.month += 1;
                    users[login_index].SUB.is_subscribed = true;
                    cout << "you have renewed your plan suSuccessfully\n";
                }
                else if (users[login_index].SUB.stage = 3) {
                    if (users[login_index].balance < price.publicMonth_stage3)
                    {
                        system("cls");
                        cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                        user_menu();
                        break;
                    }
                    users[login_index].balance -= price.publicMonth_stage3;
                    users[login_index].SUB.rides = 60;
                    users[login_index].SUB.END_date.month += 1;
                    users[login_index].SUB.is_subscribed = true;
                    cout << "you have renewed your plan suSuccessfully\n";
                }
                else if (users[login_index].SUB.stage = 4) {
                    if (users[login_index].balance < price.publicMonth_stage4)
                    {
                        system("cls");
                        cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                        user_menu();
                        break;
                    }
                    users[login_index].balance -= price.publicMonth_stage4;
                    users[login_index].SUB.rides = 60;
                    users[login_index].SUB.END_date.month += 1;
                    users[login_index].SUB.is_subscribed = true;
                    cout << "you have renewed your plan suSuccessfully\n";
                }
            }// end public month renew


            else if (users[login_index].SUB.type == "public for year") {
                if (users[login_index].SUB.stage = 1) {
                    if (users[login_index].balance < price.publicYear_stage1)
                    {
                        system("cls");
                        cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                        user_menu();
                        break;
                    }
                    users[login_index].balance -= price.publicYear_stage1;
                    users[login_index].SUB.rides = 60;
                    users[login_index].SUB.END_date.month += 1;
                    users[login_index].SUB.is_subscribed = true;
                    cout << "you have renewed your plan suSuccessfully\n";
                }
                else if (users[login_index].SUB.stage = 2) {
                    if (users[login_index].balance < price.publicYear_stage2)
                    {
                        system("cls");
                        cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                        user_menu();
                        break;
                    }
                    users[login_index].balance -= price.publicYear_stage2;
                    users[login_index].SUB.rides = 60;
                    users[login_index].SUB.END_date.month += 1;
                    users[login_index].SUB.is_subscribed = true;
                    cout << "you have renewed your plan suSuccessfully\n";
                }
                else if (users[login_index].SUB.stage = 3) {
                    if (users[login_index].balance < price.publicYear_stage3)
                    {
                        system("cls");
                        cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                        user_menu();
                        break;
                    }
                    users[login_index].balance -= price.publicYear_stage3;
                    users[login_index].SUB.rides = 60;
                    users[login_index].SUB.END_date.month += 1;
                    users[login_index].SUB.is_subscribed = true;
                    cout << "you have renewed your plan suSuccessfully\n";
                }
                else if (users[login_index].SUB.stage = 4) {
                    if (users[login_index].balance < price.publicYear_stage4)
                    {
                        system("cls");
                        cout << " | NOT ENOUGH BALANCE\n | recharge your wallet first please\n";
                        user_menu();
                        break;
                    }
                    users[login_index].balance -= price.publicYear_stage4;
                    users[login_index].SUB.rides = 60;
                    users[login_index].SUB.END_date.month += 1;
                    users[login_index].SUB.is_subscribed = true;
                    cout << "you have renewed your plan suSuccessfully\n";
                }
            }// end public year renew
            break;
        case '2':
            Purchase_sub();
            break;
        case '3':
            user_menu();
            break;
        default:
            cout << " | please select only from given values\n";
            mangeSUBS();
            break;
        }// end switch


    }// end else
}// end function


void view_station() {
    for (int i = 0; i < 3; i++) {
        cout << " | the GREEN LINE " << i + 1 << " METRO stations\n\n";


        for (int j = 0; j < 100; j++) {
            if (stations[i][j] == "")
                continue;
            if (j % 4 == 0 && j != 0)
                cout << endl;
            if (j < 9)
                cout << "(" << j + 1 << " ) " << stations[i][j] << " --> ";
            else
                cout << "(" << j + 1 << ") " << stations[i][j] << " --> ";
        }
        cout << endl << endl;
    }cout << endl;
    int start, end, entryline, outline;
    cout << " | choose which line you will start from (1,2,3) : "; cin >> entryline;
    cout << " | Enter the index of starting station : "; cin >> start;
    cout << " | choose which line you will End at (1,2,3) : "; cin >> outline;
    cout << " | Enter the index of end station      : "; cin >> end;




    make_ride(entryline, --start, outline, --end);
}


void make_ride(int entryline, int start, int outline, int end) {
    int diffStations = 0;
    // from 1 to 2
    if (entryline == 1 && outline == 2) {
        cout << "\n\n ||  you are in the 1 to 2 line\n\n";
        diffStations = abs((end)-shohadaa_index_in_line2) + abs(shohadaa_index_in_line1 - (start)); //calc diffrence stations to apply statges
        if (users[login_index].SUB.type == "Cash Wallet Cards") {
            if (diffStations <= 9)
                users[login_index].wallet_balance -= price.stage1;
            else if (diffStations <= 16)
                users[login_index].wallet_balance -= price.stage2;
            else if (diffStations <= 23)
                users[login_index].wallet_balance -= price.stage3;
            else if (diffStations > 23)
                users[login_index].wallet_balance -= price.stage4;
        }


        else if (users[login_index].SUB.type == "null") { // cheking if the user is subscibed or not
            cout << "Do a subscrition first\n";
            system("pause");
            system("cls");
            user_menu();
        }
        else if (users[login_index].SUB.available_stations < diffStations) {
            system("cls");
            cout << "your stage does not fit this ride !!\n try again\n";// cheking for the stage and avalible stations
            view_station();
        }
        printing_stations(shohadaa_index_in_line1, shohadaa_index_in_line2, start, end, entryline, outline, diffStations);
    }
    // from 2 to 1
    else if (entryline == 2 && outline == 1) {
        diffStations = abs((start)-shohadaa_index_in_line2) + abs(shohadaa_index_in_line1 - (end));
        if (users[login_index].SUB.type == "Cash Wallet Cards") {
            if (diffStations <= 9)
                users[login_index].wallet_balance -= price.stage1;
            else if (diffStations <= 16)
                users[login_index].wallet_balance -= price.stage2;
            else if (diffStations <= 23)
                users[login_index].wallet_balance -= price.stage3;
            else if (diffStations > 23)
                users[login_index].wallet_balance -= price.stage4;
        }


        else if (users[login_index].SUB.type == "null") {
            cout << "Do a subscrition first\n";
            system("pause");
            system("cls");
            user_menu();
        }
        else if (users[login_index].SUB.available_stations < diffStations) {
            system("cls");
            cout << "your stage does not fit this ride !!\n try again\n";
            view_station();
        }
        printing_stations(shohadaa_index_in_line2, shohadaa_index_in_line1, start, end, entryline, outline, diffStations);
    }
    // from 1 to 3
    else if (entryline == 1 && outline == 3) {
        diffStations = abs((end)-nasser_index_in_line3) + abs(nasser_index_in_line1 - (start));
        if (users[login_index].SUB.type == "Cash Wallet Cards") {
            if (diffStations <= 9)
                users[login_index].wallet_balance -= price.stage1;
            else if (diffStations <= 16)
                users[login_index].wallet_balance -= price.stage2;
            else if (diffStations <= 23)
                users[login_index].wallet_balance -= price.stage3;
            else if (diffStations > 23)
                users[login_index].wallet_balance -= price.stage4;
        }


        else if (users[login_index].SUB.type == "null") {
            cout << "Do a subscrition first\n";
            system("pause");
            system("cls");
            user_menu();
        }
        else if (users[login_index].SUB.available_stations < diffStations) {
            system("cls");
            cout << "your stage does not fit this ride !!\n try again\n";
            view_station();
        }
        printing_stations(nasser_index_in_line1, nasser_index_in_line3, start, end, entryline, outline, diffStations);
    }
    //from 3 to 1
    else if (entryline == 3 && outline == 1) {
        diffStations = abs((start)-nasser_index_in_line3) + abs(nasser_index_in_line1 - (end));
        if (users[login_index].SUB.type == "Cash Wallet Cards") {
            if (diffStations <= 9)
                users[login_index].wallet_balance -= price.stage1;
            else if (diffStations <= 16)
                users[login_index].wallet_balance -= price.stage2;
            else if (diffStations <= 23)
                users[login_index].wallet_balance -= price.stage3;
            else if (diffStations > 23)
                users[login_index].wallet_balance -= price.stage4;
        }
        else if (users[login_index].SUB.type == "null") {
            cout << "Do a subscrition first\n";
            system("pause");
            system("cls");
            user_menu();
        }
        else if (users[login_index].SUB.available_stations < diffStations) {
            system("cls");
            cout << "your stage does not fit this ride !!\n try again\n";
            view_station();
        }
        printing_stations(nasser_index_in_line3, nasser_index_in_line1, start, end, entryline, outline, diffStations);
    }
    // from 2 to 3
    else if (entryline == 2 && outline == 3) {
        diffStations = abs((end)-attaba_index_in_line3) + abs(attaba_index_in_line2 - (start));
        if (users[login_index].SUB.type == "Cash Wallet Cards") {
            if (diffStations <= 9)
                users[login_index].wallet_balance -= price.stage1;
            else if (diffStations <= 16)
                users[login_index].wallet_balance -= price.stage2;
            else if (diffStations <= 23)
                users[login_index].wallet_balance -= price.stage3;
            else if (diffStations > 23)
                users[login_index].wallet_balance -= price.stage4;
        }
        else  if (users[login_index].SUB.type == "null") {
            cout << "Do a subscrition first\n";
            system("pause");
            system("cls");
            user_menu();
        }
        else if (users[login_index].SUB.available_stations < diffStations) {
            system("cls");
            cout << "your stage does not fit this ride !!\n try again\n";
            view_station();
        }
        printing_stations(attaba_index_in_line2, attaba_index_in_line3, start, end, entryline, outline, diffStations);
    }
    // from 3 to 2
    else if (entryline == 3 && outline == 2) {
        diffStations = abs((start)-attaba_index_in_line3) + abs(attaba_index_in_line2 - (end));
        if (users[login_index].SUB.type == "Cash Wallet Cards") {
            if (diffStations <= 9)
                users[login_index].wallet_balance -= price.stage1;
            else if (diffStations <= 16)
                users[login_index].wallet_balance -= price.stage2;
            else if (diffStations <= 23)
                users[login_index].wallet_balance -= price.stage3;
            else if (diffStations > 23)
                users[login_index].wallet_balance -= price.stage4;
        }
        else if (users[login_index].SUB.type == "null") {
            cout << "Do a subscrition first\n";
            system("pause");
            system("cls");
            user_menu();
        }
        else if (users[login_index].SUB.available_stations < diffStations) {
            system("cls");
            cout << "your stage does not fit this ride !!\n try again\n";
            view_station();
        }
        printing_stations(attaba_index_in_line3, attaba_index_in_line2, start, end, entryline, outline, diffStations);
    }
    else if (entryline == outline) {


        if (start < end) { // adly mansour direction
            diffStations = end - start;
            cout << "ready for the trip ?\n====================\n\n";
            for (int i = 0; i < diffStations + 1; i++) {
                cout << stations[entryline - 1][start + i] << "  ";
                this_thread::sleep_for(chrono::seconds(1));
            }
            cout << endl;
            users[login_index].SUB.rides -= 2;
            cout << " | you have reached your destination > " << stations[entryline - 1][end] << endl;
            save_rides_history(start, end, --entryline, --outline); // saving the data of this ride
        }
        else if (start > end) { // rod el farag direction
            cout << "\n\n | Ready for the trip ?\n====================\n\n";
            diffStations = start - end;
            int j = 0;


            do {
                cout << stations[entryline - 1][start - j] << "  ";
                this_thread::sleep_for(chrono::seconds(1));
                j++;
            } while (j < diffStations + 1);


            cout << endl;
            users[login_index].SUB.rides -= 2;
            cout << " | you have reached your destination -->" << stations[entryline - 1][end] << endl;
            save_rides_history(start, end, --entryline, --outline); // saving the data of this ride
        }
        else { // If start and end stations are the same
            system("cls");
            cout << " | You are already at your destination." << endl;
            user_menu();
        }


    }
}


int historyINDEX = 0;
void save_rides_history(int startstation, int endstation, int entryline, int outline) {
    HISTORY[historyINDEX].start_station = stations[entryline][startstation];
    HISTORY[historyINDEX].end_station = stations[outline][endstation];
    HISTORY[historyINDEX].userName = users[login_index].name;
    HISTORY[historyINDEX].userId = users[login_index].id;
    HISTORY[historyINDEX].subscriptionType = users[login_index].SUB.type;
    HISTORY[historyINDEX].DOP.day = currentDay;
    HISTORY[historyINDEX].DOP.month = currentmonth;
    HISTORY[historyINDEX].DOP.year = currentyear;
    historyINDEX++;
}


void view_rides_history_forUSER() {
    cout << "\t\t\t========================================\n"
        << "\t\t\t  rides history for user : " << users[login_index].name << endl
        << "\t\t\t==========================================\n\n";
    int counterrides = 1;
    cout << "     user name\t\tuser id\t    enter station\t    out station\t\tdate\n";
    for (int i = 0; i < historyINDEX + 1; i++) {


        if (HISTORY[i].userId == users[login_index].id) {


            cout << "(" << counterrides << ")"
                << HISTORY[i].userName << "      \t"
                << HISTORY[i].userId << "\t"
                << HISTORY[i].start_station << "\t"
                << HISTORY[i].end_station << "   \t  "
                << HISTORY[i].DOP.year << "/"
                << HISTORY[i].DOP.month << "/"
                << HISTORY[i].DOP.day << endl << endl;
            counterrides++;
        }
    }
}


void printing_stations(int common_station_index_in_entry_line, int common_station_index_in_out_line, int start, int end, int entryline, int outline, int diffStations) {
    if (start < common_station_index_in_entry_line) {
        cout << "ready for the trip ?\n====================\n";
        int j = 0;
        for (int i = 0; i < diffStations + 2; i++) {
            if ((i + start) <= common_station_index_in_entry_line) {
                cout << stations[entryline - 1][start + i] << "  ";
                this_thread::sleep_for(chrono::seconds(1));
                if ((i + start) == common_station_index_in_entry_line) {
                    cout << "\n\n | SHIFTING LINES...Please go to the other platform\n\n";
                    this_thread::sleep_for(chrono::seconds(3));
                } // (↑) print shifting lines 
            }//   (↑) printing the stations untill common station in entry line
            if ((i + start) > common_station_index_in_entry_line) {
                if (end > common_station_index_in_out_line) {
                    cout << stations[outline - 1][common_station_index_in_out_line + j];
                    this_thread::sleep_for(chrono::seconds(1));
                    j++;
                }
                else if (end < common_station_index_in_out_line) {
                    cout << stations[outline - 1][common_station_index_in_out_line - j];
                    this_thread::sleep_for(chrono::seconds(1));
                    j++;
                }
            }//   (↑) printing the stations from shohadaa untill end station
        }
        cout << endl;
        users[login_index].SUB.rides -= 2;
        cout << "\n | you have reached your destination --> " << stations[outline - 1][end] << endl;
        save_rides_history(start, end, --entryline, --outline); // saving the data of this ride
    }
    else if (start > common_station_index_in_entry_line) {
        cout << "ready for the trip ?\n====================\n";
        int j = 0;
        for (int i = 0; i < diffStations + 2; i++) {
            if ((-i + start) >= common_station_index_in_entry_line) {
                cout << stations[entryline - 1][start - i] << "  ";
                this_thread::sleep_for(chrono::seconds(1));
                if ((-i + start) == common_station_index_in_entry_line) {
                    cout << "\n\n | SHIFTING LINES...Please go to the other platform\n\n";
                    this_thread::sleep_for(chrono::seconds(3));
                } // (↑) print shifting lines 
            }
            else if ((-i + start) <= common_station_index_in_entry_line) {
                cout << stations[outline - 1][common_station_index_in_out_line + j];
                this_thread::sleep_for(chrono::seconds(1));
                j++;
            }//   (↑) printing the stations from shohadaa untill end station
        }
        cout << endl;
        users[login_index].SUB.rides -= 2;
        cout << "\n | you have reached your destination --> " << stations[outline - 1][end] << endl;
        save_rides_history(start, end, --entryline, --outline); // saving the data of this ride
    }




}
/////////////////////////////////////////////////////////////////admin//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////admin//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////admin//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////admin//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////admin//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////admin//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////admin//////////////////////////////////////////////////////////////////////////////


void admin_menu() {
    char choice;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t------------------------------\n"
        << "\t\t\t\t\t\t\t\t\t\t\t\t          admin menu\n"
        << "\t\t\t\t\t\t\t\t\t\t\t\t-------------------------------\n";


    cout << "  [1] Main Menu\n"
        << "  [2] User Management\n"
        << "  [3] Subscription Plan Management\n"
        << "  [4] View All Ride Logs\n"
        << "  [5] Station Management\n"
        << "  [6] Fare Management\n\n"
        << "  | please enter your choice : ";
    cin >> choice;
    switch (choice)
    {
    case '1':
        system("cls");
        main_menu();
        break;
    case '2':
        system("cls");
        user_management();
        admin_menu();
        break;
    case '3':
        system("cls");
        subscription_plan_management();
        admin_menu();
        break;
    case '4':
        system("cls");
        view_rides_history_forADMIN();
        admin_menu();
        break;
    case '5':
        system("cls");
        station_management();
        admin_menu();
        break;
    case '6':
        system("cls");
        fare_management();
        admin_menu();
        break;
    default:
        system("cls");
        cout << " | Please select from the options given\n";
        admin_menu();
        break;
    }
}


void user_management() {


    for (int j = 0; j < index; j++)
    {
        if (users[j].type == 'c' || users[j].type == 'C')
        {
            cout << " ======================\n"
                << "  personal information for user " << j + 1 << endl
                << " ======================\n"
                << " | User name     : " << users[j].name << endl
                << " | Phone number  : " << users[j].phone << endl
                << " | Password      : " << users[j].password << endl
                << " | ID            : " << users[j].id << endl
                << " | Subscription  : " << users[j].SUB.type << endl
                << " | Available st. : " << users[j].SUB.available_stations << endl
                << " | Balance       : " << users[j].balance << endl << endl;
        }
        else
            continue;
    }
    cout << "  [1] Continue to make Updates\n"
        << "  [2] Admin Menu\n\n"
        << "  | Please enter your choice : ";
    char choice;    cin >> choice;
    switch (choice)
    {
    case '1':
        admin_user_manag();
        break;
    case '2':
        system("cls");
        admin_menu();
        break;
    default:
        system("cls");
        cout << "Please select from the options given \n";
        user_management();
        break;
    }
}


void admin_user_manag() {
    cout << "  [1] Edit\n"
        << "  [2] Delete\n\n"
        << "  | Please enter your choice : ";
    char choice;    cin >> choice;
    switch (choice)
    {
    case '1':
        cout << "  [1] Edit user name\n"
            << "  [2] Edit password\n"
            << "  [3] Edit phone number\n"
            << "  [4] Edit balance\n"
            << "  | Please enter your choice : ";
        char slct;    cin >> slct;
        cout << "Choose a specific user : ";
        int num1;   cin >> num1;
        switch (slct)
        {
        case '1':
            cout << " | Enter the new name : ";
            cin.ignore();
            getline(cin, users[num1 - 1].name);
            system("cls");
            user_management();
            break;
        case '2':
            cout << " | Enter the new password : ";
            cin >> users[num1 - 1].password;
            system("cls");
            user_management();
            break;
        case '3':
            cout << " | Enter the phone number : ";
            cin >> users[num1 - 1].phone;
            system("cls");
            user_management();
            break;
        case '4':
            float add_balance;
            cout << " | Enter the new balance : ";
            cin >> add_balance;
            users[num1 - 1].balance = add_balance;
            system("cls");
            user_management();
            break;
        default:
            system("cls");
            cout << " | Chose only from given numbers plz\n";
            admin_user_manag();
            break;
        }
        break;
    case '2':
        cout << "Which user you want to delete : ";
        cin >> num1;
        users[num1 - 1].SUB.type = "null";
        users[num1 - 1].type = 'q';
        system("cls");
        user_management();
        break;
    default:
        system("cls");
        cout << "Please select from the options given \n";
        admin_user_manag();
        break;
    }
}


void subscription_plan_management() {
    price_list_stage();
    price_list_sub();
    cout << " [1] Continue to make Updates\n"
        << " [2] Admin Menu\n\n"
        << "Please enter your choice : ";
    char choice;    cin >> choice;
    switch (choice)
    {
    case '1':
        system("cls");
        admin_sub_manag();
        break;
    case '2':
        system("cls");
        admin_menu();
        break;
    default:
        system("cls");
        cout << "Please select from the options given \n";
        subscription_plan_management();
    }
}


void admin_sub_manag() {
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t------------------------------\n"
        << "\t\t\t\t\t\t\t\t\t\t\t\t          Uptading Page \n"
        << "\t\t\t\t\t\t\t\t\t\t\t\t-------------------------------\n";
    cout << "  [1] Update prices of Metro Stages\n"
        << "  [2] Update prices of Student Subscription\n"
        << "  [3] Update prices of Public Within month Subscription\n"
        << "  [4] Update prices of Public Within year Subscription\n"
        << "  [5] Update prices of Wallet Subscription\n\n"
        << "  | Please enter your choice : ";
    char choice;    cin >> choice;
    switch (choice)
    {
    case '1':
        cout << " Updating stage #1 price : "; cin >> price.stage1;
        cout << " Updating stage #2 price : "; cin >> price.stage2;
        cout << " Updating stage #3 price : "; cin >> price.stage3;
        cout << " Updating stage #4 price : "; cin >> price.stage4;
        subscription_plan_management();
        break;
    case '2':
        cout << " Updating students stage #1 price : "; cin >> price.student_stage1;
        cout << " Updating students stage #2 price : "; cin >> price.student_stage2;
        cout << " Updating students stage #3 price : "; cin >> price.student_stage3;
        cout << " Updating students stage #4 price : "; cin >> price.student_stage4;
        subscription_plan_management();
        break;
    case '3':
        cout << " Updating public stage Within month stage #1 price : "; cin >> price.publicMonth_stage1;
        cout << " Updating public stage Within month stage #2 price : "; cin >> price.publicMonth_stage2;
        cout << " Updating public stage Within month stage #3 price : "; cin >> price.publicMonth_stage3;
        cout << " Updating public stage Within month stage #4 price : "; cin >> price.publicMonth_stage4;
        subscription_plan_management();
        break;
    case '4':
        cout << " Updating public stage Within year stage #1 price : "; cin >> price.publicYear_stage1;
        cout << " Updating public stage Within year stage #2 price : "; cin >> price.publicYear_stage2;
        cout << " Updating public stage Within year stage #3 price : "; cin >> price.publicYear_stage3;
        cout << " Updating public stage Within year stage #4 price : "; cin >> price.publicYear_stage4;
        subscription_plan_management();
        break;
    case '5':
        cout << " Updating wallet price limit : "; cin >> price.wallet_limit;
        subscription_plan_management();
        break;
    default:
        system("cls");
        cout << " Enter only from above choices\n";
        admin_sub_manag();
        break;
    }


}


void station_management() {
    showStation();
    cout << "\n\n | [1] Add new staion\n"
        << " | [2] Remove a station\n"
        << " | [3] Edit a staion\n"
        << " | [4] Admin menu\n\n"
        << " | Please enter your choice : ";
    char choice;    cin >> choice;
    string new_st_name;
    string edited_st_name;
    int lineNumber;
    switch (choice)
    {
    case '1':
        cout << "Enter line number : ";
        cin >> lineNumber;
        cout << "Enter the new station name : ";
        cin >> new_st_name;
        add_station(new_st_name, lineNumber - 1);
        station_management();
        break;
    case '2':
        cout << "Enter line number : ";
        cin >> lineNumber;
        cout << "Enter id of staion you want to remove : ";
        int removed_st_id;
        cin >> removed_st_id;
        removeStation(removed_st_id, lineNumber - 1);
        station_management();
        break;
    case '3':
        cout << "Enter line number : ";
        cin >> lineNumber;
        int edited_st_id;
        cout << "Enter the id of station : ";   cin >> edited_st_id;
        cout << "Enter the new name of station : ";   cin >> edited_st_name;
        editStation(edited_st_id - 1, edited_st_name, lineNumber - 1);
        station_management();
        break;
    case'4':
        admin_menu();
        break;
    default:
        cout << " Enter only from above choices\n";
        station_management();
        break;
    }
}


void fare_management() {
    price_list_stage();
    cout << "[1] Continue\n"
        << "[2] Admin Menu\n\n"
        << " Please enter your choice : ";
    char choice;    cin >> choice;
    switch (choice)
    {
    case '1':
        cout << " Updating stage #1 price : "; cin >> price.stage1;
        cout << " Updating stage #2 price : "; cin >> price.stage2;
        cout << " Updating stage #3 price : "; cin >> price.stage3;
        cout << " Updating stage #4 price : "; cin >> price.stage4;
        system("cls");
        fare_management();
        break;
    default:
        cout << "Please enter from the choices given";
        break;
    }
}


void view_rides_history_forADMIN()
{
    for (int j = 0; j < index; j++)
    {
        if (users[j].type == 'c' || users[j].type == 'C')
        {


            cout << "\t\t\t========================================\n"
                << "\t\t\t  rides history for user :" << users[j].name << endl
                << "\t\t\t==========================================\n\n";
            int counterrides = 1;
            cout << "     user name\t\tuser id\t    enter station\t    out station\t\tdate\n";
            for (int i = 0; i < historyINDEX + 1; i++) {


                if (HISTORY[i].userId == users[j].id) {


                    cout << "(" << counterrides << ")"
                        << HISTORY[i].userName << "      \t"
                        << HISTORY[i].userId << "\t"
                        << HISTORY[i].start_station << "\t"
                        << HISTORY[i].end_station << "   \t  "
                        << HISTORY[i].DOP.year << "/"
                        << HISTORY[i].DOP.month << "/"
                        << HISTORY[i].DOP.day << endl << endl;
                    counterrides++;
                }
            }
        }
        else
            continue;
    }
}




void showStation() {
    int lineNumber;
    for (lineNumber = 0; lineNumber < 3; lineNumber++) {
        for (int i = 0; i < station_num[lineNumber]; i++) {
            cout << "Station name: " << stations[lineNumber][i] << "Station id: " << i + 1 << "\n";
        }
    }
}


void add_station(string new_st_name, int lineNumber) {
    if (station_num[lineNumber] < 100) {
        stations[lineNumber][station_num[lineNumber]] = "    " + new_st_name + "     ";
        station_num[lineNumber]++;
    }
    else {
        cout << "Invalid! Total number of stations exceeded. Please add or remove stations first" << endl;
    }
}


void removeStation(int removed_st_id, int lineNumber) {
    if (station_num[lineNumber] <= 0) {
        cout << "Invalid! There are no stations to remove. Please add stations first " << endl;
    }
    else {


        for (int i = removed_st_id - 1; i <= station_num[lineNumber]; i++) {
            stations[lineNumber][i] = stations[lineNumber][i + 1];
        }
        station_num[lineNumber]--;
    }
}


void editStation(int edited_st_id, string edited_st_name, int lineNumber) {
    if (station_num[lineNumber] <= 0) {
        cout << "Invalid! There are no stations to edit. Please add stations first " << endl;


    }
    else {
        stations[lineNumber][edited_st_id] = "    " + edited_st_name + "     ";
    }
}


// yousef karam last edited in  1 / 5 / 2024