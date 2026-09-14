#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FileHandler {
private:
  File *myFile;

public:
  FileHandler() {
    myFile = fopen("data.txt", "r"); // opened a file got a resource
  }

  ~FileHandler() {
    if (myFile != nullptr) {
      fclose(myFile); // Closed the file before dying (cleanup)
    }
  }
};
