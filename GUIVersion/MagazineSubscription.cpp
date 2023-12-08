//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <filesystem>
#include <jpeg.hpp>     //For JPG support
#include <pngimage.hpp> //For PNG support
#include "BMP.h"
using namespace std;
namespace fs = std::filesystem;

#pragma hdrstop

#include "MagazineSubscription.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TColorSorter *ColorSorter;

string lol;
string temp;
vector <string> Files;

//---------------------------------------------------------------------------
__fastcall TColorSorter::TColorSorter(TComponent* Owner)
	: TForm(Owner)
{
}


//---------------------------------------------------------------------------
void __fastcall TColorSorter::Button1Click(TObject *Sender)
{
	//EFullName->Text.w_str() takes name of variable and makes it
	//name of the message box

	//Putting an L in front of "Full name" is something about string
    //formatting
   //Application->MessageBoxW(EFullName->Text.w_str(), L"That's your name", MB_OK);
   ListCurrentDirectory();
   GetTheCurrentFiles();
}
//---------------------------------------------------------------------------
void __fastcall TColorSorter::Button2Click(TObject *Sender)
{   /*// You seem able to add as many options as you want to messagebox by just adding |
	int answer = Application->MessageBoxW(L"PINGAS?", L"A message from Robotnik", MB_YESNO|MB_ICONQUESTION|MB_DEFBUTTON2);
	if(answer == IDYES) {
	   ShowMessage("Very good.");
	}
	else
		ShowMessage("SILENCE!!!");*/

   vector <int> Pictures;
   vector <string> extensions;
   vector <string> extbmp;

	for (const auto& f:Files) {
	size_t pos = f.find_last_of('.');
	System::UnicodeString File(f.c_str());
	System::UnicodeString ConvertNonsense(f.c_str() + pos);
	if (pos != string::npos) {
		ConvertNonsense = File + " has the extension of " + ConvertNonsense;
		TheConsole->Lines->Add(ConvertNonsense);
	}
	else {
		ConvertNonsense = File + " had no file extension";
		TheConsole->Lines->Add(ConvertNonsense);
	}

	if (f.find(".bmp") != string::npos) {
		extbmp.push_back(f);
	}
}
int ok;
ok = extbmp.size();
System::UnicodeString Detected = ok;
Detected = Detected + " bmp files detected. \n\n";
TheConsole->Lines->Add(Detected);

for(int i=0; i<ok; i++)
	{
		string hold=extbmp[i];
	   size_t lastSlashPos = hold.find_last_of("/\\");
	   if (lastSlashPos != std::string::npos) {
        // Extract everything after the last slash or backslash
		extbmp[i] = hold.substr(lastSlashPos + 1);
		UnicodeString Bruv = extbmp[i].c_str();
		// Print the result
		TheConsole->Lines->Add(Bruv);
       }
	}
	int R = Red->Text.ToInt();
	int B = Blue->Text.ToInt();
	int G = Green->Text.ToInt();
	int H = HeightFraction->Text.ToInt();
	int W = WidthFraction->Text.ToInt();
	vector <BMP> Bruh;

	BMP PlaceHolder(3840,2160, false);
	PlaceHolder.fill_region(50, 20, 100, 100, 255, 0, 255, 255);
	PlaceHolder.write("PlaceHolderImage.bmp");                      // the program won't work right for some reason
	vector <double> averages;

	for (int i=0; i<ok; i++) {
		averages.push_back(0);
		BMP PlaceHolder(extbmp[i].c_str());
		Bruh.push_back(PlaceHolder);
		averages[i] = PlaceHolder.OrganizeAverageColor2(R,G,B,H,W);
	}
	insertionSort(averages, ok, extbmp);
	printAverageOfArray(averages, ok, extbmp);
	string HoldNewDest;
    //This segment is to copy the files
	 //and give the copies new name with number
	for (int l=0; l<ok; l++)
	{
	/*ifstream source(extbmp[l], ios::binary);
	HoldNewDest=to_string(l)+"_"+extbmp[l];
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
	*/

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

        // Copy the file
        filesystem::copy(source, destinationFile);
		//cout << "File copied successfully.\n";
	}
	catch (filesystem::filesystem_error& e) {
        //cout << "Error: " << e.what() << '\n';
	}
}

}
//---------------------------------------------------------------------------
/*void __fastcall TForm1::DefaultClick(TObject *Sender)
{
	EFullName->Text = "Some Dood";
	Eemail->Text = "doodguy@gmail.com";
	EAge->Text = 22;
	CGender->ItemIndex = 0;
	// int age = EAge->Text.ToInt(); (If you want to get the age as an input)
} */
//---------------------------------------------------------------------------
void __fastcall TColorSorter::BSelectionClick(TObject *Sender)
{
   /*if(LMagazine->SelCount > 0)
   {
	   ShowMessage(LMagazine->Items->Strings[LMagazine->ItemIndex]);
   } */

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


void __fastcall TColorSorter::ListCurrentDirectory()
{
	fs::path cp = fs::current_path();
	System::UnicodeString REALPathString(cp.c_str());
	TheConsole->Lines->Add("Here is the current path: ");
	TheConsole->Lines->Add(REALPathString);
}

void __fastcall TColorSorter::GetTheCurrentFiles()
{
    fs::path cp = fs::current_path();
	   //cout << "Files in current directory:\n";
	   TheConsole->Lines->Add("Files in current directory:\n");
		for (const auto& entry : fs::directory_iterator(cp)) {
		 // cout << entry.path() << "\n";
		 System::UnicodeString ConvertNonsense(entry.path().c_str());
		 TheConsole->Lines->Add(ConvertNonsense);
		  temp = entry.path().string();
		  Files.push_back(temp);
		}
}
void TColorSorter::insertionSort(vector <double>& arr, int n, vector <string>& f)
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
		System::UnicodeString ConvertNonsense(f[i].c_str());
        ConvertNonsense=ConvertNonsense+" is position "+IntToStr(i);
		TheConsole->Lines->Add(ConvertNonsense);
        cout << f[i] << " is position " << arr[i] << endl;
	}
}

