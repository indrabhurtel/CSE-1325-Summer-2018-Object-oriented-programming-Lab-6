//Indra Bhurtel

#include "choice.h"
#include <gtkmm.h>


using namespace std;
using namespace Gtk;


int main(int argc, char *argv[])
{
    string selection;

    Main kit(argc, argv);

    Dialogs::gettingMenu("Pick from the following menu: ", "Roonie's Delivery Service");

    return 0;
}
