bin/space : src/main.cpp
	g++ src/main.cpp -o bin/space -std=c++2a -lftxui-screen -lftxui-component -lftxui-dom

run : bin/space
	./bin/space

hola :
	echo Hola mundo

receta2:
	echo receta