// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
//
// Celem zadania jest rozszerzenie jego wersji podstawowej, polimorficznej listy:
//   https://upel.agh.edu.pl/mod/assign/view.php?id=136110
//   Rozszerzenie obejmuje:
//   - Definicję szablonu klasy Pair (typu aggregate, patrz niżej), której zadaniem
//     jest jedynie przechowywanie dwóch danych numertycznych. Klasa ta musi zawierać
//     słownik dedukcji typów CTAD (z założenia)
//   - Definicję szablonu klasy Complex dziedziczącym po klasie Pair
//     z odpowiednią funkcjonalnością (patrz main) oraz słownikiem dedukcji typów CTAD.
//     Uwaga: klasa Complex nie zawiera własnych atrybutów! Wykorzystuje to co dziedziczy!
//   - modyfikację definicji klasy List (jeśli konieczne) tak aby kolejne 
//     instancje TNode tworzone były bez podawania argumentów szablonowych
//
// Pliku main.cpp, nie wolno modyfikowac.
//
// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny 
// i dobrze napisany kod), oraz powinna być spełniona zasada D.R.Y. 
// - Don't Repeat Yourself.
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i main.cpp 
// należy wgrać do UPEL jako archiwum tar.gz, 
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab11/
// * archiwum nie powinno zawierać katalogu build/

/* 
  What are aggregates and why they are special?
  https://stackoverflow.com/questions/4178175/what-are-aggregates-and-pods-and-how-why-are-they-special
  Formal definition from the C++ standard (C++03 8.5.1 §1):
    "An aggregate is an array or a class (clause 9) with no user-declared constructors (12.1), 
    no private or protected non-static data members (clause 11), no base classes (clause 10), 
    and no virtual functions (10.3)."
    template<class T,class U> class AggregateExample {
      public:
        T first;
        U second;
    };
*/

#include <iostream>
#include "Complex.h"
#include "List.h"

int main() {
  Pair<int,int> p0{3,1};
  std::cout << p0 << std::endl;

  Pair p1{3,1.3};
  std::cout << p1 << std::endl;

  Complex<int,int> c0{3,1};   // Complex jest "aggregate", 
                              // czyli struct bez zdefiniowanych konstruktorów!
                              // Dokładniej, w tym przypadku szablonem struktury/klasy.
  std::cout << c0 << std::endl;

  Complex c1{5.1,2};      // Ryzyko: CTAD doesn’t know how to deduce 
                          //         the template arguments for aggregate class templates

  auto c2 = c1.Conjugate(); // X + Yi -> X - Yi
  std::cout << c1 << "  " <<c2 << std::endl;
  List list;
  list.add(7);             // Uwaga: domyślne działanie CTAD, nie ma potrzeby dodawania arg. szablonu
  list.add(float(4.566));  // Domyślnie dla typu zmiennoprzecinkowego wybierany jest double
  list.add(c2);
  std::cout<<" is float "<<std::boolalpha<<list.head()->isType<float>()<< std::endl;

  auto c3 = dynamic_cast<const TNode<Complex<float,int>>*>( list.head() );
  c3 ? std::cout<<c3->get() : std::cout<<" cast type error... ";
  std::cout<<std::endl; 

  auto c4 = dynamic_cast<const TNode<Complex<double,int>>*>( list.head() );
  c4 ? std::cout<<c4->get() : std::cout<<" cast type error... ";
  std::cout<<std::endl; 

  
}
/* wynik
3,1
3,1.3
3+1i
5.1+2i  5.1-2i
 is float false
 cast type error...
5.1-2i
 */