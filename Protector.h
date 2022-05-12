#pragma once
#include "Noble.h"
#include <string>
#include <vector>
#include <iostream>
#ifndef PROTECTOR_H
#define PROTECTOR_H
using namespace std;

// Protectors - BASE Class

namespace WarriorCraft {

	class Noble;

	class Protector {

		friend ostream& operator<<(ostream& os, const Protector& protector);

	public:
		Protector(const string& name, int strength);
		bool is_hired();
		void modify_employement(const string& action, Noble& employer);
		const string& getPname() const;
		const string& getBossname() const;
		int getPstrength() const;
		void modifyStrength(int new_strength);
		virtual void defend() const = 0;
	protected:
	private:
		string protector_name;
		int ind_strength;
		bool assigned = false;
		Noble* boss = nullptr;
	};

	// Wizard - DERIVED class from Protectors
	class Wizard : public Protector {
	public:
		Wizard(const string& name, int strength);
		void defend() const;
	protected:
	private:
	};

	// Warrior - DERIVED class from Protectors
	class Warrior : public Protector {
	public:
		Warrior(const string& name, int strength);
		void defend() const;
	protected:
	private:
	};

	// Archer - DERIVED class from Warrior
	class Archer : public Warrior {
	public:
		Archer(const string& name, int strength);
		void defend() const;
	protected:
	private:
	};

	// Swordsman - DERIVED class from Warrior
	class Swordsman : public Warrior {
	public:
		Swordsman(const string& name, int strength);
		void defend() const;
	protected:
	private:
	};
}

#endif
