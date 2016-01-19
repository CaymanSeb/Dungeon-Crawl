# Dungeon-Crawl

#include "stdafx.h"
#include "dungeon_crawl.h"
#include <iostream>

using namespace std;


Item::Item(string name_of_item, float item_weight) {

	name = name_of_item;
	weight = item_weight;
}

///Brauche Ich einen Destruktor immer? Oder Ist dies in diesem Spiel nicht nötig?

Item::~Item() {
	
	cout << "Item verloren!" << endl;
}

/// Ist das richtig in der Methode eine andere Header aufzurufen?
void Item::item_spawn() {

	room.addItem();
}

void Item::take_item() {

	if (weight <= max_weight) {
		creature.addItem();
	}
	else {
		cout << "The Item is to heavy, you can't take it!" << endl
	}
}

Creature::Creature(string name, float max_weight, vector<Item> carried_items, Attributes attribs, room_location current_location) {
	
	current_location = location;
}

Creature::Creature() {

	cout << name << "died...!" << endl;
}

void Creature::set_room_location(room_location current_location) {

	current_location = 0.0;
}

void Creature::creature_spawn() {

	room.addCreature();
}
