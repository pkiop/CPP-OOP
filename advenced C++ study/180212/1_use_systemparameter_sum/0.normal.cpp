#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
   int sum = 0;

   for(int i=1; i<argc; ++i){
      int mult = 1;
      for(int j=0; argv[i][j]!=0; ++j){
         sum += (argv[i][j]-'0')*mult;
         mult*=10;
      }
   }
   cout << sum << endl;
   return 0;
}