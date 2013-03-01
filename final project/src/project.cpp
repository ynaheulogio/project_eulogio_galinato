#include "../include/project.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#define TARGET 500
#define MAX_NUMBER 999999

using namespace std;


const unsigned int size = 20;
unsigned int grid[size][size] = {0};

int number_of_divisors( int num )
{
   int number_of_divisors = 1;
   int half_num = (num / 2 );
   int adder;
   int i = 1;
   if ( (num % 2) == 0 )
   {
      adder = 1;
   }
   else
   {
      adder = 2;
   }
   while( i <= half_num )
   {
      if ( ( num % i ) == 0 )
      {
         number_of_divisors++;
      }

      i += adder;
   }
   return number_of_divisors;
}

project::project()
{
    //ctor
}

project::~project()
{
    //dtor
}

void project::multiples_3_and_5()
{
    int sum=0;

    for (int i=0; i<1000; i++)
    {
        if (i%3 == 0 || i%5 == 0)
        {
            sum+=i;

        }
    }

    cout << "sum is " << sum << endl;
}

void project::even_fibonacce()
{
	int sum = 0, x=0, y=1, z;
	while (x < 4000000)
	{
		if (x%2 == 0)
		{
			sum += x;
		}
		z = x;
		x += y;
		y = z;
	}

	cout << "The sum of all the even numbers in fibonacce sequence is "<< sum << endl;
}

void project::largest_prime_factor()
{

    long long largest_prime = 0;
    long long num = 13195LL;
    int i, j;

    for(i = 2; i < num; i++)
    {

        if(num%i == 0)
        {
            for(j = 2; j < i; j ++)
            {
                if(i%j == 0)
                {
                    break;
                }

                else if(j == i - 1)
                {
                    largest_prime = i;
                }
            }
        }

    }

    cout <<"The Largest prime number is "<< largest_prime << endl;

}

void project::largest_palindrome_product()
{
    int numbers[2];
    int largest[2];

    for(int i = 10; i < 1000; i++)
    {
        numbers[0] = i;
        for(int k = 10; k < 100; k++)
        {
            ostringstream convert;
            string palindrome;
            string final_palindrome = "";
            numbers[1] = k;
            int product = numbers[0]*numbers[1];
            convert << product;
            palindrome = convert.str();
            int range = palindrome.length();
            for(int x = 0; x < range; x++)
            {
                final_palindrome = palindrome.at(x) + final_palindrome;
                if(palindrome == final_palindrome)
                {
                    for(int j = 0; j < 2; j++)
                    {
                        largest[j] = numbers[j];
                    }
                }
            }
        }
    }

    for(int i = 0; i < 2; i++)
    {
        cout << largest[i] << endl;
    }

}

void project::smallest_multiple()
{
    int i = 20;

while (i %  2 != 0 || i %  3 != 0 || i %  4 != 0 || i %  5 != 0 ||
         i %  6 != 0 || i %  7 != 0 || i %  8 != 0 || i %  9 != 0 ||
         i % 10 != 0 || i % 11 != 0 || i % 12 != 0 || i % 13 != 0 ||
         i % 14 != 0 || i % 15 != 0 || i % 16 != 0 || i % 17 != 0 ||
         i % 18 != 0 || i % 19 != 0 || i % 20 != 0)
         {
                i += 20;
         }

         cout << "The smallest number divisible by each of the numbers from 1 to 20 is " << i << endl;
}

void project::sum_square_diff()
{
    int sum = 0;
    int sqr = 0;
    int z = 0;
    for(int i = 1; i <= 100; i++)
    {
        sum += i;
        z = i*i;
        sqr += z;
    }

    sum *= sum;
    cout<< "The difference of the sum and square is " << sum - sqr << endl;

}


void project::the_10001st_prime()
{
        int x = 2;
    for(int i = 0; i < 10001; i++)
    {
        bool a = false;
        while(!a)
        {
            for(int k = 2; k <= x; k++)
            {

                if(k == x)
                {
                    a = true;
                    break;
                }

                else if(x%k == 0)
                {
                    break;
                }

            }
            x++;
        }
    }
    x--;
    cout << x << endl;

}

void project::largest_product_in_series()
{


    ifstream ReadFile;
    string line, str;
    string numbers = "";
    int index = 0;
    int temp = 0;
    int y = 0;
    int product = 1;
    int product2 = 1;
    int getnumber[5];
    int highestproduct[5];
    ReadFile.open("4digits.txt");

    while(ReadFile.good())
    {
        getline(ReadFile, line);
        str = line;
        numbers += str;
    }
        string a;
        for(int i = 0; i < 1000 - 4;i++)
        {
            product2 = 1;

            index = i;
            for(int k = 0; k < 5; k++)
            {
                a = numbers.at(index);
                stringstream(a) >> temp;
                y = temp;
                getnumber[k] = y;
                product2 *= getnumber[k];
                index++;
             }

            if(product < product2)
            {
                product = product2;
                for(int k = 0; k < 5; k++)
                {
                    highestproduct[k] = getnumber[k];
                }
            }

        }
      cout << product << endl;

}

void project::special_pytho_triplet()
{
          int total = 1000;

    for (int a = 1; a <= total/3; a++)
    {
        for (int b = a + 1; b <= total/2; b++)
        {
            int c = total - a - b;
            if ( c > 0 && (a*a + b*b == c*c) )

               cout<<a*b*c<<endl;
        }
    }

}

void project::summation_of_primes()
{
	int num=1;
	unsigned long long int total=2;
	int divisor;

	bool prime = true ;

	while (num<2000000)
	{
prime=true;
	if (num<=1)
		prime=false;
	else if(num==2||num==3)
		prime=true;
	else if (num%2==0)
	prime = false ;
	else
	{

		for(divisor=3; divisor <1415;divisor=divisor+2)
		{
			if (num==divisor)
				prime=true;
		else if (num%divisor==0){
		prime=false;
		break;
		}

		}

	}
if (prime==true){
	total=total+num;


}

		num=num+2;
	}
	cout<<"Their Sum is " << total << endl;

}

void project :: largest_product_grid()
{
    unsigned int r=0, c=0;


    ifstream fin("numbahs.txt");
    if( fin )
    {
        for( r=0; r < size*size; r++ )
            fin >> grid[r/size][r%size];

        fin.close();
    }


    unsigned int product = 1;
    unsigned int maxProduct = product;

    // vertical products
    for( c=0; c < size; ++c )
        for( r=0; r < size-3; ++r )
        {
            product = grid[r][c]*grid[r+1][c]*grid[r+2][c]*grid[r+3][c];
            if( product > maxProduct )
                maxProduct = product;
        }

    // horizontal products
    for( r=0; r < size; ++r )
        for( c=0; c < size-3; ++c )
        {
            product = grid[r][c]*grid[r][c+1]*grid[r][c+2]*grid[r][c+3];
            if( product > maxProduct )
                maxProduct = product;
        }

    // diagonal products - \
    for( c=0; c < size-3; ++c )
        for( r=0; r < size-3; ++r )
        {
            product = grid[r][c]*grid[r+1][c+1]*grid[r+2][c+2]*grid[r+3][c+3];
            if( product > maxProduct )
                maxProduct = product;
        }

    // diagonal products - /
    for( c=3; c < size; ++c )
        for( r=0; r < size-3; ++r )
        {
            product = grid[r][c]*grid[r+1][c-1]*grid[r+2][c-2]*grid[r+3][c-3];
            if( product > maxProduct )
                maxProduct = product;
        }

    cout << "largest product = " << maxProduct << endl;
}

