//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("Problem4.cpp", Item4);
USEFORM("Problem3.cpp", Item3);
USEFORM("Main.cpp", Form1);
USEFORM("Problem1.cpp", Item1);
USEFORM("Problem2.cpp", Item2);
USEFORM("Unit2.cpp", info);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TItem1), &Item1);
		Application->CreateForm(__classid(TItem2), &Item2);
		Application->CreateForm(__classid(TItem3), &Item3);
		Application->CreateForm(__classid(TItem4), &Item4);
		Application->CreateForm(__classid(Tinfo), &info);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
