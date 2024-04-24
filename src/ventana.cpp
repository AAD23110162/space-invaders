#include<iostream>
#include<string>
#include<ftxui/component/component.hpp>
#include<ftxui/component/screen_interactive.hpp>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    string prueba = "DVD";
    int posicionX = 0;
    int posicionY = 0;

    while (true)
    {
        posicionY++;
        this_thread::sleep_for(0.1s);

        auto Pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Render(Pantalla, border(text("hola")));
        Pantalla.PixelAt(5, 5).character = 'm';

        for (auto &&letra : prueba)
        {
            Pantalla.PixelAt(posicionX, posicionY).character = letra;
            posicionX++;
        }

        Pantalla.Print();
        cout << Pantalla.ResetPosition();
    }

    return 0;
}
