//---------------------------------------------------------------------------

#ifndef MagazineSubscriptionH
#define MagazineSubscriptionH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <jpeg.hpp>     //For JPG support
#include <pngimage.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp> //For PNG support
#include <vector>
#include <string>
#include "BMP.h"
namespace fs = std::filesystem;
//---------------------------------------------------------------------------
class TColorSorter : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TButton *GetFiles;
	TButton *BEGIN;
	TRichEdit *TheConsole;
	TEdit *Red;
	TEdit *Green;
	TEdit *Blue;
	TUpDown *UpDown2;
	TUpDown *UpDown3;
	TUpDown *UpDown4;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *HeightFractionLabel;
	TLabel *Label5;
	TLabel *WidthFractionLabel;
	TEdit *WidthFraction;
	TEdit *HeightFraction;
	TButton *ConvertJPG;
	TButton *ConvertPNG;
	TListBox *ListOfColors;
	void __fastcall GetFilesClick(TObject *Sender);
	void __fastcall BEGINClick(TObject *Sender);
	//void __fastcall DefaultClick(TObject *Sender);
	void __fastcall BSelectionClick(TObject *Sender);
	void __fastcall ConvertJPGClick(TObject *Sender);
	void __fastcall ConvertPNGClick(TObject *Sender);
	void __fastcall ListOfColorsClick(TObject *Sender);

private:	// User declarations
public:		// User declarations

	void __fastcall ListCurrentDirectory();
	void __fastcall GetTheCurrentFiles();
	void __fastcall insertionSort(vector <double>& arr, int n, vector <string>& f);
    void __fastcall printAverageOfVector(vector <double> arr, int n, vector <string> f);
	__fastcall TColorSorter(TComponent* Owner);
	vector <string> Files;
    fs::path cp;
};
//---------------------------------------------------------------------------
extern PACKAGE TColorSorter *ColorSorter;
//---------------------------------------------------------------------------
#endif
