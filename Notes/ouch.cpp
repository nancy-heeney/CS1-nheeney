#include <iostream>
  #include <fstream>
  using namespace std;
  
  int main()
  {

    ofstream output("scores.txt");

    output << "John" << " " << "T" << " " << "Smith"
      << " " << 90 << endl;
    output << "Eric" << " " << "K" << " " << "Jones"
      << " " << 85;
  
    output.close();
  
    ifstream input;

    input.open("scores.txt");
  
 
    char firstName[80];
    char mi;
    char lastName[80];
    int score;
    input >> firstName >> mi >> lastName >> score;
    double sum = score;
  
    input >> firstName >> mi >> lastName >> score;
    sum += score;
  
    cout << "Total score is " << sum << endl;
  
    input.close();
  
    return 0;
  }