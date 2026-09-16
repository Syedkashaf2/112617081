#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Database {
  string dbName;
  int connectionID;

  Database() : dbName("LocalDB"), connectionID(0) {
    cout << "Connected to Default DB\n";
  }

public:
  Database(string name, int id) {
    name = name;
    connectionID = id;
    cout << "Connected to " << dbName << '\n';
  }
};

void closeConnection() {
  connectionID = -1;
  cout << "Connection manually closed.\n";
}

int main() {
  Database myDB;

  Database serverDB("CloudSDB", 404);

  myDB.closeConnection();
  return 0;
}
