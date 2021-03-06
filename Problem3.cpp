//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Problem3.h"
#include "petri_net.h"
#include "petri_net.cpp"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TItem3 *Item3;
Net n;
//---------------------------------------------------------------------------
__fastcall TItem3::TItem3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TItem3::Button3Click(TObject *Sender)
{
    n.nP = 0;
	 n.nT = 0;
	 n.p.clear();
     n.t.clear();

	 pFree3->Text = FreeEdit->Text;
	 pDocu3->Text = DocuEdit->Text;
	 pBusy3->Text = BusyEdit->Text;
	 pWait3->Text = WaitEdit->Text;
	 pInside3->Text = InsideEdit->Text;
	 pDone3->Text = DoneEdit->Text;

     string places[] = {"pFree", "pWait", "pInside", "pDone", "pBusy", "pDocu"};
    string trans[] = {"tStart", "tChange", "tEnd"};
    string arcs[] = {
        "pFree->tStart",
        "pWait->tStart",
        "tStart->pBusy",
        "tStart->pInside",
        "pInside->tChange",
        "pBusy->tChange",
        "tEnd->pFree",
        "tChange->pDocu",
        "pDocu->tEnd",
        "tChange->pDone"};
    int nP = sizeof(places) / sizeof(places[0]);
    int nT = sizeof(trans) / sizeof(trans[0]);
    int nA = sizeof(arcs) / sizeof(arcs[0]);

	n.addPlaces(places, nP);
    n.addTransitions(trans, nT);
    n.addArcs(arcs, nA);

	int problem = 3;
    vector<int> input;
	input.push_back(FreeEdit->Text.ToInt());
	input.push_back(WaitEdit->Text.ToInt());
	input.push_back(InsideEdit->Text.ToInt());
	input.push_back(DoneEdit->Text.ToInt());
	input.push_back(BusyEdit->Text.ToInt());
	input.push_back(DocuEdit->Text.ToInt());

    	n.setMarking(input) ;
}
//---------------------------------------------------------------------------

void __fastcall TItem3::endClick(TObject *Sender)
{
     int* Output;
	Output = n.getMarking();
	n.t[2]->firing();

	Output = n.getMarking();

	int free = Output[0];
	int wait = Output[1];
	int inside = Output[2];
	int done = Output[3];
	int busy = Output[4];
	int doc = Output[5];




	pFree3->Text = free;
	pDocu3->Text = doc;
	pBusy3->Text = busy;
	pWait3->Text = wait;
	pInside3->Text = inside;
	pDone3->Text = done;

	FreeEdit->Text = pFree3->Text;
	 DocuEdit->Text = pDocu3->Text;
	 BusyEdit->Text = pBusy3->Text;
	 WaitEdit->Text = pWait3->Text;
	 InsideEdit->Text = pInside3->Text;
	 DoneEdit->Text = pDone3->Text;
}

//---------------------------------------------------------------------------

void __fastcall TItem3::tStartClick(TObject *Sender)
{
      int* Output;
	Output = n.getMarking();
	n.t[0]->firing();

	Output = n.getMarking();

	int free = Output[0];
	int wait = Output[1];
	int inside = Output[2];
	int done = Output[3];
	int busy = Output[4];
	int doc = Output[5];




	pFree3->Text = free;
	pDocu3->Text = doc;
	pBusy3->Text = busy;
	pWait3->Text = wait;
	pInside3->Text = inside;
	pDone3->Text = done;

    FreeEdit->Text = pFree3->Text;
	 DocuEdit->Text = pDocu3->Text;
	 BusyEdit->Text = pBusy3->Text;
	 WaitEdit->Text = pWait3->Text;
	 InsideEdit->Text = pInside3->Text;
	 DoneEdit->Text = pDone3->Text;
}

//---------------------------------------------------------------------------

void __fastcall TItem3::tChangeClick(TObject *Sender)
{
      int* Output;
	Output = n.getMarking();
	n.t[1]->firing();

    Output = n.getMarking();

	int free = Output[0];
	int wait = Output[1];
	int inside = Output[2];
	int done = Output[3];
	int busy = Output[4];
	int doc = Output[5];




	pFree3->Text = free;
	pDocu3->Text = doc;
	pBusy3->Text = busy;
	pWait3->Text = wait;
	pInside3->Text = inside;
	pDone3->Text = done;

    FreeEdit->Text = pFree3->Text;
	 DocuEdit->Text = pDocu3->Text;
	 BusyEdit->Text = pBusy3->Text;
	 WaitEdit->Text = pWait3->Text;
	 InsideEdit->Text = pInside3->Text;
	 DoneEdit->Text = pDone3->Text;
}

//---------------------------------------------------------------------------