int project :: divisible_triangular_number()
{
    int divisors = 2;
 	int i = 7;
 	int limit;


 unsigned int triangle = 28;


 while ( divisors <= TARGET )
 {
  divisors = 2;
  i++;


  triangle += i;
  limit = sqrt(triangle);

  int j;


  for (j = 2; j <= limit; j++)
  {
   if (!(triangle % j))
   {
    if (j == limit)
     divisors++;
    else
     divisors += 2;
   }
  }
 }
 cout<<"The first triangle number with 500 or more divisors "<< triangle << endl;

    return 1;
}

void project :: largest_sum()
{
        long long temp = 0;
    long long f = 1;
    long long carry[50] = {0};
    int j = 49;
    int i = 49;
    long long answer[50] = {0};
    int data[100][50] = {
{  3, 7 ,1, 0, 7, 2, 8, 7, 5, 3, 3, 9, 0, 2, 1, 0, 2, 7, 9, 8, 7, 9, 7, 9, 9, 8, 2, 2, 0, 8, 3, 7, 5, 9, 0, 2, 4, 6, 5, 1, 0, 1, 3, 5, 7, 4, 0, 2, 5, 0} ,
{  4, 6, 3, 7, 6, 9, 3, 7, 6, 7, 7, 4, 9, 0, 0, 0, 9, 7, 1, 2, 6, 4, 8, 1, 2, 4, 8, 9, 6, 9, 7, 0, 0, 7, 8, 0, 5, 0, 4, 1, 7, 0, 1, 8, 2, 6, 0, 5, 3, 8}  ,
{  7, 4, 3, 2, 4, 9, 8, 6, 1, 9, 9, 5, 2, 4, 7, 4, 1, 0, 5, 9, 4, 7, 4, 2, 3, 3, 3, 0, 9, 5, 1, 3, 0, 5, 8, 1, 2, 3, 7, 2, 6, 6, 1, 7, 3, 0, 9, 6, 2, 9}  ,
{  9, 1, 9, 4, 2, 2, 1, 3, 3, 6, 3, 5, 7, 4, 1, 6, 1, 5, 7, 2, 5, 2, 2, 4, 3, 0, 5, 6, 3, 3, 0, 1, 8, 1, 1, 0, 7, 2, 4, 0, 6, 1, 5, 4, 9, 0, 8, 2, 5, 0}  ,
{  2, 3, 0, 6, 7, 5, 8, 8, 2, 0, 7, 5, 3, 9, 3, 4, 6, 1, 7, 1, 1, 7, 1, 9, 8, 0, 3, 1, 0, 4, 2, 1, 0, 4, 7, 5, 1, 3, 7, 7, 8, 0, 6, 3, 2, 4, 6, 6, 7, 6}  ,
{  8, 9, 2, 6, 1, 6, 7, 0, 6, 9, 6, 6, 2, 3, 6, 3, 3, 8, 2, 0, 1, 3, 6, 3, 7, 8, 4, 1, 8, 3, 8, 3, 6, 8, 4, 1, 7, 8, 7, 3, 4, 3, 6, 1, 7, 2, 6, 7, 5, 7}  ,
{  2, 8, 1, 1, 2, 8, 7, 9, 8, 1, 2, 8, 4, 9, 9, 7, 9, 4, 0, 8, 0, 6, 5, 4, 8, 1, 9, 3, 1, 5, 9, 2, 6, 2, 1, 6, 9, 1, 2, 7, 5, 8, 8, 9, 8, 3, 2, 7, 3, 8}  ,
{  4, 4, 2, 7, 4, 2, 2, 8, 9, 1, 7, 4, 3, 2, 5, 2, 0, 3, 2, 1, 9, 2, 3, 5, 8, 9, 4, 2, 2, 8, 7, 6, 7, 9, 6, 4, 8, 7, 6, 7, 0, 2, 7, 2, 1, 8, 9, 3, 1, 8}  ,
{  4, 7, 4, 5, 1, 4, 4, 5, 7, 3, 6, 0, 0, 1, 3, 0, 6, 4, 3, 9, 0, 9, 1, 1, 6, 7, 2, 1, 6, 8, 5, 6, 8, 4, 4, 5, 8, 8, 7, 1, 1, 6, 0, 3, 1, 5, 3, 2, 7, 6}  ,
{  7, 0, 3, 8, 6, 4, 8, 6, 1, 0, 5, 8, 4, 3, 0, 2, 5, 4, 3, 9, 9, 3, 9, 6, 1, 9, 8, 2, 8, 9, 1, 7, 5, 9, 3, 6, 6, 5, 6, 8, 6, 7, 5, 7, 9, 3, 4, 9, 5, 1}  ,
{  6, 2, 1, 7, 6, 4, 5, 7, 1, 4, 1, 8, 5, 6, 5, 6, 0, 6, 2, 9, 5, 0, 2, 1, 5, 7, 2, 2, 3, 1, 9, 6, 5, 8, 6, 7, 5, 5, 0, 7, 9, 3, 2, 4, 1, 9, 3, 3, 3, 1}  ,
{  6, 4, 9, 0, 6, 3, 5, 2, 4, 6, 2, 7, 4, 1, 9, 0, 4, 9, 2, 9, 1, 0, 1, 4, 3, 2, 4, 4, 5, 8, 1, 3, 8, 2, 2, 6, 6, 3, 3, 4, 7, 9, 4, 4, 7, 5, 8, 1, 7, 8}  ,
{  9, 2, 5, 7, 5, 8, 6, 7, 7, 1, 8, 3, 3, 7, 2, 1, 7, 6, 6, 1, 9, 6, 3, 7, 5, 1, 5, 9, 0, 5, 7, 9, 2, 3, 9, 7, 2, 8, 2, 4, 5, 5, 9, 8, 8, 3, 8, 4, 0, 7}  ,
{  5, 8, 2, 0, 3, 5, 6, 5, 3, 2, 5, 3, 5, 9, 3, 9, 9, 0, 0, 8, 4, 0, 2, 6, 3, 3, 5, 6, 8, 9, 4, 8, 8, 3, 0, 1, 8, 9, 4, 5, 8, 6, 2, 8, 2, 2, 7, 8, 2, 8}  ,
{  8, 0, 1, 8, 1, 1, 9, 9, 3, 8, 4, 8, 2, 6, 2, 8, 2, 0, 1, 4, 2, 7, 8, 1, 9, 4, 1, 3, 9, 9, 4, 0, 5, 6, 7, 5, 8, 7, 1, 5, 1, 1, 7, 0, 0, 9, 4, 3, 9, 0}  ,
{  3, 5, 3, 9, 8, 6, 6, 4, 3, 7, 2, 8, 2, 7, 1, 1, 2, 6, 5, 3, 8, 2, 9, 9, 8, 7, 2, 4, 0, 7, 8, 4, 4, 7, 3, 0, 5, 3, 1, 9, 0, 1, 0, 4, 2, 9, 3, 5, 8, 6}  ,
{  8, 6, 5, 1, 5, 5, 0, 6, 0, 0, 6, 2, 9, 5, 8, 6, 4, 8, 6, 1, 5, 3, 2, 0, 7, 5, 2, 7, 3, 3, 7, 1, 9, 5, 9, 1, 9, 1, 4, 2, 0, 5, 1, 7, 2, 5, 5, 8, 2, 9}  ,
{  7, 1, 6, 9, 3, 8, 8, 8, 7, 0, 7, 7, 1, 5, 4, 6, 6, 4, 9, 9, 1, 1, 5, 5, 9, 3, 4, 8, 7, 6, 0, 3, 5, 3, 2, 9, 2, 1, 7, 1, 4, 9, 7, 0, 0, 5, 6, 9, 3, 8}  ,
{  5, 4, 3, 7, 0, 0, 7, 0, 5, 7, 6, 8, 2, 6, 6, 8, 4, 6, 2, 4, 6, 2, 1, 4, 9, 5, 6, 5, 0, 0, 7, 6, 4, 7, 1, 7, 8, 7, 2, 9, 4, 4, 3, 8, 3, 7, 7, 6, 0, 4}  ,
{  5, 3, 2, 8, 2, 6, 5, 4, 1, 0, 8, 7, 5, 6, 8, 2, 8, 4, 4, 3, 1, 9, 1, 1, 9, 0, 6, 3, 4, 6, 9, 4, 0, 3, 7, 8, 5, 5, 2, 1, 7, 7, 7, 9, 2, 9, 5, 1, 4, 5}  ,
{  3, 6, 1, 2, 3, 2, 7, 2, 5, 2, 5, 0, 0, 0, 2, 9, 6, 0, 7, 1, 0, 7, 5, 0, 8, 2, 5, 6, 3, 8, 1, 5, 6, 5, 6, 7, 1, 0, 8, 8, 5, 2, 5, 8, 3, 5, 0, 7, 2, 1}  ,
{  4, 5, 8, 7, 6, 5, 7, 6, 1, 7, 2, 4, 1, 0, 9, 7, 6, 4, 4, 7, 3, 3, 9, 1, 1, 0, 6, 0, 7, 2, 1, 8, 2, 6, 5, 2, 3, 6, 8, 7, 7, 2, 2, 3, 6, 3, 6, 0, 4, 5}  ,
{  1, 7, 4, 2, 3, 7, 0, 6, 9, 0, 5, 8, 5, 1, 8, 6, 0, 6, 6, 0, 4, 4, 8, 2, 0, 7, 6, 2, 1, 2, 0, 9, 8, 1, 3, 2, 8, 7, 8, 6, 0, 7, 3, 3, 9, 6, 9, 4, 1, 2}  ,
{  8, 1, 1, 4, 2, 6, 6, 0, 4, 1, 8, 0, 8, 6, 8, 3, 0, 6, 1, 9, 3, 2, 8, 4, 6, 0, 8, 1, 1, 1, 9, 1, 0, 6, 1, 5, 5, 6, 9, 4, 0, 5, 1, 2, 6, 8, 9, 6, 9, 2}  ,
{  5, 1, 9, 3, 4, 3, 2, 5, 4, 5, 1, 7, 2, 8, 3, 8, 8, 6, 4, 1, 9, 1, 8, 0, 4, 7, 0, 4, 9, 2, 9, 3, 2, 1, 5, 0, 5, 8, 6, 4, 2, 5, 6, 3, 0, 4, 9, 4, 8, 3}  ,
{  6, 2, 4, 6, 7, 2, 2, 1, 6, 4, 8, 4, 3, 5, 0, 7, 6, 2, 0, 1, 7, 2, 7, 9, 1, 8, 0, 3, 9, 9, 4, 4, 6, 9, 3, 0, 0, 4, 7, 3, 2, 9, 5, 6, 3, 4, 0, 6, 9, 1}  ,
{  1, 5, 7, 3, 2, 4, 4, 4, 3, 8, 6, 9, 0, 8, 1, 2, 5, 7, 9, 4, 5, 1, 4, 0, 8, 9, 0, 5, 7, 7, 0, 6, 2, 2, 9, 4, 2, 9, 1, 9, 7, 1, 0, 7, 9, 2, 8, 2, 0, 9}  ,
{  5, 5, 0, 3, 7, 6, 8, 7, 5, 2, 5, 6, 7, 8, 7, 7, 3, 0, 9, 1, 8, 6, 2, 5, 4, 0, 7, 4, 4, 9, 6, 9, 8, 4, 4, 5, 0, 8, 3, 3, 0, 3, 9, 3, 6, 8, 2, 1, 2, 6}  ,
{  1, 8, 3, 3, 6, 3, 8, 4, 8, 2, 5, 3, 3, 0, 1, 5, 4, 6, 8, 6, 1, 9, 6, 1, 2, 4, 3, 4, 8, 7, 6, 7, 6, 8, 1, 2, 9, 7, 5, 3, 4, 3, 7, 5, 9, 4, 6, 5, 1, 5}  ,
{  8, 0, 3, 8, 6, 2, 8, 7, 5, 9, 2, 8, 7, 8, 4, 9, 0, 2, 0, 1, 5, 2, 1, 6, 8, 5, 5, 5, 4, 8, 2, 8, 7, 1, 7, 2, 0, 1, 2, 1, 9, 2, 5, 7, 7, 6, 6, 9, 5, 4}  ,
{  7, 8, 1, 8, 2, 8, 3, 3, 7, 5, 7, 9, 9, 3, 1, 0, 3, 6, 1, 4, 7, 4, 0, 3, 5, 6, 8, 5, 6, 4, 4, 9, 0, 9, 5, 5, 2, 7, 0, 9, 7, 8, 6, 4, 7, 9, 7, 5, 8, 1}  ,
{  1, 6, 7, 2, 6, 3, 2, 0, 1, 0, 0, 4, 3, 6, 8, 9, 7, 8, 4, 2, 5, 5, 3, 5, 3, 9, 9, 2, 0, 9, 3, 1, 8, 3, 7, 4, 4, 1, 4, 9, 7, 8, 0, 6, 8, 6, 0, 9, 8, 4}  ,
{  4, 8, 4, 0, 3, 0, 9, 8, 1, 2, 9, 0, 7, 7, 7, 9, 1, 7, 9, 9, 0, 8, 8, 2, 1, 8, 7, 9, 5, 3, 2, 7, 3, 6, 4, 4, 7, 5, 6, 7, 5, 5, 9, 0, 8, 4, 8, 0, 3, 0}  ,
{  8, 7, 0, 8, 6, 9, 8, 7, 5, 5, 1, 3, 9, 2, 7, 1, 1, 8, 5, 4, 5, 1, 7, 0, 7, 8, 5, 4, 4, 1, 6, 1, 8, 5, 2, 4, 2, 4, 3, 2, 0, 6, 9, 3, 1, 5, 0, 3, 3, 2}  ,
{  5, 9, 9, 5, 9, 4, 0, 6, 8, 9, 5, 7, 5, 6, 5, 3, 6, 7, 8, 2, 1, 0, 7, 0, 7, 4, 9, 2, 6, 9, 6, 6, 5, 3, 7, 6, 7, 6, 3, 2, 6, 2, 3, 5, 4, 4, 7, 2, 1, 0}  ,
{  6, 9, 7, 9, 3, 9, 5, 0, 6, 7, 9, 6, 5, 2, 6, 9, 4, 7, 4, 2, 5, 9, 7, 7, 0, 9, 7, 3, 9, 1, 6, 6, 6, 9, 3, 7, 6, 3, 0, 4, 2, 6, 3, 3, 9, 8, 7, 0, 8, 5}  ,
{  4, 1, 0, 5, 2, 6, 8, 4, 7, 0, 8, 2, 9, 9, 0, 8, 5, 2, 1, 1, 3, 9, 9, 4, 2, 7, 3, 6, 5, 7, 3, 4, 1, 1, 6, 1, 8, 2, 7, 6, 0, 3, 1, 5, 0, 0, 1, 2, 7, 1}  ,
{  6, 5, 3, 7, 8, 6, 0, 7, 3, 6, 1, 5, 0, 1, 0, 8, 0, 8, 5, 7, 0, 0, 9, 1, 4, 9, 9, 3, 9, 5, 1, 2, 5, 5, 7, 0, 2, 8, 1, 9, 8, 7, 4, 6, 0, 0, 4, 3, 7, 5}  ,
{  3, 5, 8, 2, 9, 0, 3, 5, 3, 1, 7, 4, 3, 4, 7, 1, 7, 3, 2, 6, 9, 3, 2, 1, 2, 3, 5, 7, 8, 1, 5, 4, 9, 8, 2, 6, 2, 9, 7, 4, 2, 5, 5, 2, 7, 3, 7, 3, 0, 7}  ,
{  9, 4, 9, 5, 3, 7, 5, 9, 7, 6, 5, 1, 0, 5, 3, 0, 5, 9, 4, 6, 9, 6, 6, 0, 6, 7, 6, 8, 3, 1, 5, 6, 5, 7, 4, 3, 7, 7, 1, 6, 7, 4, 0, 1, 8, 7, 5, 2, 7, 5}  ,
{  8, 8, 9, 0, 2, 8, 0, 2, 5, 7, 1, 7, 3, 3, 2, 2, 9, 6, 1, 9, 1, 7, 6, 6, 6, 8, 7, 1, 3, 8, 1, 9, 9, 3, 1, 8, 1, 1, 0, 4, 8, 7, 7, 0, 1, 9, 0, 2, 7, 1}  ,
{  2, 5, 2, 6, 7, 6, 8, 0, 2, 7, 6, 0, 7, 8, 0, 0, 3, 0, 1, 3, 6, 7, 8, 6, 8, 0, 9, 9, 2, 5, 2, 5, 4, 6, 3, 4, 0, 1, 0, 6, 1, 6, 3, 2, 8, 6, 6, 5, 2, 6}  ,
{  3, 6, 2, 7, 0, 2, 1, 8, 5, 4, 0, 4, 9, 7, 7, 0, 5, 5, 8, 5, 6, 2, 9, 9, 4, 6, 5, 8, 0, 6, 3, 6, 2, 3, 7, 9, 9, 3, 1, 4, 0, 7, 4, 6, 2, 5, 5, 9, 6, 2}  ,
{  2, 4, 0, 7, 4, 4, 8, 6, 9, 0, 8, 2, 3, 1, 1, 7, 4, 9, 7, 7, 7, 9, 2, 3, 6, 5, 4, 6, 6, 2, 5, 7, 2, 4, 6, 9, 2, 3, 3, 2, 2, 8, 1, 0, 9, 1, 7, 1, 4, 1}  ,
{  9, 1, 4, 3, 0, 2, 8, 8, 1, 9, 7, 1, 0, 3, 2, 8, 8, 5, 9, 7, 8, 0, 6, 6, 6, 9, 7, 6, 0, 8, 9, 2, 9, 3, 8, 6, 3, 8, 2, 8, 5, 0, 2, 5, 3, 3, 3, 4, 0, 3}  ,
{  3, 4, 4, 1, 3, 0, 6, 5, 5, 7, 8, 0, 1, 6, 1, 2, 7, 8, 1, 5, 9, 2, 1, 8, 1, 5, 0, 0, 5, 5, 6, 1, 8, 6, 8, 8, 3, 6, 4, 6, 8, 4, 2, 0, 0, 9, 0, 4, 7, 0}  ,
{  2, 3, 0, 5, 3, 0, 8, 1, 1, 7, 2, 8, 1, 6, 4, 3, 0, 4, 8, 7, 6, 2, 3, 7, 9, 1, 9, 6, 9, 8, 4, 2, 4, 8, 7, 2, 5, 5, 0, 3, 6, 6, 3, 8, 7, 8, 4, 5, 8, 3}  ,
{  1, 1, 4, 8, 7, 6, 9, 6, 9, 3, 2, 1, 5, 4, 9, 0, 2, 8, 1, 0, 4, 2, 4, 0, 2, 0, 1, 3, 8, 3, 3, 5, 1, 2, 4, 4, 6, 2, 1, 8, 1, 4, 4, 1, 7, 7, 3, 4, 7, 0}  ,
{  6, 3, 7, 8, 3, 2, 9, 9, 4, 9, 0, 6, 3, 6, 2, 5, 9, 6, 6, 6, 4, 9, 8, 5, 8, 7, 6, 1, 8, 2, 2, 1, 2, 2, 5, 2, 2, 5, 5, 1, 2, 4, 8, 6, 7, 6, 4, 5, 3, 3}  ,
{  6, 7, 7, 2, 0, 1, 8, 6, 9, 7, 1, 6, 9, 8, 5, 4, 4, 3, 1, 2, 4, 1, 9, 5, 7, 2, 4, 0, 9, 9, 1, 3, 9, 5, 9, 0, 0, 8, 9, 5, 2, 3, 1, 0, 0, 5, 8, 8, 2, 2}  ,
{  9, 5, 5, 4, 8, 2, 5, 5, 3, 0, 0, 2, 6, 3, 5, 2, 0, 7, 8, 1, 5, 3, 2, 2, 9, 6, 7, 9, 6, 2, 4, 9, 4, 8, 1, 6, 4, 1, 9, 5, 3, 8, 6, 8, 2, 1, 8, 7, 7, 4}  ,
{  7, 6, 0, 8, 5, 3, 2, 7, 1, 3, 2, 2, 8, 5, 7, 2, 3, 1, 1, 0, 4, 2, 4, 8, 0, 3, 4, 5, 6, 1, 2, 4, 8, 6, 7, 6, 9, 7, 0, 6, 4, 5, 0, 7, 9, 9, 5, 2, 3, 6}  ,
{  3, 7, 7, 7, 4, 2, 4, 2, 5, 3, 5, 4, 1, 1, 2, 9, 1, 6, 8, 4, 2, 7, 6, 8, 6, 5, 5, 3, 8, 9, 2, 6, 2, 0, 5, 0, 2, 4, 9, 1, 0, 3, 2, 6, 5, 7, 2, 9, 6, 7}  ,
{  2, 3, 7, 0, 1, 9, 1, 3, 2, 7, 5, 7, 2, 5, 6, 7, 5, 2, 8, 5, 6, 5, 3, 2, 4, 8, 2, 5, 8, 2, 6, 5, 4, 6, 3, 0, 9, 2, 2, 0, 7, 0, 5, 8, 5, 9, 6, 5, 2, 2}  ,
{  2, 9, 7, 9, 8, 8, 6, 0, 2, 7, 2, 2, 5, 8, 3, 3, 1, 9, 1, 3, 1, 2, 6, 3, 7, 5, 1, 4, 7, 3, 4, 1, 9, 9, 4, 8, 8, 9, 5, 3, 4, 7, 6, 5, 7, 4, 5, 5, 0, 1}  ,
{  1, 8, 4, 9, 5, 7, 0, 1, 4, 5, 4, 8, 7, 9, 2, 8, 8, 9, 8, 4, 8, 5, 6, 8, 2, 7, 7, 2, 6, 0, 7, 7, 7, 1, 3, 7, 2, 1, 4, 0, 3, 7, 9, 8, 8, 7, 9, 7, 1, 5}  ,
{  3, 8, 2, 9, 8, 2, 0, 3, 7, 8, 3, 0, 3, 1, 4, 7, 3, 5, 2, 7, 7, 2, 1, 5, 8, 0, 3, 4, 8, 1, 4, 4, 5, 1, 3, 4, 9, 1, 3, 7, 3, 2, 2, 6, 6, 5, 1, 3, 8, 1}  ,
{  3, 4, 8, 2, 9, 5, 4, 3, 8, 2, 9, 1, 9, 9, 9, 1, 8, 1, 8, 0, 2, 7, 8, 9, 1, 6, 5, 2, 2, 4, 3, 1, 0, 2, 7, 3, 9, 2, 2, 5, 1, 1, 2, 2, 8, 6, 9, 5, 3, 9}  ,
{  4, 0, 9, 5, 7, 9, 5, 3, 0, 6, 6, 4, 0, 5, 2, 3, 2, 6, 3, 2, 5, 3, 8, 0, 4, 4, 1, 0, 0, 0, 5, 9, 6, 5, 4, 9, 3, 9, 1, 5, 9, 8, 7, 9, 5, 9, 3, 6, 3, 5}  ,
{  2, 9, 7, 4, 6, 1, 5, 2, 1, 8, 5, 5, 0, 2, 3, 7, 1, 3, 0, 7, 6, 4, 2, 2, 5, 5, 1, 2, 1, 1, 8, 3, 6, 9, 3, 8, 0, 3, 5, 8, 0, 3, 8, 8, 5, 8, 4, 9, 0, 3}  ,
{  4, 1, 6, 9, 8, 1, 1, 6, 2, 2, 2, 0, 7, 2, 9, 7, 7, 1, 8, 6, 1, 5, 8, 2, 3, 6, 6, 7, 8, 4, 2, 4, 6, 8, 9, 1, 5, 7, 9, 9, 3, 5, 3, 2, 9, 6, 1, 9, 2, 2}  ,
{  6, 2, 4, 6, 7, 9, 5, 7, 1, 9, 4, 4, 0, 1, 2, 6, 9, 0, 4, 3, 8, 7, 7, 1, 0, 7, 2, 7, 5, 0, 4, 8, 1, 0, 2, 3, 9, 0, 8, 9, 5, 5, 2, 3, 5, 9, 7, 4, 5, 7}  ,
{  2, 3, 1, 8, 9, 7, 0, 6, 7, 7, 2, 5, 4, 7, 9, 1, 5, 0, 6, 1, 5, 0, 5, 5, 0, 4, 9, 5, 3, 9, 2, 2, 9, 7, 9, 5, 3, 0, 9, 0, 1, 1, 2, 9, 9, 6, 7, 5, 1, 9}  ,
{  8, 6, 1, 8, 8, 0, 8, 8, 2, 2, 5, 8, 7, 5, 3, 1, 4, 5, 2, 9, 5, 8, 4, 0, 9, 9, 2, 5, 1, 2, 0, 3, 8, 2, 9, 0, 0, 9, 4, 0, 7, 7, 7, 0, 7, 7, 5, 6, 7, 2}  ,
{  1, 1, 3, 0, 6, 7, 3, 9, 7, 0, 8, 3, 0, 4, 7, 2, 4, 4, 8, 3, 8, 1, 6, 5, 3, 3, 8, 7, 3, 5, 0, 2, 3, 4, 0, 8, 4, 5, 6, 4, 7, 0, 5, 8, 0, 7, 7, 3, 0, 8}  ,
{  8, 2, 9, 5, 9, 1, 7, 4, 7, 6, 7, 1, 4, 0, 3, 6, 3, 1, 9, 8, 0, 0, 8, 1, 8, 7, 1, 2, 9, 0, 1, 1, 8, 7, 5, 4, 9, 1, 3, 1, 0, 5, 4, 7, 1, 2, 6, 5, 8, 1}  ,
{  9, 7, 6, 2, 3, 3, 3, 1, 0, 4, 4, 8, 1, 8, 3, 8, 6, 2, 6, 9, 5, 1, 5, 4, 5, 6, 3, 3, 4, 9, 2, 6, 3, 6, 6, 5, 7, 2, 8, 9, 7, 5, 6, 3, 4, 0, 0, 5, 0, 0}  ,
{  4, 2, 8, 4, 6, 2, 8, 0, 1, 8, 3, 5, 1, 7, 0, 7, 0, 5, 2, 7, 8, 3, 1, 8, 3, 9, 4, 2, 5, 8, 8, 2, 1, 4, 5, 5, 2, 1, 2, 2, 7, 2, 5, 1, 2, 5, 0, 3, 2, 7}  ,
{  5, 5, 1, 2, 1, 6, 0, 3, 5, 4, 6, 9, 8, 1, 2, 0, 0, 5, 8, 1, 7, 6, 2, 1, 6, 5, 2, 1, 2, 8, 2, 7, 6, 5, 2, 7, 5, 1, 6, 9, 1, 2, 9, 6, 8, 9, 7, 7, 8, 9}  ,
{  3, 2, 2, 3, 8, 1, 9, 5, 7, 3, 4, 3, 2, 9, 3, 3, 9, 9, 4, 6, 4, 3, 7, 5, 0, 1, 9, 0, 7, 8, 3, 6, 9, 4, 5, 7, 6, 5, 8, 8, 3, 3, 5, 2, 3, 9, 9, 8, 8, 6}  ,
{  7, 5, 5, 0, 6, 1, 6, 4, 9, 6, 5, 1, 8, 4, 7, 7, 5, 1, 8, 0, 7, 3, 8, 1, 6, 8, 8, 3, 7, 8, 6, 1, 0, 9, 1, 5, 2, 7, 3, 5, 7, 9, 2, 9, 7, 0, 1, 3, 3, 7}  ,
{  6, 2, 1, 7, 7, 8, 4, 2, 7, 5, 2, 1, 9, 2, 6, 2, 3, 4, 0, 1, 9, 4, 2, 3, 9, 9, 6, 3, 9, 1, 6, 8, 0, 4, 4, 9, 8, 3, 9, 9, 3, 1, 7, 3, 3, 1, 2, 7, 3, 1}  ,
{  3, 2, 9, 2, 4, 1, 8, 5, 7, 0, 7, 1, 4, 7, 3, 4, 9, 5, 6, 6, 9, 1, 6, 6, 7, 4, 6, 8, 7, 6, 3, 4, 6, 6, 0, 9, 1, 5, 0, 3, 5, 9, 1, 4, 6, 7, 7, 5, 0, 4}  ,
{  9, 9, 5, 1, 8, 6, 7, 1, 4, 3, 0, 2, 3, 5, 2, 1, 9, 6, 2, 8, 8, 9, 4, 8, 9, 0, 1, 0, 2, 4, 2, 3, 3, 2, 5, 1, 1, 6, 9, 1, 3, 6, 1, 9, 6, 2, 6, 6, 2, 2}  ,
{  7, 3, 2, 6, 7, 4, 6, 0, 8, 0, 0, 5, 9, 1, 5, 4, 7, 4, 7, 1, 8, 3, 0, 7, 9, 8, 3, 9, 2, 8, 6, 8, 5, 3, 5, 2, 0, 6, 9, 4, 6, 9, 4, 4, 5, 4, 0, 7, 2, 4}  ,
{  7, 6, 8, 4, 1, 8, 2, 2, 5, 2, 4, 6, 7, 4, 4, 1, 7, 1, 6, 1, 5, 1, 4, 0, 3, 6, 4, 2, 7, 9, 8, 2, 2, 7, 3, 3, 4, 8, 0, 5, 5, 5, 5, 6, 2, 1, 4, 8, 1, 8}  ,
{  9, 7, 1, 4, 2, 6, 1, 7, 9, 1, 0, 3, 4, 2, 5, 9, 8, 6, 4, 7, 2, 0, 4, 5, 1, 6, 8, 9, 3, 9, 8, 9, 4, 2, 2, 1, 7, 9, 8, 2, 6, 0, 8, 8, 0, 7, 6, 8, 5, 2}  ,
{  8, 7, 7, 8, 3, 6, 4, 6, 1, 8, 2, 7, 9, 9, 3, 4, 6, 3, 1, 3, 7, 6, 7, 7, 5, 4, 3, 0, 7, 8, 0, 9, 3, 6, 3, 3, 3, 3, 0, 1, 8, 9, 8, 2, 6, 4, 2, 0, 9, 0}  ,
{  1, 0, 8, 4, 8, 8, 0, 2, 5, 2, 1, 6, 7, 4, 6, 7, 0, 8, 8, 3, 2, 1, 5, 1, 2, 0, 1, 8, 5, 8, 8, 3, 5, 4, 3, 2, 2, 3, 8, 1, 2, 8, 7, 6, 9, 5, 2, 7, 8, 6}  ,
{  7, 1, 3, 2, 9, 6, 1, 2, 4, 7, 4, 7, 8, 2, 4, 6, 4, 5, 3, 8, 6, 3, 6, 9, 9, 3, 0, 0, 9, 0, 4, 9, 3, 1, 0, 3, 6, 3, 6, 1, 9, 7, 6, 3, 8, 7, 8, 0, 3, 9}  ,
{  6, 2, 1, 8, 4, 0, 7, 3, 5, 7, 2, 3, 9, 9, 7, 9, 4, 2, 2, 3, 4, 0, 6, 2, 3, 5, 3, 9, 3, 8, 0, 8, 3, 3, 9, 6, 5, 1, 3, 2, 7, 4, 0, 8, 0, 1, 1, 1, 1, 6}  ,
{  6, 6, 6, 2, 7, 8, 9, 1, 9, 8, 1, 4, 8, 8, 0, 8, 7, 7, 9, 7, 9, 4, 1, 8, 7, 6, 8, 7, 6, 1, 4, 4, 2, 3, 0, 0, 3, 0, 9, 8, 4, 4, 9, 0, 8, 5, 1, 4, 1, 1}  ,
{  6, 0, 6, 6, 1, 8, 2, 6, 2, 9, 3, 6, 8, 2, 8, 3, 6, 7, 6, 4, 7, 4, 4, 7, 7, 9, 2, 3, 9, 1, 8, 0, 3, 3, 5, 1, 1, 0, 9, 8, 9, 0, 6, 9, 7, 9, 0, 7, 1, 4}  ,
{  8, 5, 7, 8, 6, 9, 4, 4, 0, 8, 9, 5, 5, 2, 9, 9, 0, 6, 5, 3, 6, 4, 0, 4, 4, 7, 4, 2, 5, 5, 7, 6, 0, 8, 3, 6, 5, 9, 9, 7, 6, 6, 4, 5, 7, 9, 5, 0, 9, 6}  ,
{  6, 6, 0, 2, 4, 3, 9, 6, 4, 0, 9, 9, 0, 5, 3, 8, 9, 6, 0, 7, 1, 2, 0, 1, 9, 8, 2, 1, 9, 9, 7, 6, 0, 4, 7, 5, 9, 9, 4, 9, 0, 1, 9, 7, 2, 3, 0, 2, 9, 7}  ,
{  6, 4, 9, 1, 3, 9, 8, 2, 6, 8, 0, 0, 3, 2, 9, 7, 3, 1, 5, 6, 0, 3, 7, 1, 2, 0, 0, 4, 1, 3, 7, 7, 9, 0, 3, 7, 8, 5, 5, 6, 6, 0, 8, 5, 0, 8, 9, 2, 5, 2}  ,
{  1, 6, 7, 3, 0, 9, 3, 9, 3, 1, 9, 8, 7, 2, 7, 5, 0, 2, 7, 5, 4, 6, 8, 9, 0, 6, 9, 0, 3, 7, 0, 7, 5, 3, 9, 4, 1, 3, 0, 4, 2, 6, 5, 2, 3, 1, 5, 0, 1, 1}  ,
{  9, 4, 8, 0, 9, 3, 7, 7, 2, 4, 5, 0, 4, 8, 7, 9, 5, 1, 5, 0, 9, 5, 4, 1, 0, 0, 9, 2, 1, 6, 4, 5, 8, 6, 3, 7, 5, 4, 7, 1, 0, 5, 9, 8, 4, 3, 6, 7, 9, 1}  ,
{  7, 8, 6, 3, 9, 1, 6, 7, 0, 2, 1, 1, 8, 7, 4, 9, 2, 4, 3, 1, 9, 9, 5, 7, 0, 0, 6, 4, 1, 9, 1, 7, 9, 6, 9, 7, 7, 7, 5, 9, 9, 0, 2, 8, 3, 0, 0, 6, 9, 9}  ,
{  1, 5, 3, 6, 8, 7, 1, 3, 7, 1, 1, 9, 3, 6, 6, 1, 4, 9, 5, 2, 8, 1, 1, 3, 0, 5, 8, 7, 6, 3, 8, 0, 2, 7, 8, 4, 1, 0, 7, 5, 4, 4, 4, 9, 7, 3, 3, 0, 7, 8}  ,
{  4, 0, 7, 8, 9, 9, 2, 3, 1, 1, 5, 5, 3, 5, 5, 6, 2, 5, 6, 1, 1, 4, 2, 3, 2, 2, 4, 2, 3, 2, 5, 5, 0, 3, 3, 6, 8, 5, 4, 4, 2, 4, 8, 8, 9, 1, 7, 3, 5, 3}  ,
{  4, 4, 8, 8, 9, 9, 1, 1, 5, 0, 1, 4, 4, 0, 6, 4, 8, 0, 2, 0, 3, 6, 9, 0, 6, 8, 0, 6, 3, 9, 6, 0, 6, 7, 2, 3, 2, 2, 1, 9, 3, 2, 0, 4, 1, 4, 9, 5, 3, 5}  ,
{  4, 1, 5, 0, 3, 1, 2, 8, 8, 8, 0, 3, 3, 9, 5, 3, 6, 0, 5, 3, 2, 9, 9, 3, 4, 0, 3, 6, 8, 0, 0, 6, 9, 7, 7, 7, 1, 0, 6, 5, 0, 5, 6, 6, 6, 3, 1, 9, 5, 4}  ,
{  8, 1, 2, 3, 4, 8, 8, 0, 6, 7, 3, 2, 1, 0, 1, 4, 6, 7, 3, 9, 0, 5, 8, 5, 6, 8, 5, 5, 7, 9, 3, 4, 5, 8, 1, 4, 0, 3, 6, 2, 7, 8, 2, 2, 7, 0, 3, 2, 8, 0}  ,
{  8, 2, 6, 1, 6, 5, 7, 0, 7, 7, 3, 9, 4, 8, 3, 2, 7, 5, 9, 2, 2, 3, 2, 8, 4, 5, 9, 4, 1, 7, 0, 6, 5, 2, 5, 0, 9, 4, 5, 1, 2, 3, 2, 5, 2, 3, 0, 6, 0, 8}  ,
{  2, 2, 9, 1, 8, 8, 0, 2, 0, 5, 8, 7, 7, 7, 3, 1, 9, 7, 1, 9, 8, 3, 9, 4, 5, 0, 1, 8, 0, 8, 8, 8, 0, 7, 2, 4, 2, 9, 6, 6, 1, 9, 8, 0, 8, 1, 1, 1, 9, 7}  ,
{  7, 7, 1, 5, 8, 5, 4, 2, 5, 0, 2, 0, 1, 6, 5, 4, 5, 0, 9, 0, 4, 1, 3, 2, 4, 5, 8, 0, 9, 7, 8, 6, 8, 8, 2, 7, 7, 8, 9, 4, 8, 7, 2, 1, 8, 5, 9, 6, 1, 7}  ,
{  7, 2, 1, 0, 7, 8, 3, 8, 4, 3, 5, 0, 6, 9, 1, 8, 6, 1, 5, 5, 4, 3, 5, 6, 6, 2, 8, 8, 4, 0, 6, 2, 2, 5, 7, 4, 7, 3, 6, 9, 2, 2, 8, 4, 5, 0, 9, 5, 1, 6}  ,
{  2, 0, 8, 4, 9, 6, 0, 3, 9, 8, 0, 1, 3, 4, 0, 0, 1, 7, 2, 3, 9, 3, 0, 6, 7, 1, 6, 6, 6, 8, 2, 3, 5, 5, 5, 2, 4, 5, 2, 5, 2, 8, 0, 4, 6, 0, 9, 7, 2, 2} ,
{  5, 3, 5, 0, 3, 5, 3, 4, 2, 2, 6, 4, 7, 2, 5, 2, 4, 2, 5, 0, 8, 7, 4, 0, 5, 4, 0, 7, 5, 5, 9, 1, 7, 8, 9, 7, 8, 1, 2, 6, 4, 3, 3, 0, 3, 3, 1, 6, 9, 0}
};

for (int y = 49; y >= 0; y --)
{

    temp = 0;

    for (int x = 0; x < 100; x ++)
    {

        temp += data[x][y];

    }

    carry[i] = temp;
    i--;

}

for (i = 49; i >= 1; i--)
{
    answer[j] = carry[i] % 10;
    carry[i] /= 10;
    carry[i-1] += carry[i];
    j--;
}

answer[j] = carry[0];

for (j = 0; j <= 7; j++)
{
        cout << answer[j];
}
cout << endl;
}

