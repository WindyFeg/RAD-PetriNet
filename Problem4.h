//---------------------------------------------------------------------------

#ifndef Problem4H
#define Problem4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TItem4 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TCircle *pWait;
	TCircle *pInside;
	TCircle *pDone;
	TButton *tStart;
	TButton *tChange;
	TEdit *InsideEdit;
	TEdit *DoneEdit;
	TLabel *Label4;
	TLabel *labelinside;
	TLabel *label;
	TEdit *WaitEdit;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *labeldone;
	TButton *Button3;
	TLabel *pWait3;
	TLabel *pInside3;
	TLabel *pDone3;
	TCircle *Circle1;
	TCircle *Circle2;
	TCircle *Circle3;
	TLabel *FreeName;
	TButton *end;
	TLabel *BusyName;
	TLabel *DocuName;
	TLabel *pFree3;
	TLabel *pDocu3;
	TLabel *pBusy3;
	TEdit *BusyEdit;
	TEdit *DocuEdit;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *FreeEdit;
	TLine *Line1;
	TLine *Line2;
	TLine *Line3;
	TLine *Line4;
	TArc *Arc1;
	TArc *Z;
	TLine *Line5;
	TLine *Line6;
	TLine *Line7;
	TLine *Line8;
	TLine *Line9;
	TLine *Line10;
	TLine *Line11;
	TLine *Line12;
	TLine *Line13;
	TLine *Line14;
	TLabel *num;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLine *Line15;
	TLine *Line16;
	TLine *Line17;
	TLine *Line18;
	TLine *Line19;
	TLine *Line20;
	TLine *Line21;
	TLine *Line22;
	TLine *Line23;
	TLine *Line24;
	TLine *Line25;
	TLine *Line26;
	TLine *Line27;
	TLine *Line28;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall endClick(TObject *Sender);
	void __fastcall tStartClick(TObject *Sender);
	void __fastcall tChangeClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TItem4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TItem4 *Item4;
//---------------------------------------------------------------------------
#endif
