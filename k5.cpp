/* inheritance.cpp */
#include <iostream>
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

//transticketを引き継いだtrainticket
class trainTicket : public transTicket{
public:
 string traname;
 trainTicket(): transTicket(){};
};


int main()
{
 int ticketNum;
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
 }
 cout << "\n チケット利用者一覧：\n";
 for(int i = 0; i < ticketNum; i++){
 trainTicket t = tickets[i];
 cout << " " << t.id << " : " << t.traname << ":" << t.user->name << " : " << t.origin << "=>" << t.destination << "\n";
 }
 cout << "\n";
}
