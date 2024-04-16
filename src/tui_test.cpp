
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>

using namespace ftxui;

int main(int argc, char const *argv[])
{
    //Crea los elementos de la interfaz de usuario
    Element label=text("Hola Mundo");
    Element container=hbox({label});

    //Crea la pantalla
    auto screen=Screen::Create
    (
        Dimension::Full(),
        Dimension::Fit(container)
    );
    Render (screen,container);
    screen.Print();
    /* code */
    return 0;
}
