//Indra Bhurtel


#include "choice.h"
using namespace std;
using namespace Gtk;

vector <string>name;
string myOrders;
float fixedCharge;
float charge=0.00;

static string printingName() // printing name
{
	for (int i =0; i< name.size(); i++)
	{
		return name[i];
	}
}

string Dialogs::gettingMenu(string msg, string title) // Getting menu on the first window
	{
		Dialog *dialog=new Dialog();
		dialog->set_title(title);

		Label *label1=new Label("");
		Label *label2=new Label(msg);
		dialog->get_content_area()->pack_start(*label1);
		dialog->get_content_area()->pack_start(*label2);
		label1->show();
		label2->show();

		dialog->add_button("Apply",1);
		dialog->add_button("Customer",0);
		dialog->add_button("Exit",2);


		int result=dialog->run();
		dialog->close();

		while(Main::events_pending())
		{
			Main::iteration();
		}
		delete dialog;
		delete label1;
		delete label2;


		if(result==0)
		{
			Dialogs::itemsSelection("Burrito or Bowl?", "Place your order");
		}
		else if(result== 1)
		{
			Apply::position("Enter your full name", "Roonie's Delivery Service");
		}
		else
		{
			exit(1);
		}
	}
string  Dialogs::itemsSelection(string msg, string title)
{

	Dialog *dialog=new Dialog();
	dialog->set_title(title);


		Label *label=new Label(msg);
		dialog->get_content_area()->pack_start(*label);
		label->show();

		dialog->add_button("OK",1);
		dialog->add_button("Cancel",0);

		Entry *entry = new Entry();
		entry -> set_text("");
		entry -> set_max_length(60);
		entry -> show();
		dialog -> get_vbox()->pack_start(*entry);

		int result=dialog->run();
		string text =  entry-> get_text();
		 myOrders.append("1.\t"+text+"\n");
		dialog->close();

		while(Main::events_pending())
		{
			Main::iteration();
		}

		if( text == "Burrito" )
		{
			charge +=5.25;
		}
		else if( text == "Bowl")
		{
			charge += 7.25;
		}
		delete dialog;
		delete label;
		delete entry;

		if(result==1)
		{
			Dialogs::pickingItem1();
		}
		else
		{
			exit(1);
		}
}
string Apply::position(string msg,  string title)
{
	Dialog *dialog=new Dialog();
	dialog->set_title(title);
	Label *label1=new Label("Welcome");
	Label *label=new Label(msg);

	dialog->get_content_area()->pack_start(*label1);
	dialog->get_content_area()->pack_start(*label);

	label1->show();
	label->show();

	dialog->add_button("OK",1);
	dialog->add_button("Cancel",0);

	Entry *entry = new Entry();
	entry -> set_text("");
	entry -> set_max_length(60);
	entry -> show();
	dialog -> get_vbox()->pack_start(*entry);

	int result=dialog->run();
	string text =  entry-> get_text();
	name.push_back(text);
	dialog->close();

	while(Main::events_pending())
	{
		Main::iteration();
	}
	delete dialog;
	delete label;
	delete label1;
	delete entry;

	if(result==1)
	{
		Apply::printingName(text);
	}
	else
	{
		exit(1);
	}

}
string Apply::printingName(string text) // printing name of a delivery drivers
{
	Dialog *dialog=new Dialog();
	dialog->set_title("Ronnie's Delivery Service");
	Label *label=new Label("Newest delivery person :"+ text );
	dialog->get_content_area()->pack_start(*label);
	label->show();
	dialog->add_button("OK",1);
	dialog->add_button("Cancel",0);

	int result=dialog->run();
	dialog->close();

	while(Main::events_pending())
	{
		Main::iteration();
	}
	delete dialog;
	delete label;

	if(result == 1)
	{
		Dialogs::gettingMenu("Pick from the following menu: ", "Roonie's Delivery services");
	}
	else
	{
		exit(1);
	}

}

