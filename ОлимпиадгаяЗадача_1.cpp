

#include <iostream>
#include <cmath>
 
typedef unsigned long long T_my;
 
size_t dig_sum(T_my val)
{
   size_t sum = 0;
   
   do
   {
      sum += val % 10;
   }
   while ( val /= 10 );
   return sum;
}
 
int main()
{
   int k = 7, n = 2;
   T_my max = static_cast<T_my> (pow( 10., n));
   T_my i;
   T_my cnt = 0;
   
   for ( i = 0; i < max ; ++i )
      if ( dig_sum(i) == k )
         ++cnt;
   std::cout << cnt << std::endl;
   return 0;
