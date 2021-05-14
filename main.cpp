#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BMP.h"
using namespace std;

void insertionSort(float arr[], int n, string f[])
{
    int i, key, j;
    string key2;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        key2=f[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            f[j+1]=f[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        f[j+1]=key2;
    }
}
void printArray(string f[], float arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << f[i] << " had an average of " << arr[i] << endl;
    cout << endl;
}

int main() {
  string name;
  string files[100];
  int count=0;
  ifstream FileNames("Files.txt");
  while (getline (FileNames, name))
  {
    files[count]=name;
    name=files[count];
    count++;
  }
  cout << "The files in this directory are... " << endl;
  for(int i=0; i<count; i++)
  {
    cout << files[i] << endl;
  }
 
  int choice;
  int Pictures[100];
  cout << "\n\n Time to start organizing by the color red! \n";
  int iteration=0;
float averages[count];
  
 
  vector <BMP> Bruh;
  BMP temp("placeholder.bmp");
  for (int j=0; j<count; j++)
  {
    BMP temp(files[j].c_str());
    Bruh.push_back(temp);
    averages[j]=temp.OrganizeAverageRed();
  }

for (int k=0; k<count; k++)
{
  cout << "Average " << k << "   " << averages[k] << endl;
}
insertionSort(averages, count, files);
printArray(files, averages, count);

char c;
for (int l=0; l<count; l++)
{
ifstream i_file(files[l]);
ofstream o_file(to_string(l)+"_"+files[l]);
while(i_file.get(c))
{
    o_file.put(c);
}
i_file.close();
o_file.close();
}


}