string Dialogs:: pickingItem1()
{

	Dialog *dialog=new Dialog();
	dialog->set_title("Orders");
	Label *label=new Label("\t\tPick: \nTofu\tSteak\tChicken");	 // items to pick
	dialog->get_content_area()->pack_start(*label);
	label->show();

	dialog->add_button("OK",1);
	dialog->add_button("Cancel",0);

	Entry *entry = new Entry();
	entry -> set_text("");
	entry -> set_max_length(60);
	entry -> show();
	dialog -> get_vbox()->pack_start(*entry);

	int result=dialog->run();
	string text =  entry-> get_text();
	myOrders.append("2.\t"+text+"\n");
	dialog->close();
	if (text == "none" )
	{
		charge +=0.0;
	}
	else
	{
		charge += 3.25;
	}

	while(Main::events_pending())
	{
		Main::iteration();
	}
	delete dialog;
	delete label;
	delete entry;

	if(result==1)
	{
		Dialogs:: pickingItem2();
	}
	else
	{
		exit(1);
	}
}

string Dialogs:: pickingItem2()
{

	Dialog *dialog=new Dialog();
	dialog->set_title("Orders");
	Label *label=new Label("\t\tPick:\n Cilantro-Lime Brown\n Cilantro-Lime White");	// items to pick
	dialog->get_content_area()->pack_start(*label);
	label->show();

	dialog->add_button("OK",1);
	dialog->add_button("Cancel",0);

	Entry *entry = new Entry();
	entry -> set_text("");
	entry -> set_max_length(60);
	entry -> show();
	dialog -> get_vbox()->pack_start(*entry);

	int result=dialog->run();
	string text =  entry-> get_text();
	myOrders.append("3.\t"+text+"\n");
	dialog->close();

	while(Main::events_pending())
	{
		Main::iteration();
	}
	if (text == "none")
	{
		charge +=0.0;
	}
	else
	{
		charge += 1.25;
	}
	delete dialog;
	delete label;
	delete entry;

	if(result==1)
	{
		Dialogs:: pickingItem3();
	}
	else
	{
		exit(1);
	}
}
string Dialogs:: pickingItem3()
{

	Dialog *dialog=new Dialog();
	dialog->set_title("Orders");
	Label *label=new Label("\t\t\tPick: \nQueso, Sour Cream, Fresh Tomato Salsa");	// items to pick
	dialog->get_content_area()->pack_start(*label);
	label->show();

	dialog->add_button("OK",1);
	dialog->add_button("Cancel",0);

	Entry *entry = new Entry();
	entry -> set_text("");
	entry -> set_max_length(60);
	entry -> show();
	dialog -> get_vbox()->pack_start(*entry);

	int result=dialog->run();
	string text =  entry-> get_text();
	myOrders.append("4.\t"+text+"\n");
	dialog->close();

	while(Main::events_pending())
	{
		Main::iteration();
	}
	if (text == "none")
	{
		charge +=0.0;
	}
	else
	{
		charge += 0.75;
	}
	delete dialog;
	delete label;
	delete entry;

	if(result==1)
	{
		Orders :: printingOrder();
	}
	else
	{
		exit(1);
	}
}
void Orders::printingOrder()
{
	Dialog *dialog = new Dialog();
	dialog -> set_title("Total orders so far");
	Label *label = new Label(myOrders);

	dialog -> get_content_area()->pack_start(*label);
	Label *label1 = new Label("Confirm order( Order or Cancel)?");
	dialog -> get_content_area()->pack_start(*label1);

	label ->show();
	label1->show();
	dialog -> add_button("Order", 0);
	dialog->add_button("Cancel", 1);

	int result= dialog->run();

	dialog-> close();

	while(Main:: events_pending())
		Main::iteration();

	delete dialog;
	delete label;
	delete label1;

	if(result == 0)
	{
		Orders::message();
	}
	else
	{
		exit(0);
	}

}
void Orders::message()
{

	Dialog *dialog = new Dialog();
	dialog -> set_title("Total orders so far");

	Label *label = new Label("");
	dialog -> get_content_area()->pack_start(*label);
	Label *label1 = new Label(printingName().append( " will be delivering your order \n Thank you."));

	dialog -> get_content_area()->pack_start(*label1);

	label ->show();
	label1->show();
	dialog -> add_button("Main menu", 0);
	dialog->add_button("Exit", 1);

	int result= dialog->run();

	dialog-> close();

	while(Main:: events_pending())
		Main::iteration();

	delete dialog;
	delete label;
	delete label1;

	if(result == 0)
	{
		Dialogs::gettingMenu("Pick from the following Menu: ", "Roonie's Delivery Service");
	}
	else
	{
	 	exit(1);
	}
}
