//---------------------------------------------------------------------------

#ifndef Problem1H
#define Problem1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
//---------------------------------------------------------------------------
class TItem1 : public TForm
{
__published:	// IDE-managed Components
	TCircle *Circle1;
	TCircle *Circle2;
	TCircle *Circle3;
	TButton *tEnd;
	TLabel *FreeName;
	TButton *tStart;
	TButton *tChange;
	TLabel *Label1;
	TEdit *BusyEdit;
	TEdit *DocuEdit;
	TLabel *BusyName;
	TLabel *DocuName;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *FreeEdit;
	TButton *Button3;
	TLabel *pFree;
	TLabel *pDocu;
	TLabel *pBusy;
	TLine *Line1;
	TLine *Line2;
	TLine *Line3;
	TLine *Line4;
	TLine *Line5;
	TLine *Line6;
	TLine *Line9;
	TLine *Line10;
	TLine *Line7;
	TLine *Line8;
	TLabel *Label9;
	TLabel *Label10;
	TLine *Line11;
	TLine *Line12;
	TLine *Line13;
	TLine *Line14;
	TLine *Line15;
	TLine *Line16;
	TLine *Line17;
	TLine *Line18;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall tEndClick(TObject *Sender);
	void __fastcall tStartClick(TObject *Sender);
	void __fastcall tChangeClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TItem1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TItem1 *Item1;
//---------------------------------------------------------------------------
#endif
