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
#include "Threadin.h"
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


//---------------------------------------------------------------------------
__fastcall TColorSorter::TColorSorter(TComponent* Owner)
	: TForm(Owner)
{
}


//---------------------------------------------------------------------------

void __fastcall TColorSorter::GetFilesClick(TObject *Sender)
{
   ListCurrentDirectory();
   GetTheCurrentFiles();
}  

/*
 void __fastcall TColorSorter::GetFilesClick(TObject *Sender)
{
    
	TFileOpenDialog *dialog = new TFileOpenDialog(this);
    dialog->Options << fdoPickFolders;
    if (dialog->Execute()) {
		fs::path selectedPath(dialog->FileName.c_str());
        cp = dialog->FileName.c_str();
        TheConsole->Lines->Add("Selected directory:\n");
        System::UnicodeString ConvertNonsense(selectedPath.c_str());
        TheConsole->Lines->Add(ConvertNonsense);
		for (const auto& entry : fs::directory_iterator(selectedPath)) {
			System::UnicodeString ConvertNonsense(entry.path().c_str());
            TheConsole->Lines->Add(ConvertNonsense);
            temp = entry.path().string();
            Files.push_back(temp);
        }
    }
    delete dialog;
}
*/

//---------------------------------------------------------------------------
void __fastcall TColorSorter::BEGINClick(TObject *Sender)
{
   TSortThread *myThread = new TSortThread(cp, Files, false);

}
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
	fs::path cp2 = fs::current_path();
	System::UnicodeString REALPathString(cp2.c_str());
	TheConsole->Lines->Add("Here is the current path: ");
	TheConsole->Lines->Add(REALPathString);
}

void __fastcall TColorSorter::GetTheCurrentFiles()
{
       fs::path cp = fs::current_path();
	   //cout << "Files in current directory:\n";
       Files.clear();
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
	int i, j;
	double key;
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
	}
}

void TColorSorter::printAverageOfVector(vector <double> arr, int n, vector <string> f)
{
   int i;
	for (i = 0; i < n; i++)
	{
		// cout << f[i] << " had an average of " << arr[i] << endl;
		System::UnicodeString ConvertNonsense = f[i].c_str();
		ConvertNonsense=ConvertNonsense+" had an average of "+FloatToStr(arr[i]);
		TheConsole->Lines->Add(ConvertNonsense);
	}

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

            // Set the color depth to 24 bits per pixel
            bmp->PixelFormat = pf24bit;

            bmp->SaveToFile(NewName+".bmp");
        }
        catch(Exception &e){
            // Handle any errors that occur during the conversion
            ShowMessage("Error converting image: " + e.Message);
		}


        // Delete the objects
        delete jpg;
		delete bmp;
	}
	GetTheCurrentFiles();
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

			// Remove the alpha channel
			png->RemoveTransparency();

			bmp->Assign(png);                       // Convert the PNG to BMP

            // Set the color depth to 24 bits per pixel
            bmp->PixelFormat = pf24bit;

            bmp->SaveToFile(NewName+".bmp");
        }
        catch(Exception &e){
            // Handle any errors that occur during the conversion
            ShowMessage("Error converting image: " + e.Message);
		}

		// Delete the objects
		delete png;
		delete bmp;
	}
	GetTheCurrentFiles();
}

//---------------------------------------------------------------------------


void __fastcall TColorSorter::ListOfColorsClick(TObject *Sender)
{
	if(ListOfColors->ItemIndex != -1)
	{
		// Get the selected item text
		String selectedItem = ListOfColors->Items->Strings[ListOfColors->ItemIndex];

		//Find the position of the brackets
		int start = selectedItem.Pos("(");
		int end = selectedItem.Pos(")");

		//Extract the RGB values
		String rgbValues = selectedItem.SubString(start+1, end-start-1);

		//Split the RGB values
		TStrings *values = new TStringList();
		values->Delimiter = ',';
		values->DelimitedText = rgbValues;

		//Assign the RGB values to the TEDitBoxes
		Red->Text = values->Strings[0];
		Green->Text = values->Strings[1];
		Blue->Text = values->Strings[2];

        delete values;
    }
}
//---------------------------------------------------------------------------




