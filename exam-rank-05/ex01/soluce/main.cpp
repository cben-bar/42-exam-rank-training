#include "Warlock.cpp"
#include "ASpell.cpp"
#include "ATarget.cpp"
#include "Dummy.cpp"
#include "Fwoosh.cpp"

int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
}