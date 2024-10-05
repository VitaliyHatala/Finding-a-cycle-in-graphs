#include <iostream>

#include <cmath> 
#include <fstream> 
#include <vector> 
#include <string>
using namespace std;

int main()
{
   ifstream file1("Text.txt");


   int natural_size = 0;

   string str = "";

   getline(file1, str);


   for (int i = 0; i < str.size(); i++)
   {
      if (str[i] == ' ')
      {
         natural_size++;
      }
   }

   natural_size += 1;

   ifstream file("Text.txt");
   int size;
   cout << "Hom many points do you have? ";
   cin >> size;

   if (size <= 0)
   {
      cout << "Invalid number";
      return 0;
   }
   if (natural_size != size)
   {
      cout << "Invalid matrix number";
      return 0;
   }


   int orient_counter;
   int yes_no;

   cout << "Is the graph directed?\n[1 - Yes]\n[2 - No]\n";
   cin >> yes_no;

   if (yes_no == 1)
      orient_counter = 1;
   else if (yes_no == 2)
      orient_counter = 2;
   else
   {
      cout << "Invalid number";
      return 0;
   }

   int** arr = new int* [size];
   for (int i = 0; i < size; i++)
   {
      arr[i] = new int[size];
   }

   char* letter = new char[size];
   cout << "\t";
   for (int i = 0; i < size; ++i)
   {
      letter[i] = 'a' + i;
      cout << letter[i] << "\t";
   }
   for (int i = 0; i < size; ++i)
   {
      letter[i] = 'a' + i;
      cout << endl;
      cout << letter[i];
      for (int j = 0; j < size; j++)
      {
         file >> arr[i][j];
         cout << "\t" << arr[i][j];
      }
   }

   int sum_all = 0;
   int index = 0;
   int max_sum = 0;
   for (int i = 0; i < size; i++)
   {
      int sum = 0;
      for (int j = 0; j < size; j++)
      {
         sum += arr[i][j];
         sum_all += arr[i][j];
      }
      if (sum > max_sum)
      {
         index = i;
         max_sum = sum;
      }
   }

   cout << endl;


   vector<char> symbol;
   int counter_step = 0;
   symbol.push_back(letter[index]);
   while (sum_all > 0)
   {
      bool found = false;
      for (int j = 0; j < size; j++)
      {
         if (arr[index][j] == 1)
         {
            found = true;
            arr[index][j] = 0;
            arr[j][index] = 0;
            index = j;
            symbol.push_back(letter[j]);
            counter_step += 1;
            sum_all -= orient_counter;
            break;
         }
      }
      if (!found)
      {
         break;
      }
   }

   if (yes_no == 2)
   {
      if (symbol[0] != symbol.back())
      {
         symbol.push_back(symbol[0]);
      }
   }

   if (yes_no == 1)
   {
      if (symbol[0] != symbol.back())
      {
         cout << "Cicle doesnt exist";
         return 0;
      }
   }
   cout << endl;
   cout << endl << "----------------------------------------" << endl;
   cout << "Cycle: ";
   for (int i = 0; i < symbol.size(); i++)
   {
      if (i != symbol.size() - 1)
         cout << symbol[i] << "->";

      else
         cout << symbol[i] << ".";
   }
   cout << endl;
   cout << "Steps = " << counter_step;

   return 0;
}
