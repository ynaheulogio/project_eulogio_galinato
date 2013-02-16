#include "../include/project.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>

using namespace std;

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
