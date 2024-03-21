 #include <iostream>
 using namespace std;

 void f(double& p)
 {
   p += 2;
 }

 int main()
 {
   double x = 1;
   double y = 1;
 
   f(x);
   f(y);

   cout << "x is " << x;
   cout << " y is " << y << endl;

   return 0;
 }