#include <vcl.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <jpeg.hpp>     //For JPG support
#include <pngimage.hpp> //For PNG support
#include "BMP.h"
using namespace std;
namespace fs = std::filesystem;

string lol;
 string temp;
 vector <string> Files;
 void ListCurrentDirectory()
 {
	fs::path cp = fs::current_path();
	cout << "Current path: " << cp << "\n";
 }

 void GetTheCurrentFiles()
 {
	   fs::path cp = fs::current_path();
       Files.clear();
	   cout << "Files in current directory:\n";
		for (const auto& entry : fs::directory_iterator(cp)) {
		  cout << entry.path() << "\n";
		  temp = entry.path().string();
		  Files.push_back(temp);
		}
 }

 void insertionSort(vector <double>& arr, int n, vector <string>& f)
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
	for (i = 0; i < n; i++) {
        cout << f[i] << " is position " << arr[i] << endl;
	}
}

void printAverageOfArray(vector <double> arr, int n, vector <string> f)
{
    int i;
    for (i = 0; i < n; i++)
        cout << f[i] << " had an average of " << arr[i] << endl;
    cout << endl;
}

  void ConvertJPG()
{
  vector <int> Pictures;
   vector <string> extensions;
   vector <string> extjpg;

	for (const auto& f:Files) {
	size_t pos = f.find_last_of('.');
	System::UnicodeString File(f.c_str());
	System::UnicodeString ConvertNonsense(f.c_str() + pos);
	if (pos != string::npos) {
		ConvertNonsense = File + " has the extension of " + ConvertNonsense;
		wcout << ConvertNonsense << endl;
	}
	else {
		ConvertNonsense = File + " had no file extension";
		wcout << ConvertNonsense << endl;
	}

	if (f.find(".jpg") != string::npos) {
		extjpg.push_back(f);
	}
	}
	int ok;
	ok = extjpg.size();
	System::UnicodeString Detected = ok;
	Detected = Detected + " jpg files detected. \n\n";
	wcout << Detected;



	for (int i=0; i<ok; i++) {
        UnicodeString NewName = extjpg[i].c_str();
        int pos = NewName.LastDelimiter(".");
        if(pos != 0)
        {
            NewName = NewName.SubString(1, pos-1);  //Remove the extension
        }
        TJPEGImage *jpg = new TJPEGImage;
        TBitmap *bmp = new TBitmap;
        try{
            jpg->LoadFromFile(extjpg[i].c_str());   //Load the JPG

            bmp->Assign(jpg);                       // Convert the JPG to BMP

            // Set the color depth to 24 bits per pixel
            bmp->PixelFormat = pf24bit;

            bmp->SaveToFile(NewName+".bmp");
        }
        catch(Exception &e){
            // Handle any errors that occur during the conversion
           cout << "Error converting image!" << endl;
		}


        // Delete the objects
        delete jpg;
		delete bmp;
	}
	GetTheCurrentFiles();
}

void ConvertPNG()
{
   vector <int> Pictures;
   vector <string> extensions;
   vector <string> extpng;

	for (const auto& f:Files) {
	size_t pos = f.find_last_of('.');
	System::UnicodeString File(f.c_str());
	System::UnicodeString ConvertNonsense(f.c_str() + pos);
	if (pos != string::npos) {
		ConvertNonsense = File + " has the extension of " + ConvertNonsense;
		wcout << ConvertNonsense << endl;
	}
	else {
		ConvertNonsense = File + " had no file extension";
		wcout << ConvertNonsense << endl;
	}

	if (f.find(".png") != string::npos) {
		extpng.push_back(f);
	}
	}
	int ok;
	ok = extpng.size();
	System::UnicodeString Detected = ok;
	Detected = Detected + " png files detected. \n\n";
	wcout << Detected;



	for (int i=0; i<ok; i++) {
		UnicodeString NewName = extpng[i].c_str();
        int pos = NewName.LastDelimiter(".");
		if(pos != 0)
		{
			NewName = NewName.SubString(1, pos-1);  //Remove the extension
		}
		TPngImage *png = new TPngImage;
		TBitmap *bmp = new TBitmap;
		try{
			png->LoadFromFile(extpng[i].c_str());   //Load the PNG

			// Remove the alpha channel
			png->RemoveTransparency();

			bmp->Assign(png);                       // Convert the PNG to BMP

            // Set the color depth to 24 bits per pixel
            bmp->PixelFormat = pf24bit;

            bmp->SaveToFile(NewName+".bmp");
        }
        catch(Exception &e){
			// Handle any errors that occur during the conversion
			cout <<"Error converting image!" << endl;
		}

		// Delete the objects
		delete png;
		delete bmp;
	}
	GetTheCurrentFiles();
}

