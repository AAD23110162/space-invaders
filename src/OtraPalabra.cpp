#include<iostream>
#include<string>
#include<ftxui/component/component.hpp>
#include<ftxui/component/screen_interactive.hpp>
#include<thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    string palabra1 = "DVD";
    string palabra2 = "Alejandro";

    int posicionInicialX1 = 0;
    int posicionInicialY1 = 0;

    int posicionInicialX2 = 10;
    int posicionInicialY2 = 0;

    auto Pantalla = Screen::Create(Dimension::Full(), Dimension::Full());

    while (true)
    {

        this_thread::sleep_for(0.1s);
        int posicionPalabraX1=0;
        int posicionPalabraY1=0;

        int posicionPalabraX2=10;
        int posicionPalabraY2=0;
        
        for (auto &&letra : palabra1)
        {
            int posicionFinalX1=posicionInicialX1+posicionPalabraX1;
            int posicionFinalY1=posicionInicialY1+posicionPalabraY1;
            Pantalla.PixelAt(posicionFinalX1, posicionFinalY1).character = letra;
            posicionPalabraX1++;
        }

        for (auto &&letra : palabra2)
        {
            int posicionFinalX2=posicionInicialX2+posicionPalabraX2;
            int posicionFinalY2=posicionInicialY2+posicionPalabraY2;
            Pantalla.PixelAt(posicionFinalX2, posicionFinalY2).character = letra;
            posicionPalabraX2++;
        }

        Pantalla.Print();
        Pantalla.Clear();
        cout << Pantalla.ResetPosition();

        posicionInicialX1++;
        posicionInicialY1++;
        posicionInicialX2++;
        posicionInicialY2++;
    }

    return 0;
}
