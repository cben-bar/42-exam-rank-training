#include "Warlock.cpp"
#include "ASpell.cpp"
#include "ATarget.cpp"
#include "Dummy.cpp"
#include "Fwoosh.cpp"
#include "BrickWall.cpp"
#include "Fireball.cpp"
#include "Polymorph.cpp"
#include "SpellBook.cpp"
#include "TargetGenerator.cpp"


int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  richard.introduce();
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);
}