int longest_collatz_sequence1( double num )
{
   int counter = 1;
   double temp = num;

   while( temp > 1 )
   {
      if ( (temp / 2) == floor(temp / 2) )
      {
         temp /= 2;
      }
      else
      {
         temp = 3*temp + 1;
      }

      counter++;
   }
   return counter;
}
void project :: longest_collatz_sequence()
{
    cout.setf( ios_base::fixed, ios_base::floatfield );
   cout.precision( 0 );
   int max_chain = 0;
   int max_number = 0;
   int temp_chain = 0;
   int i;
   for ( i = 1; i <= MAX_NUMBER; i++ )
   {
      temp_chain = longest_collatz_sequence1( i );
      if ( temp_chain > max_chain )
      {
         max_chain = temp_chain;
         max_number = i;
      }

        //* cout << i << "\n";
   }
   cout << "\nThe starting number below " << MAX_NUMBER + 1 << endl;
   cout << " which produces the longest chain is " << max_number << endl;
   cout << " with a chain length of " << max_chain << endl;
}

void project :: diophantine_reciprocals_a()
{
cout << "none" << endl;
}

int  x[302];

void project :: power_digit_sum()
{
       x[301]=2;
	for (short power=1;power!=1000;power++)
	{
		for (short arraynum=301;arraynum!=0;arraynum--) {
			x[arraynum]=x[arraynum] * 2;
        }

		for (short arraynum=301;arraynum!=0;arraynum--) {
			if (x[arraynum]>9) {
                        x[arraynum]=x[arraynum]-10;
                        x[arraynum-1]=x[arraynum-1]+1;
			    }
		}
	}

	int sum=0;

		for (short arraynum=301;arraynum!=-1;arraynum--)
		{sum = sum +x[arraynum];}
		cout<< "The Sum of all the digits is " << sum << endl;

	cin.get();

}

