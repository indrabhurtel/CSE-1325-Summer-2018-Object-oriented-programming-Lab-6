//Indra Bhurtel
//1001542825

#ifndef _choice_h
#define _choice_h

#include <iostream>
#include <gtkmm.h>
#include <vector>
#include <string>

using namespace std;
using namespace Gtk;

class Dialogs // Dialogs class
{
public:
	static string gettingMenu(string msg, string title);
	static string itemsSelection(string msg, string title);
	static string pickingItem1();
	static string pickingItem2();
	static string pickingItem3();
	
};
class Apply // Apply class
{
public:
	static string position(string msg, string title);
	static string printingName(string text);
};

class Orders // Orders class
{
	public:
	static void message();
	
	static void printingOrder();
};

#endif