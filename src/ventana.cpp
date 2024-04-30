#include<iostream>
#include<string>
#include<ftxui/component/component.hpp>
#include<ftxui/component/screen_interactive.hpp>
#include<thread>
#include<Dibujo.hpp>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    Dibujo palabra1("Hola",0,0);
    Dibujo palabra2("Adios",5,0);

    auto Pantalla = Screen::Create(Dimension::Full(), Dimension::Full());

    while (true)
    {

        this_thread::sleep_for(0.1s);
       
        palabra1.Dibujar(Pantalla);
        palabra2.Dibujar(Pantalla);

        Pantalla.Print();
        Pantalla.Clear();
        cout << Pantalla.ResetPosition();

    }

    return 0;
}
