#include <iostream>
#include <string>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <Archivo.hpp>
#include <thread>
#include <list>
#include <Dibujo.hpp>
#include <experimental/random>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    Archivo alien("./assets/images/alien.txt");
    list<Dibujo> dibujos;
    for (size_t i = 0; i < 20; i++)
    {
        Dibujo d= alien.CrearDibujo();
        d.EstablecerPosion(
            experimental::randint(0,20),
            experimental::randint(0,20)
        );
        dibujos.push_back(d);
    }
    
    //Crear monitos
    for (int i=0; i<20; i++)
    {
        list<string> c;
        c.push_back("Personaje: " + to_string(i));
        c.push_back("  0  ");
        c.push_back("--|--");
        c.push_back(" / \\");
        Dibujo contenido(c,
            experimental::randint(0,50), //Posicion en X
            experimental::randint(0,50)  //Posicion en Y
            );
        dibujos.push_back(contenido);
    }
    
    auto Pantalla = Screen::Create(Dimension::Full(), Dimension::Full());

    while (true)
    {
        Pantalla.Clear();
        this_thread::sleep_for(0.1s);

        //Actualizar
        for(auto &&i : dibujos)
        {
            i.DesplazarX(experimental::randint(-1,1));
            i.Desplazary(experimental::randint(-1,1));
        }

        //Dibujar       
        for(auto &&i : dibujos)
        {
            i.Dibujar(Pantalla);
        }

        Pantalla.Print();
        cout << Pantalla.ResetPosition();

    }

    return 0;
}
