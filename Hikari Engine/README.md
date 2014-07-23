# Hikari::Engine README #
## Wstêp

Hikari::Engine to silnik graficzny stworzony nie po to, aby przerosn¹æ inne silniki graficzne, ale aby daæ zarówno nam, jak i potencjalnym u¿ytkownikom wgl¹d w budowê takiego oprogramowania. Kod jest zorientowany obiektowo oraz korzysta z mo¿liwoœci wersji 11 jêzyka C++, a dziêki wykorzystaniu bibliotek Assimp oraz ResIL pozwala na import wiêkszoœci formatów modeli 3D oraz wiêkszoœci formatów obrazów. Dodatkowymi atutami s¹ tak¿e w³asna biblioteka graficznego interfejsu u¿ytkownika (GUI) oraz wykorzystanie silnika fizyki Bullet Physics.

## Podstawy

Podstawow¹ przestrzeni¹ nazw jest Hikari::, jednak wewn¹trz - celem lepszej organizacji komponentów - wydzielone zosta³y dodatkowe przestrzenie nazw, które odpowiadaj¹ strukturze katalogów (zarówno w kwestii plików Ÿród³owych jak i nag³ówkowych).
Wewnêtrzne przestrzenie nazw zosta³y wymienione poni¿ej.

Nazwa             | Opis
------------------|--------------------------------------------------------
Hikari::Objects:: | Zawiera wszystkie obiekty dziedzicz¹ce z Hikari::Object

~~~~~~~~{.cpp}
// test
Hikari::Engine::run();
~~~~~~~~