/* inheritance.cpp */
#include <iostream>
#include "stdio.h"
using namespace std;


class person{
public:
 string name;
};

class ticket{
public:
 int id;
 person* user;
 ticket(){user = new person;}
};

class transTicket : public ticket{
public:
 string origin;
 string destination;
 transTicket(): ticket(){};
};

class hm{
public:
  int hour;
  int minute;
  hm(){hour=0;minute=0;}
};


//transticketを引き継いだtrainticket
class trainTicket : public transTicket{
public:
  string traname;
  hm departureTime; //出発時刻
  hm arrivalTime;  //到着時刻
  trainTicket(): transTicket(){};
};


int main()
{
 int ticketNum;
 int hour;
 int minute;
 cout << "チケットを何枚購入しますか？ ";
 cin >> ticketNum;
 cout << "\n";
 trainTicket* tickets = new trainTicket [ticketNum];
 for(int i = 0; i < ticketNum; i++){
    tickets[i].id = i+1;
    cout << i+1 << "人目の利用者の名前を入力してください: ";
    cin >> tickets[i].user->name;
    cout << "何車両目か入力してください";
    cin >> tickets[i].traname; 
    cout << " 出発地を入力してください: ";
    cin >> tickets[i].origin;
    cout << " 到着地を入力してください: ";
    cin >> tickets[i].destination;

    //main関数内で出発地と到着時刻
    cout << " 出発時刻を入力してください(例15:30): ";
    scanf("%d:%d", &tickets[i].departureTime.hour, &tickets[i].departureTime.minute);
    cout << " 到着時刻を入力してください(例15:30): ";
    scanf("%d:%d", &tickets[i].arrivalTime.hour, &tickets[i].arrivalTime.minute);
 }
 
 cout << "\n チケット利用者一覧：\n";
 for(int i = 0; i < ticketNum; i++){
    trainTicket t = tickets[i];
    cout << "チケット購入枚数 " << t.id << "\n" << "利用者名 : " << t.user->name << "\n" << " 車両: " << t.traname << "\n" << t.origin << "=>" << t.destination << ":"<< "【" << t.departureTime.hour << ":" << t.departureTime.minute << " 】" << "=>" << "【" << t.arrivalTime.hour << ":" << t.arrivalTime.minute << " 】"<< "\n";
 }
  cout << "\n";

}
