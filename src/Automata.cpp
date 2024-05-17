// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <iostream>

Automata::Automata() : cash(0), state(STATES::OFF) {
    menu = { "Tea", "Coffe", "Cacao" };
    price = { 50, 100, 60 };
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        std::cout << "On!" << std::endl;
    }
}

void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
        std::cout << "Off!" << std::endl;
    }
}

void Automata::coin(int Money) {
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        cash += Money;
        state = STATES::ACCEPT;
        std::cout << "Balance: " << cash << std::endl;
    }
}

void Automata::getMenu() {
    std::cout << "Menu:" << std::endl;
    for (size_t i = 0; i < menu.size(); ++i) {
        std::cout << i + 1 << ". ";
        std::cout << menu[i] << " - ";
        std::cout << price[i] << std::endl;
    }
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int Num) {
    if (state == STATES::ACCEPT && Num <= menu.size()) {
        state = STATES::CHECK;
        if (check(Num - 1)) {
            cook(Num - 1);
        } else {
            std::cout << "Not enough money!" << std::endl;
            cancel();
        }
    }
}

bool Automata::check(int Num) {
    return cash >= price[Num];
}

void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::CHECK) {
        std::cout << "Take your money, pls" << cash << std::endl;
        cash = 0;
        state = STATES::WAIT;
    }
}

void Automata::cook(int Num) {
    if (state == STATES::CHECK) {
        std::cout << "Cooking... " << menu[Num] << std::endl;
        cash -= price[Num];
        state = STATES::COOK;
        finish();
    }
}

void Automata::finish() {
    std::cout << "Take your drink pls!" << std::endl;
    state = STATES::WAIT;
}
