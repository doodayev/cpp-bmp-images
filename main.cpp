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
  
  int count=0;
  string choose;
  ifstream FileNames("Files.txt");
  while (getline (FileNames, name))
  {
    count++;
  }
  string files[count];
  count=0;
  FileNames.close();
  ifstream FileNames2("Files.txt");
  while (getline (FileNames2, name))
  {
  files[count]=name;
  name=files[count];
  count++;
  }
  FileNames.close();
  cout << "The files in this directory are... " << endl;
  for(int i=0; i<count; i++)
  {
    cout << files[i] << endl;
  }
  
  int choice;
  int Pictures[count];
  cout << "By which color do you want to sort these pictures? \n";
 Repeat:
  cout << "Enter 1 for Red, 2 for Green, 3 for Blue, 4 for black \n";
  cout << "5 for yellow, 6 for turquoise, 7 for light purple, 8 for blue idk name of, 9 for red idk name of \n";
  cin >> choose;
  vector <BMP> Bruh;
  BMP temp("placeholder.bmp");
  float averages[count];
 if (choose == "1" || choose=="Red" || choose=="red" || choose=="r")
 {
  cout << "\n\n Time to start organizing by the color red! \n";
  for (int j=0; j<count; j++)
  {
    BMP temp(files[j].c_str());
    Bruh.push_back(temp);
    averages[j]=temp.OrganizeAverageColor2(255, 0, 0);
  }
 }
 else if (choose=="2" || choose=="Green" || choose=="green" || choose=="g")
 {
  cout << "\n\n Time to start organizing by the color green! \n";
  for (int j=0; j<count; j++)
  {
    BMP temp(files[j].c_str());
    Bruh.push_back(temp);
    averages[j]=temp.OrganizeAverageColor2(0, 255, 0);
  }
 }
 else if (choose=="3" || choose=="Blue" || choose=="blue" || choose=="b")
 {
    cout << "\n\n Time to start organizing by the color blue! \n";
  for (int j=0; j<count; j++)
  {
    BMP temp(files[j].c_str());
    Bruh.push_back(temp);
    averages[j]=temp.OrganizeAverageColor2(0, 0, 255);
  }
 }
 else if (choose=="4")
 {
    cout << "\n\n Time to start organizing by the color black! \n";
  for (int j=0; j<count; j++)
  {
    BMP temp(files[j].c_str());
    Bruh.push_back(temp);
    averages[j]=temp.OrganizeAverageColor2(0, 0, 0);
  }
 }
 else if (choose=="5")
 {
    cout << "\n\n Time to start organizing by the color yellow! \n";
  for (int j=0; j<count; j++)
  {
    BMP temp(files[j].c_str());
    Bruh.push_back(temp);
    averages[j]=temp.OrganizeAverageColor2(255, 255, 0);
  }
 }
 else if (choose=="6")
 {
    cout << "\n\n Time to start organizing by the color turquoise! \n";
  for (int j=0; j<count; j++)
  {
    BMP temp(files[j].c_str());
    Bruh.push_back(temp);
    averages[j]=temp.OrganizeAverageColor2(0, 255, 255);
  }
 }
 else if (choose=="7")
 {
    cout << "\n\n Time to start organizing by the color light purple! \n";
  for (int j=0; j<count; j++)
  {
    BMP temp(files[j].c_str());
    Bruh.push_back(temp);
    averages[j]=temp.OrganizeAverageColor2(255, 0, 255);
  }
 }
 else if (choose=="8")
 {
    cout << "\n\n Time to start organizing by the color idk blue! \n";
  for (int j=0; j<count; j++)
  {
    BMP temp(files[j].c_str());
    Bruh.push_back(temp);
    averages[j]=temp.OrganizeAverageColor2(0, 162, 232);
  }
 }
 else if (choose=="9")
 {
    cout << "\n\n Time to start organizing by the color idk red! \n";
  for (int j=0; j<count; j++)
  {
    BMP temp(files[j].c_str());
    Bruh.push_back(temp);
    averages[j]=temp.OrganizeAverageColor2(180, 41, 41);
  }
 }
 else{
     goto Repeat;
 }
 RestOfIt:
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
