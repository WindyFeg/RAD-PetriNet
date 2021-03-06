//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Problem4.h"
#include "petri_net.h"
#include "petri_net.cpp"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TItem4 *Item4;
Net n;
//---------------------------------------------------------------------------
__fastcall TItem4::TItem4(TComponent* Owner)
	: TForm(Owner)
{
}

long long count(int p1, int p2, int p3, int p4, int p5, int p6) {
    /*
    p1: wait
    p2: inside
    p3: done
    p4: free
    p5: busy
    p6: docu

    t1: start
    t2: change
    t3: end
    */

    int patient = p1 + p2 + p3;
    int doctor = p4 + p5 + p6;
    if (p1 == 0 && p2 == 0 && p3 == patient && p4 == doctor && p5 == 0 && p6 == 0) {
        return 1;
    }

    else if (p1 < 0 || p2 < 0 || p3 < 0 || p4 < 0 || p5 < 0 || p6 < 0) {
        return 0;
    }

    else {
        return 1 + count(p1 - 1, p2 + 1, p3, p4 -1, p5 + 1, p6)
                 + count(p1, p2 -1, p3 + 1, p4, p5 - 1, p6 + 1)
                 + count(p1, p2, p3, p4 + 1, p5, p6 - 1);
    }
}
//---------------------------------------------------------------------------
void __fastcall TItem4::Button3Click(TObject *Sender)
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
	int p1, p2, p3, p4, p5, p6;
	int* M = n.getMarking();
	p1 = M[1];
	p2 = M[2]; //3
	p3 = M[3];
	p4 = M[0]; //
	p5 = M[4]; //
	p6 = M[5];

	int a = count(p1, p2, p3, p4, p5, p6);
	num->Text = a;
}
//---------------------------------------------------------------------------

void __fastcall TItem4::endClick(TObject *Sender)
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

    int p1, p2, p3, p4, p5, p6;
	int* M = n.getMarking();
	p1 = M[1];
	p2 = M[2]; //3
	p3 = M[3];
	p4 = M[0]; //
	p5 = M[4]; //
	p6 = M[5];

	int a = count(p1, p2, p3, p4, p5, p6);
	num->Text = a;

    FreeEdit->Text = pFree3->Text;
	 DocuEdit->Text = pDocu3->Text;
	 BusyEdit->Text = pBusy3->Text;
	 WaitEdit->Text = pWait3->Text;
	 InsideEdit->Text = pInside3->Text;
	 DoneEdit->Text = pDone3->Text;
}
//---------------------------------------------------------------------------

void __fastcall TItem4::tStartClick(TObject *Sender)
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

    int p1, p2, p3, p4, p5, p6;
	int* M = n.getMarking();
	p1 = M[1];
	p2 = M[2]; //3
	p3 = M[3];
	p4 = M[0]; //
	p5 = M[4]; //
	p6 = M[5];

	int a = count(p1, p2, p3, p4, p5, p6);
	num->Text = a;

    FreeEdit->Text = pFree3->Text;
	 DocuEdit->Text = pDocu3->Text;
	 BusyEdit->Text = pBusy3->Text;
	 WaitEdit->Text = pWait3->Text;
	 InsideEdit->Text = pInside3->Text;
	 DoneEdit->Text = pDone3->Text;
}
//---------------------------------------------------------------------------

void __fastcall TItem4::tChangeClick(TObject *Sender)
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

    int p1, p2, p3, p4, p5, p6;
	int* M = n.getMarking();
	p1 = M[1];
	p2 = M[2]; //3
	p3 = M[3];
	p4 = M[0]; //
	p5 = M[4]; //
	p6 = M[5];

	int a = count(p1, p2, p3, p4, p5, p6);
	num->Text = a;

    FreeEdit->Text = pFree3->Text;
	 DocuEdit->Text = pDocu3->Text;
	 BusyEdit->Text = pBusy3->Text;
	 WaitEdit->Text = pWait3->Text;
	 InsideEdit->Text = pInside3->Text;
	 DoneEdit->Text = pDone3->Text;
}
//---------------------------------------------------------------------------




