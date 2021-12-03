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