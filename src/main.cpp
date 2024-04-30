#include <iostream>
#include <string.h>
#include <thread>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
#include <ftxui/screen/terminal.hpp>
#include <fstream>
#include <Archivo.hpp>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    Archivo dTanque("./assets/images/canon.txt");
    Archivo dAlien("./assets/images/alien.txt");
   
    int fotograma=0;
    while(true)
    {
        fotograma++;
        Element personaje = spinner(21,fotograma) | bold|color(Color::Yellow)|bgcolor(Color::Green1);
        Element tanque = dTanque.GetElement() | bold|color(Color::Green)|bgcolor(Color::Blue);
        Element lienzo = hbox({personaje,tanque, dAlien.GetElement()});
        
        Screen pantalla = Screen :: Create(
            Dimension::Full(), 
            Dimension::Full());

        Render(pantalla,lienzo);
        pantalla.Print();
        cout<<pantalla.ResetPosition();
        
        this_thread::sleep_for(0.1s);
    }
    return 0;
}
