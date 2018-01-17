#include <iostream>
using namespace std;

class person{
public:
  string address;
  string name; 
};

class addressbook{
  person friends[100];
  int numberOfFriends;
  
  
public:
  addressbook();
  void listFriends();
  void addFriend(string n);
  void addFriend(string n,string a);
  person find(string query);
};

// constructor
addressbook::addressbook(){
  numberOfFriends = 0;  
}

void addressbook::addFriend(string n){
  friends[numberOfFriends].name = n;
  numberOfFriends++;
}
void addressbook::addFriend(string n,string a){
  friends[numberOfFriends].name = n;
  friends[numberOfFriends].address = a;
  numberOfFriends++;
}

void addressbook::listFriends(){
  for(int i = 0; i < numberOfFriends; i++){
    cout << friends[i].name << ":" << friends[i].address << "\n";
  }      
}

person addressbook::find(string query){
  person no_one;
  for(int i = 0; i < numberOfFriends; i++){
    if(friends[i].name == query)
      no_one=friends[i];
  }
  return no_one;
}

int main()
{
  addressbook abook;
  string name;
    string address;

  while(1){
    cout << "住所録に登録する名前と住所を入力してください（終了するにはquitと入力してください）: ";
    cin >> name;
    if(name == "quit" ){break;}
    cin >> address;
    //   cout << "name.length() = " << name.length() << "\n";
    if(address=="quit"){break;}
    abook.addFriend(name,address);
  }

  cout << "\n名前:住所\n";
  abook.listFriends();
  
  string query;
      cout << "住所検索を行います。名前を入力してください: ";
  cin >> query;
  cout << abook.find(query).address << "\n";
}
