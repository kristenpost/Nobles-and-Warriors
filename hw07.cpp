/* Purpose of Code: To expand the world of Warriors and Nobles by means of inheritance.
 Now, there are two types of Nobles; Lord and PersonWithStrength. Instead of simply having Warriors,
 there will be a Protector class, from which classes Wizards and Warriors will be derived from.  
 Furthermore, there will be two different types of Warriors; derived classes Archer and Swordsmen. */

#include "Protector.h"
#include<string>
#include<vector>
#include<iostream>
#include "Noble.h"
using namespace std;
using namespace WarriorCraft;

int main() {
	Lord sam("Sam");
	Archer samantha("Samantha", 200);
	sam.hires(samantha);
	Lord joe("Joe");
	PersonWithStrengthToFight randy("Randolf the Elder", 250);
	joe.battle(randy);
	joe.battle(sam);
	Lord janet("Janet");
	Swordsman hardy("TuckTuckTheHardy", 100);
	Swordsman stout("TuckTuckTheStout", 80);
	janet.hires(hardy);
	janet.hires(stout);
	PersonWithStrengthToFight barclay("Barclay the Bold", 300);
	janet.battle(barclay);
	janet.hires(samantha);
	Archer pethora("Pethora", 50);
	Archer thora("Thorapleth", 60);
	Wizard merlin("Merlin", 150);
	janet.hires(pethora);
	janet.hires(thora);
	sam.hires(merlin);
	janet.battle(barclay);
	sam.battle(barclay);
	joe.battle(barclay);
}
