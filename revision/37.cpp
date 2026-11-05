#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Database {
private:
    string dbName;
    int connectionID;

public: // FIX 1: Put BOTH constructors under 'public:'!
    Database() : dbName("LocalDB"), connectionID(0) {
        cout << "Connected to Default DB\n";
    }

    // FIX 2: Use initializer list ': dbName(name), connectionID(id)'!
    Database(string name, int id) : dbName(name), connectionID(id) {
        cout << "Connected to " << dbName << '\n';
    }

    void closeConnection(); // Declared inside the class (like revision/28.cpp)
};

// FIX 3: Use 'Database::' to tell C++ this function belongs to class Database!
void Database::closeConnection() {
    connectionID = -1;
    cout << "Connection manually closed.\n";
}

int main() {
  Database myDB;

  Database serverDB("CloudSDB", 404);

  myDB.closeConnection();
  return 0;
}