int getValueOf1to19(int num);
int getValueOf20to99(int num);
int getValueOf1to9999(int num);

int getValueOf1to9999(int num) {
    if (num >= 0 && num <= 19) {
        return getValueOf1to19(num);
    } else if (num >= 20 && num <= 99) {
        return getValueOf20to99(num);
    } else if (num >= 100 && num <= 999) {
        int hundreds_value = getValueOf1to19(int(floor(num / 100)));
        hundreds_value += 7; // "hundred"
        cout <<"hundred";
        int tens_and_ones_value = getValueOf1to9999(num % 100);
        if (tens_and_ones_value > 0 && tens_and_ones_value <= 19) {
            hundreds_value += 3;
            std::cout << "and";
        }
        return hundreds_value + tens_and_ones_value;
    } else if (num >= 1000 && num <= 9999) {
        int thousands_value = getValueOf1to19(int(floor(num / 1000)));
        thousands_value += 8; // "thousand"
        cout << "thousand";
        int hundreds_tens_and_ones_value = num % 1000;

        return thousands_value
            + getValueOf1to9999(hundreds_tens_and_ones_value);
    }
}


int getValueOf20to99(int num) {
    int tens_value = 0;
    switch (int(floor(num / 10))) {
    case 2:
        tens_value = 6; // "twenty"
        cout << "twenty";
        break;
    case 3:
        tens_value = 6; // "thirty"
        cout << "thirty";
        break;
    case 4:
        tens_value = 5;  // "forty"
        cout << "forty";
        break;
    case 5:
        tens_value = 5; // "fifty"
        cout << "fifty";
        break;
    case 6:
        tens_value = 5; // "sixty"
        cout << "sixty";
        break;
    case 7:
        tens_value = 7; // "seventy"
        cout << "seventy";
        break;
    case 8:
        tens_value = 6; // "eighty"
        cout << "eighty";
        break;
    case 9:
        tens_value = 6; // "ninety"
        cout << "ninety";
        break;
    default:
        tens_value = 0;
        break;
    }

    return tens_value + getValueOf1to19(num % 10);
}