void TColorSorter::printAverageOfArray(vector <double> arr, int n, vector <string> f)
{
   int i;
	for (i = 0; i < n; i++)
	{
		// cout << f[i] << " had an average of " << arr[i] << endl;
		System::UnicodeString ConvertNonsense(f[i].c_str());
		ConvertNonsense=ConvertNonsense+" had an average of "+FloatToStr(arr[i]);
		TheConsole->Lines->Add(ConvertNonsense);
	}

    cout << endl;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------




void __fastcall TColorSorter::ConvertJPGClick(TObject *Sender)
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
		TheConsole->Lines->Add(ConvertNonsense);
	}
	else {
		ConvertNonsense = File + " had no file extension";
		TheConsole->Lines->Add(ConvertNonsense);
	}

	if (f.find(".jpg") != string::npos) {
		extjpg.push_back(f);
	}
	}
	int ok;
	ok = extjpg.size();
	System::UnicodeString Detected = ok;
	Detected = Detected + " jpg files detected. \n\n";
	TheConsole->Lines->Add(Detected);



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
		bmp->SaveToFile(NewName+".bmp");
		}
		__finally{
			delete jpg;
			delete bmp;
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TColorSorter::ConvertPNGClick(TObject *Sender)
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
		TheConsole->Lines->Add(ConvertNonsense);
	}
	else {
		ConvertNonsense = File + " had no file extension";
		TheConsole->Lines->Add(ConvertNonsense);
	}

	if (f.find(".png") != string::npos) {
		extpng.push_back(f);
	}
	}
	int ok;
	ok = extpng.size();
	System::UnicodeString Detected = ok;
	Detected = Detected + " png files detected. \n\n";
	TheConsole->Lines->Add(Detected);



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
		bmp->Assign(png);                       // Convert the JPG to BMP
		bmp->SaveToFile(NewName+".bmp");
		}
		__finally{
			delete png;
			delete bmp;
		}
	}
}
//---------------------------------------------------------------------------


