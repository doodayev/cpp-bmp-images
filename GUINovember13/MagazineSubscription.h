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
#include <pngimage.hpp> //For PNG support
#include <vector>
#include <string>
#include "BMP.h"
//---------------------------------------------------------------------------
class TColorSorter : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TButton *Button1;
	TButton *Button2;
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
	TEdit *HeightFraction;
	TEdit *WidthFraction;
	TButton *ConvertJPG;
	TButton *ConvertPNG;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	//void __fastcall DefaultClick(TObject *Sender);
	void __fastcall BSelectionClick(TObject *Sender);
	void __fastcall ConvertJPGClick(TObject *Sender);
	void __fastcall ConvertPNGClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	void __fastcall ListCurrentDirectory();
	void __fastcall GetTheCurrentFiles();
	void __fastcall insertionSort(vector <double>& arr, int n, vector <string>& f);
    void __fastcall printAverageOfArray(vector <double> arr, int n, vector <string> f);
	__fastcall TColorSorter(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TColorSorter *ColorSorter;
//---------------------------------------------------------------------------
#endif