int getValueOf1to19(int num) {
    switch (num) {
    case 1:
        cout << "one";
        return 3; // "one"
        break;
    case 2:
        cout << "two";
        return 3; // "two"
        break;
    case 3:
        cout << "three";
        return 5; // "three"
        break;
    case 4:
        cout << "four";
        return 4; // "four"
        break;
    case 5:
        cout << "five";
        return 4; // "five"
        break;
    case 6:
        cout << "six";
        return 3; // "six"
        break;
    case 7:
        cout << "seven";
        return 5; // "seven"
        break;
    case 8:
        cout << "eight";
        return 5; // "eight"
        break;
    case 9:
        cout << "nine";
        return 4; // "nine"
        break;
    case 10:
        cout << "ten";
        return 3; // "ten"
        break;
    case 11:
        cout << "eleven";
        return 6; // "eleven"
        break;
    case 12:
        cout << "twelve";
        return 6; // "twelve"
        break;
    case 13:
        cout << "thirteen";
        return 8; // "thirteen"
        break;
    case 14:
        cout << "fourteen";
        return 8; // "fourteen"
        break;
    case 15:
        cout << "fifteen";
        return 7; // "fifteen"
        break;
    case 16:
        cout << "sixteen";
        return 7; // "sixteen"
        break;
    case 17:
        cout << "seventeen";
        return 9; // "seventeen"
        break;
    case 18:
        cout << "eighteen";
        return 8; // "eighteen"
        break;
    case 19:
        cout << "nineteen";
        return 8; // "nineteen"
        break;
    default:
        return 0;
        break;
    }
}

