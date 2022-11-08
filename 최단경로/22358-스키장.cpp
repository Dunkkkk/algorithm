//#include <iostream>
//#include <queue>
//#include <vector>
//
//
//using namespace std;
//int dist[500001];
//vector<int> ski[500001];
//vector<int> rev[500001];
//
//
//
//
//
//
//
//int main(){
//
//}
#include <iostream>
using namespace std;

double power(double base, int exp);

int main() {
   double base;
   int exp;

   cout << "Enter a base(double): ";
   cin >> base;

   cout << "Enter an exponent(integer): ";
   cin >> exp;

   double result = power(base, exp);
   cout << "Result: " << result << endl;
}

double power(double base, int exp) {
   if (exp == 0) {
      return 1.0;
   }

   else if (exp > 0) {
      return base * power(base , exp-1);
   }

   else {
      return power(base, exp + 1) / base;
   }
}
