//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop
#include "MagazineSubscription.h"
#include "Threadin.h"
#include <filesystem>
#include <string>
#include <vector>
namespace fs = std::filesystem;
using namespace std;
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TSortThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TSortThread::TSortThread(const fs::path& cp, const vector<string>& Files, bool CreateSuspended)
    : TThread(CreateSuspended), cp(cp), Files(Files)
{
}
//---------------------------------------------------------------------------
void __fastcall TSortThread::Execute()
{
	FreeOnTerminate = true;

	//---- Place thread code here ----
    vector <int> Pictures;
    vector <string> extensions;
	vector <string> extbmp;
    ColorSorter->GetTheCurrentFiles();
	for (const auto& f:ColorSorter->Files) {
	size_t pos = f.find_last_of('.');
	System::UnicodeString File(f.c_str());
	System::UnicodeString ConvertNonsense(f.c_str() + pos);
	if (pos != string::npos) {
		ConvertNonsense = File + " has the extension of " + ConvertNonsense;
		ColorSorter->TheConsole->Lines->Add(ConvertNonsense);
	}
	else {
		ConvertNonsense = File + " had no file extension";
		ColorSorter->TheConsole->Lines->Add(ConvertNonsense);
	}

	if (f.find(".bmp") != string::npos) {
		extbmp.push_back(f);
	}
}
int ok;
ok = extbmp.size();
System::UnicodeString Detected = ok;
Detected = Detected + " bmp files detected. \n\n";


for(int i=0; i<ok; i++)
	{
		string hold=extbmp[i];
	   size_t lastSlashPos = hold.find_last_of("/\\");
	   if (lastSlashPos != std::string::npos) {
		// Extract everything after the last slash or backslash
		extbmp[i] = hold.substr(lastSlashPos + 1);
		UnicodeString Bruv = extbmp[i].c_str();
		// Print the result
		ColorSorter->TheConsole->Lines->Add(Bruv);
	   }
	}
	int R = ColorSorter->Red->Text.ToInt();
	int B = ColorSorter->Blue->Text.ToInt();
	int G = ColorSorter->Green->Text.ToInt();
	int H = ColorSorter->HeightFraction->Text.ToInt();
	int W = ColorSorter->WidthFraction->Text.ToInt();
	vector <BMP> Bruh;

	BMP PlaceHolder(5000,5000, false);
	PlaceHolder.fill_region(50, 20, 100, 100, 255, 0, 255, 255);
   //	PlaceHolder.write("PlaceHolderImage.bmp");                      // the program won't work right for some reason without this??
	vector <double> averages;
	ColorSorter->TheConsole->Lines->Add(Detected);

	for (int i=0; i<ok; i++) {
		averages.push_back(0);
		BMP PlaceHolder(extbmp[i].c_str());
		//Bruh.push_back(PlaceHolder);
		averages[i] = PlaceHolder.OrganizeAverageColor2(R,G,B,H,W);
	}
	ColorSorter->insertionSort(averages, ok, extbmp);
	ColorSorter->printAverageOfVector(averages, ok, extbmp);
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
    //Synchronize();
}
//---------------------------------------------------------------------------