int project :: number_letter_counts()
{

    int number_value = 0;
    int sum = 0;
    for (int i = 0; i <= 1000; i++) {
        number_value = getValueOf1to9999(i);
        sum += number_value;
        cout << " - num: " << i
            << " value: " << number_value << " - total: " << sum << std::endl;
    }
    cout << "sum: " << sum << std::endl;
    return 0;

}


typedef vector<vector<int > > Array;

int FromStrToInt(string const& str)
{
	int num = 0;
	istringstream iss(str);
	iss >> num;
	return num;
}

void ReadFromFile(string const& fileName, Array& list)
{
	ifstream f(fileName.c_str());
	if (!f.bad())
	{
		while (!f.eof())
		{
			string data;
			getline(f, data);

			vector<int> line;
			istringstream istr(data);
			while (!istr.eof())
			{

				string item;
				istr >> item;
				line.push_back(FromStrToInt(item));
			}
			list.push_back(line);
		}
	}
	f.close();
}


int FindMaxWay(Array const& baseMatrix)
{
	Array list(baseMatrix);
	for (int i = 0; i < list.size() - 1; ++i)
	{
		for (int j = 0; j < list[i].size(); ++j)
		{
			if (list[i][j] + baseMatrix[i + 1][j] > list[i + 1][j])
			{
				list[i + 1][j] = list[i][j] + baseMatrix[i + 1][j];
			}
			if (list[i][j] + baseMatrix[i + 1][j + 1]> list[i + 1][j + 1])
			{
				list[i + 1][j + 1] = list[i][j] + baseMatrix[i + 1][j + 1];
			}
		}
	}

	vector<int> sortedLine = list.back();
	sort(sortedLine.begin(), sortedLine.end());

	return sortedLine.back();
}


