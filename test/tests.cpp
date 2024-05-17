// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <gtest/gtest.h>

class ATest : public ::testing::Test {
protected:
    Automata vendingMachine;

    void SetUp() override {
        vendingMachine.on();
    }
};

TEST(ATest, IsInitiallyOff) {
    Automata newAutomata;
    EXPECT_EQ(newAutomata.getState(), STATES::OFF);
}

TEST(Atest, TurnsOn) {
    EXPECT_EQ(vendingMachine.getState(), STATES::WAIT);
}

TEST(Atest, AcceptsCoins) {
    vendingMachine.coin(50);
    EXPECT_EQ(vendingMachine.getState(), STATES::ACCEPT);
}

TEST(Atest, CanReadMenu) {
    EXPECT_NO_THROW(vendingMachine.getMenu());
}

TEST(Atest, MakesSelection) {
    vendingMachine.coin(200);
    vendingMachine.choice(2);
    EXPECT_EQ(vendingMachine.getState(), STATES::WAIT);
}

TEST(Atest, ChecksSufficientFunds) {
    vendingMachine.coin(10);
    EXPECT_FALSE(vendingMachine.check(1));
}

TEST(Atest, CancelsTransaction) {
    vendingMachine.coin(100);
    vendingMachine.cancel();
    EXPECT_EQ(vendingMachine.getState(), STATES::WAIT);
}

TEST(Atest, CooksDrink) {
    vendingMachine.coin(200);
    vendingMachine.choice(1);
    EXPECT_EQ(vendingMachine.getState(), STATES::WAIT);
}

TEST(Atest, FinishesTransaction) {
    vendingMachine.coin(200);
    vendingMachine.choice(1);
    EXPECT_EQ(vendingMachine.getState(), STATES::WAIT);
}

TEST(Atest, DoesNotCookWithoutFunds) {
    vendingMachine.choice(1);
    EXPECT_NE(vendingMachine.getState(), STATES::COOK);
}
