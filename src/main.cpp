#include <iostream>
#include <string.h>
#include <thread>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    Element lienzo = hbox({
        spinner(21,2) | bold
    });

    Screen pantalla = Screen :: Create(
        Dimension::Full(), 
        Dimension::Full()
    );
    
    Render(pantalla,lienzo);
    pantalla.ResetPosition();
    pantalla.Print();

    this_thread::sleep_for(0.1s);

    return 0;
}