int project :: max_path_sum_one()
{
	Array matrix;
	ReadFromFile("input.txt", matrix);
	cout << FindMaxWay(matrix) << endl;

    return 0;
}

void project :: counting_sundays()
{
        int count = 0, days_in_month, days_passed = 1;

    for (int i = 1901; i < 2000; i++)
    {
        for (int j = 1; j <= 12; j++)
        {
            if (j == 4 || j == 6 || j == 9 || j == 11)
            {
                days_in_month = 30;
            }
            else if (j == 2)
            {
                if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
                {
                    days_in_month = 29;
                }
                else
                {
                    days_in_month = 28;
                }
            }
            else
            {
                days_in_month = 31;
            }
            if (days_passed % 7 == 0)
            {
                count++;
            }
            days_passed += days_in_month;
        }
    }

    cout << count << endl;
}

void factorial(vector<int> &, int);
void  carryNum(vector<int> &);

void carryNum(vector<int> & vect)
{
    int carry = 0;
    for(int i = 0; i < vect.size(); i++)
    {
        if( 9 < vect[i] )
        {
           if( i+1 == vect.size() )
           {
              vect.push_back(vect[i]/10);
              vect[i] = vect[i]%10;
           }
           else
           {
               carry   = vect[i]/10;
               vect[i] = vect[i]%10;
               vect[i+1] += carry;
           }
        }
    }
}

