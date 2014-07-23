# Hikari::Engine README #
## Wst�p

Hikari::Engine to silnik graficzny stworzony nie po to, aby przerosn�� inne silniki graficzne, ale aby da� zar�wno nam, jak i potencjalnym u�ytkownikom wgl�d w budow� takiego oprogramowania. Kod jest zorientowany obiektowo oraz korzysta z mo�liwo�ci wersji 11 j�zyka C++, a dzi�ki wykorzystaniu bibliotek Assimp oraz ResIL pozwala na import wi�kszo�ci format�w modeli 3D oraz wi�kszo�ci format�w obraz�w. Dodatkowymi atutami s� tak�e w�asna biblioteka graficznego interfejsu u�ytkownika (GUI) oraz wykorzystanie silnika fizyki Bullet Physics.

## Podstawy

Podstawow� przestrzeni� nazw jest Hikari::, jednak wewn�trz - celem lepszej organizacji komponent�w - wydzielone zosta�y dodatkowe przestrzenie nazw, kt�re odpowiadaj� strukturze katalog�w (zar�wno w kwestii plik�w �r�d�owych jak i nag��wkowych).
Wewn�trzne przestrzenie nazw zosta�y wymienione poni�ej.

Nazwa             | Opis
------------------|--------------------------------------------------------
Hikari::Objects:: | Zawiera wszystkie obiekty dziedzicz�ce z Hikari::Object

~~~~~~~~{.cpp}
// test
Hikari::Engine::run();
~~~~~~~~