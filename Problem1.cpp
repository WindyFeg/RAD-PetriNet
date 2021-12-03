//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Problem1.h"
#include "petri_net.h"
#include "petri_net.cpp"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

Net n;
TItem1 *Item1;
//---------------------------------------------------------------------------
__fastcall TItem1::TItem1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TItem1::Button3Click(TObject *Sender)
{
	 pFree->Text = FreeEdit->Text;
     pDocu->Text = DocuEdit->Text;
	 pBusy->Text = BusyEdit->Text;



	string places[] = {"pFree", "pDocu", "pBusy"};
	string trans[] = {"tStart", "tChange", "tEnd"};
	string arcs[] = {"pFree->tStart", "tStart->pBusy", "pBusy->tChange", "tChange->pDocu", "pDocu->tEnd", "tEnd->pFree"};
	int nP = sizeof(places) / sizeof(places[0]);
	int nT = sizeof(trans) / sizeof(trans[0]);
	int nA = sizeof(arcs) / sizeof(arcs[0]);

	n.addPlaces(places, nP);
	n.addTransitions(trans, nT);
	n.addArcs(arcs, nA);
	int problem = 1;

	vector<int> input;
	input.push_back(FreeEdit->Text.ToInt());
	input.push_back(DocuEdit->Text.ToInt());
	input.push_back(BusyEdit->Text.ToInt());


    n.setMarking(input);
}
//---------------------------------------------------------------------------

void __fastcall TItem1::tEndClick(TObject *Sender)
{
	int* Output;
	Output = n.getMarking();
	n.t[0]->firing();

	int a = Output[0];
	int b = Output[1];
	int c = Output[2];

	pFree->Text = a;
	pDocu->Text = b;
	pBusy->Text = c;
}
//---------------------------------------------------------------------------


void __fastcall TItem1::tStartClick(TObject *Sender)
{
    int* Output;
	Output = n.getMarking();
	n.t[2]->firing();

	int a = Output[0];
	int b = Output[1];
	int c = Output[2];

	pFree->Text = a;
	pDocu->Text = b;
	pBusy->Text = c;
}
//---------------------------------------------------------------------------

void __fastcall TItem1::tChangeClick(TObject *Sender)
{
	 int* Output;
	Output = n.getMarking();
	n.t[1]->firing();

	int a = Output[0];
	int b = Output[1];
	int c = Output[2];

	pFree->Text = a;
	pDocu->Text = b;
	pBusy->Text = c;

}
//---------------------------------------------------------------------------