void factorial(vector<int> & vect, int num)
{
    for (int j = 0; j < vect.size(); j++)
    {
        vect[j] = vect[j] * num;
    }
    carryNum(vect);
}


int project :: factorial_digit_sum()
{
    int number    = 0;
    int sumDigits = 0;
    vector<int>     v1;

    cout << "Enter a number: ";
    cin >> number;
    v1.push_back(number);

    for(int i = 2; i < number; i++)
    {
        factorial(v1, i);
    }

    cout << endl << "Sum of these digits: " << endl;
    for(int i = 0; i < v1.size(); i++)
    {
        sumDigits += v1[i];
    }
    cout << sumDigits << endl;

    return 0;
}

void project :: name_scores()
{
    ifstream myfile;
   string alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   string line, temp = "";
   int range=alpha.length();
   int rank=0;
   int range_a=0;
   int range_b=1;
   int letter=0;
   int prod=0;
   int i_n=0;
   unsigned long int sum = 0;
   myfile.open ("names.txt");
   getline(myfile,line);
   myfile.close();
   range_a = line.length();

   for(int i=0; i<range_a; i++ )
   {
       if(line.at(i)==',')
       {
            range_b++;
       }
   }
  string names[range_b];
    for(int i = 1; i < range_a; i++)
    {
        if(line.at(i) == '"' || line.at(i) == ',')
        {
            if(temp != "")
            {
                names[i_n] = temp;
                temp = "";
                i_n++;
            }
            continue;
        }
        temp += line.at(i);
    }

    for(int i = 0; i < range_b; i++)
    {
        for(int j = 0; j < range_b;j++)
        {
            if(names[i] > names[j])
            {
                string temp_r = names[j];
                names[j] = names[i];
                names[i] = temp_r;
            }
        }
    }


	 for(int i = 0; i < range_b; i++)
    {
        letter = 0;
        rank = range_b - i;
        int range_c = names[i].length();
        for(int m = 0; m < range_c; m++)
        {
            for(int n = 0; n < range; n++)
            {
                if(names[i].at(m) == alpha.at(n))
                {
                    letter += n + 1;
                    break;
                }
            }
        }

        prod=rank*letter;
        sum+=prod;
        }

    cout<<"The total of the name score is:" << sum << endl;
}
