//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Problem2.h"
#include "petri_net.h"
#include "petri_net.cpp"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TItem2 *Item2;
Net n;
//---------------------------------------------------------------------------
__fastcall TItem2::TItem2(TComponent* Owner)
	: TForm(Owner)
{
	
}
//---------------------------------------------------------------------------

void __fastcall TItem2::Button3Click(TObject *Sender)
{
    n.nP = 0;
	 n.nT = 0;
	 n.p.clear();
     n.t.clear();

	pWait2->Text = WaitEdit->Text;
	 pInside2->Text = InsideEdit->Text;
	 pDone2->Text = DoneEdit->Text;

    string places[] = {"pWait", "pInside", "pDone"};
    string trans[] = {"tStart", "tChange"};
    string arcs[] = {"pWait->tStart",
                     "tStart->pInside",
                     "pInside->tChange",
                     "tChange->pDone"};
    int nP = sizeof(places) / sizeof(places[0]);
    int nT = sizeof(trans) / sizeof(trans[0]);
    int nA = sizeof(arcs) / sizeof(arcs[0]);

    n.addPlaces(places, nP);
    n.addTransitions(trans, nT);
	n.addArcs(arcs, nA);

	 vector<int> input;
	input.push_back(WaitEdit->Text.ToInt());
	input.push_back(InsideEdit->Text.ToInt());
	input.push_back(DoneEdit->Text.ToInt());
	n.setMarking(input) ;

}
//---------------------------------------------------------------------------

void __fastcall TItem2::tStartClick(TObject *Sender)
{
	  int* Output;
	Output = n.getMarking();
	n.t[0]->firing();

    Output = n.getMarking();

	int a = Output[0];
	int b = Output[1];
	int c = Output[2];



	pWait2->Text = a;
	pInside2->Text = b;
	pDone2->Text = c;

	WaitEdit->Text = pWait2->Text;
	InsideEdit->Text = pInside2->Text;
	DoneEdit->Text = pDone2->Text;
}
//---------------------------------------------------------------------------

void __fastcall TItem2::tChangeClick(TObject *Sender)
{
     int* Output;
	Output = n.getMarking();
	n.t[1]->firing();

	Output = n.getMarking();

	int a = Output[0];
	int b = Output[1];
	int c = Output[2];



	pWait2->Text = a;
	pInside2->Text = b;
	pDone2->Text = c;

    WaitEdit->Text = pWait2->Text;
	InsideEdit->Text = pInside2->Text;
	DoneEdit->Text = pDone2->Text;
}
//---------------------------------------------------------------------------

