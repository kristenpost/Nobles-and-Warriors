#pragma once
#include "Protector.h"
#include <string>
#include <vector>
#ifndef NOBLE_H
#define NOBLE_H

using namespace std;

// Noble - BASE Class

namespace WarriorCraft {

	class Protector;

	class Noble {

	public:
		Noble(const string& name, int given_strength);
		void battle(Noble& noble2);
		bool alive();
		const string& getNname() const;
		virtual int getStrength() const;
		virtual void updateStrength(int new_strength);
		virtual void defend() const = 0;
	protected:
	private:
		string name;
		int strength;
		bool is_alive = true;
	};

	// PersonWithStrength - DERIVED class from Noble (Note: Will not need to hire an army of protectors)
	class PersonWithStrengthToFight : public Noble {
	public:
		PersonWithStrengthToFight(const string& given_name, int given_strength);
		void defend() const;
	protected:
	private:
	};

	// Lord - DERIVED class from Noble (Note: Will need to hire an army of protectors)
	class Lord : public Noble {
	public:
		Lord(const string& given_name);
		bool hires(Protector& potential_hire);
		bool fire(Protector& employee2fire);
		// Get Strength method (sum of all current employees strengths)
		int getStrength() const;
		void updateStrength(int new_strength);
		void defend() const;
	protected:
	private:
		vector<Protector*> army;
	};
}

#endif