int _tmain(int argc, _TCHAR* argv[])
{
	int R, G, B, H, W;	  //Args for sorting
	char Choice;
    R=0; G=0; B=0; H=1; W=1;
	ListCurrentDirectory();
	GetTheCurrentFiles();

	vector <int> Pictures;
	vector <string> extensions;
	vector <string> extbmp;
	if(argc<2)
	{
		cout << "No args were entered." << endl;
		cout << "Please specify Red, Green, Blue, Height fraction and Width fraction \n";
		cout << "(Separate your values with spaces) ";
		cin >> R >> G >> B >> H >> W;

		cout << "Do you have any PNGs and JPGs you'd like to convert? ";
		cout << "Enter J for JPG, P for PNG, b for both. ";
		cin >> Choice;

		if(Choice=='j')
		{
			 ConvertJPG();
		}
		else if(Choice=='p')
		{
			ConvertPNG();
		}
		else if(Choice=='b')
		{
			ConvertJPG();
			ConvertPNG();
		}
        goto BEGIN;
    }
	if(argc>7)
	{
		cout << "Too many args!" << endl;
        return 0;
	}
	for(int i = 1; i < argc; i++) {
		if(argc==7 && i==7)
		{
			goto SixthArg;
        }
        int num = _ttoi(argv[i]);
        if(num >= 0 && num <= 255) {
			cout << "Argument " << i << " (integer): " << num << "\n";
        } else {
			cout << "Argument " << i << " is not in the range 0-255.\n";
            return 0;
		}
		switch(i)
		{
			case 1:
				R=num;
				break;
			case 2:
				G=num;
				break;
			case 3:
				B=num;
				break;
			case 4:
				H=num;
				break;
			case 5:
				W=num;
                break;
		}
	}
	SixthArg:
	if(argc==7)
	{
		if(argv[6][0]=='j')
		{
			 ConvertJPG();
		}
		if(argv[6][0]=='p')
		{
			ConvertPNG();
		}
		if(argv[6][0]=='b')
		{
			ConvertJPG();
			ConvertPNG();
		}
	}
	 BEGIN:
	//This for loop gets me the file extensions of the files
	for (const auto& f:Files) {
			size_t pos = f.find_last_of('.');
			if (pos != string::npos) {
				string extension = f.substr(pos);
				extensions.push_back(extension);
				cout << "File extension: " << extension << "\n";
			}
			else {
                cout << "No extension found for " << f << ".\n";
			}
	}

	//Check if files are BMP files
	for (int i=0; i<extensions.size(); i++) {
		if(extensions[i]==".bmp")
		{
			extbmp.push_back(Files[i]);
		}
	}
	int ok=extbmp.size();
	cout << ok << " bmp files detected. \n\n";

	for(int i=0; i<ok; i++)
	{
		string hold=extbmp[i];
	   size_t lastSlashPos = hold.find_last_of("/\\");
	   if (lastSlashPos != std::string::npos) {
        // Extract everything after the last slash or backslash
		extbmp[i] = hold.substr(lastSlashPos + 1);

        // Print the result
		cout << "Result: " << extbmp[i] << endl;
       }
	}


	vector <BMP> Bruh;
	BMP PlaceHolder(5000,5000, false);                				// I generate this placeholder because
	PlaceHolder.fill_region(50, 20, 100, 100, 255, 0, 255, 255);    // if the first picture's resolution is too low
	vector <double> averages;                                       // the program won't work right


	for (int i=0; i<ok; i++) {
        averages.push_back(0);
		BMP PlaceHolder(extbmp[i].c_str());
		averages[i]=PlaceHolder.OrganizeAverageColor2(R,G,B,H,W);
	}
	 insertionSort(averages, ok, extbmp);
	 printAverageOfArray(averages, ok, extbmp);
     string HoldNewDest;
	//This segment is to copy the files
	 //and give the copies new name with number
	for (int l=0; l<ok; l++)
	{

	filesystem::path source = extbmp[l];
	filesystem::path source2 = to_string(l)+"_"+extbmp[l];
	filesystem::path destinationDirectory = "SortedOutput/";
	filesystem::path destinationFile = destinationDirectory/source2.filename();
	//We need to put our results somewhere that isn't the same directory
	//Because we don't want to waste time deleting the results
	try{
	 // Create the destination directory if it doesn't exist
		if (!filesystem::exists(destinationDirectory)) {
			filesystem::create_directories(destinationDirectory);
		}

		filesystem::copy(source, destinationFile);
	}
	catch (filesystem::filesystem_error& e) {
	}
	}
	/* Old version
	 //This segment is to copy the files
	 //and give the copies new name with number
	for (int l=0; l<ok; l++)
	{
	ifstream source(extbmp[l], ios::binary);
	ofstream dest(to_string(l)+"_"+extbmp[l],ios::binary);

	//Get file size
	source.seekg(0, ios::end);
	ifstream::pos_type size = source.tellg();
	source.seekg(0);
	// Allocate memory for buffer
	char* buffer = new char[size];

	//copy file
	source.read(buffer,size);
	dest.write(buffer, size);

	//clean up
	delete[] buffer;
	source.close();
	dest.close();

	}*/

     system("pause");
	return 0;

}

/*
int _tmain(int argc, _TCHAR* argv[])
{

}
*/