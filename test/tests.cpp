// Copyright 2022 UNN-IASR
#include <gtest/gtest.h>
#include "Automata.h"

class ATest : public ::testing::Test {
 protected:
    Automata vendingMachine;

    void SetUp() override {
        vendingMachine.on();
    }
};

TEST_F(ATest, 1) {
    Automata newVendingMachine;
    EXPECT_EQ(newVendingMachine.getState(), STATES::OFF);
}

TEST_F(ATest, 2) {
    EXPECT_EQ(vendingMachine.getState(), STATES::WAIT);
}

TEST_F(ATest, 3) {
    vendingMachine.coin(50);
    EXPECT_EQ(vendingMachine.getState(), STATES::ACCEPT);
}

TEST_F(ATest, 4) {
    EXPECT_NO_THROW(vendingMachine.getMenu());
}

TEST_F(ATest, 5) {
    vendingMachine.coin(100);
    vendingMachine.choice(2);
    EXPECT_EQ(vendingMachine.getState(), STATES::WAIT);
}

TEST_F(ATest, 6) {
    vendingMachine.coin(10);
    EXPECT_FALSE(vendingMachine.check(1));
}

TEST_F(ATest, 7) {
    vendingMachine.coin(50);
    vendingMachine.cancel();
    EXPECT_EQ(automata.getState(), STATES::WAIT);
}

TEST_F(ATest, 8) {
    vendingMachine.coin(100);
    vendingMachine.choice(1);
    EXPECT_EQ(vendingMachine.getState(), STATES::WAIT);
}

TEST_F(ATest, 9) {
    vendingMachine.coin(100);
    vendingMachine.choice(1);
    EXPECT_EQ(vendingMachine.getState(), STATES::WAIT);
}

TEST_F(ATest, 10) {
    vendingMachine.choice(1);
    EXPECT_NE(vendingMachine.getState(), STATES::COOK);
}
