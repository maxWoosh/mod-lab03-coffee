// Copyright 2022 UNN-IASR
#include "Automata.h"

int main() {
    Automata vendingMachine;
    vendingMachine.on();
    vendingMachine.getMenu();
    vendingMachine.coin(100);
    vendingMachine.choice(2);
    vendingMachine.off();

    return 0;
}
