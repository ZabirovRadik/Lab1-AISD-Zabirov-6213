#include <gtest/gtest.h>

#include <Account/Account.h>

TEST(AccountWorkTest, AllTest) {
    setlocale(LC_ALL, "Russian");
    TT::Credit Man3("Neizvestniy Diad Pihto", -30506, 10);
    TT::Credit Man = TT::Credit::Credit();
    auto p = Man3.clone();
    string gg = "Rrrrrrrrrrrrttttttttttttttttttttttttttttttrrr";
    Man3.set_name(gg);
    EXPECT_TRUE(Man3.get_name() == "Rrrrrrrrrrrrttttttttttttttttttttttttttttttrrr");
    Man3.set_money(5993.4);
    EXPECT_TRUE(Man3.get_money() == 5993.4);
}


TEST(PercentTests, Accrual_of_interestTest1) {
    // Arrange
    TT::Settlement Man1("Korolev Pavel Sergeevich", 43000);
    TT::Deposit Man2("Chelovechniy Chelovek Chelovechovich", 100000, 5);
    TT::Credit Man3("Neizvestniy Diad Pihto", -30506, 10);
    TT::Credit Man4("Nvestniy Dd Pto", 30506, 10);

    // Act
    Man1.Accrual_of_interest();
    Man2.Accrual_of_interest();
    Man3.Accrual_of_interest();
    Man4.Accrual_of_interest();
    // Assert

    EXPECT_EQ(Man1.get_money(), 43000);
    EXPECT_FLOAT_EQ(Man2.get_money(), 141666.66666666666);
    EXPECT_FLOAT_EQ(Man3.get_money(), -55927.666666666672);
    EXPECT_FLOAT_EQ(Man4.get_money(), 30506);

}

TEST(PrintAccount, Account) {
    setlocale(LC_ALL, "Russian");
    TT::Settlement Man1("Korolev Pavel Sergeevich", 43000);
    TT::Deposit Man2("Chelovechniy Chelovek Chelovechovich", 100000, 5);
    TT::Credit Man3("Neizvestniy Diad Pihto", -30506, 10);
    TT::Credit Man4("Nvestniy Dd Pto", 30506, 10);

    Man1.Print();
    Man2.Print();
    Man3.Print();
    Man4.Print();
}

TEST(NEW_List, In_ListAcc) {
    TT::ListAcc check;
    TT::Credit Man3("Neizvestniy Diad Pihto", -30506, 10);
    check.add(make_shared<TT::Deposit>(Man3), 0);
}

TEST(AccountListTests, AccListCtorAndOPCpyTest) {
    TT::ListAcc EL = TT::ListAcc::ListAcc();
    TT::ListAcc EL2(EL);
    TT::ListAcc EL3 = EL;
    EXPECT_EQ(EL, EL2);
    EXPECT_EQ(EL, EL3);
}


TEST(AccListTests, AddDelTests1) {
    // Arrange
    TT::ListAcc check;
    TT::Deposit  Man1("Chelovechniy Chelovek Chelovechovich", 100000, 5);
    check.add(make_shared<TT::Deposit>(Man1));
    check.add(make_shared<TT::Deposit>(Man1),1);
    check.Del(0);
}

TEST(AccListTests, AddDelTests2) {
    // Arrange
    TT::ListAcc check;
    TT::Credit  Man1("Chelovechniy Chelovek Chelovechovich", 100000, 5);
    check.add(make_shared<TT::Credit>(Man1));
    check.add(make_shared<TT::Credit>(Man1), 1);
    check.Del(0);
}

TEST(AccListTests, AddDelTests3) {
    // Arrange
    TT::ListAcc check;
    TT::Deposit  Man1("Chelovechniy Chelovek Chelovechovich", 100000, 5);
    check.add(make_shared<TT::Deposit>(Man1));
    check.add(make_shared<TT::Deposit>(Man1), 1);
    check.Del(0);
}
/*
TEST(AccListTests, MethodsTest) {
    // Arrange
    TT::ListAcc check;
    TT::Deposit Man1("Chelovechniy Chelovek Chelovechovich", 100000, 5);
    check.add(make_shared<TT::Deposit>(Man1));

    check[0]->Accrual_of_interest();
    EXPECT_FLOAT_EQ(check[0]->get_money(), 141666.66666666666);
    check.Del(0);
    EXPECT_TRUE(check.size() == 0);
}

TEST(AccListTests, FirstRichTest1) {
    // Arrange
    TT::ListAcc check;
    TT::Deposit  Man1("Chelovechniy Chelovek Chelovechovich", 100000, 5);
    TT::Settlement Man2("Korolev Pavel Sergeevich", 43000);
    TT::Credit Man3("Neizvestniy Diad Pihto", -30506, 10);
    check.add(make_shared<TT::Deposit>(Man1));
    check.add(make_shared < TT::Settlement>(Man2));
    check.add(make_shared < TT::Credit>(Man3));
    TT::Settlement Man4("Mavrodiy Jake Larsen", 39400);
    check.add(make_shared < TT::Settlement>(Man4));
    TT::Settlement Man5("Zabirov Radik Rinatovich", 1000001);
    check.add(make_shared < TT::Settlement>(Man5));

    // Act                                                    
    // Act
    bool r = false;
    if (check.First_Rich() == 0) r = true;

    // Assert

    EXPECT_FALSE(r);
}


TEST(AccListTests, FirstRichTest2) {
    // Arrange
    TT::ListAcc check;
    TT::Deposit  Man1("Chelovechniy Chelovek Chelovechovich", 100000, 5);
    TT::Settlement Man2("Korolev Pavel Sergeevich", 43000);
    TT::Credit Man3("Neizvestniy Diad Pihto", -30506, 10);
    check.add(make_shared < TT::Deposit>(Man1), 0);
    check.add(make_shared < TT::Settlement>(Man2), 1);
    check.add(make_shared < TT::Credit>(Man3), 2);
    TT::Settlement Man4("Mavrodiy Jake Larsen", 39400);
    check.add(make_shared < TT::Settlement>(Man4), 3);
    TT::Settlement Man5("Zabirov Radik Rinatovich", 1000001);
    check.add(make_shared < TT::Settlement>(Man5), 4);

    // Act
    bool r = false;
    if (check.First_Rich() == 4) r = true;

    // Assert

    EXPECT_TRUE(r);
}


TEST(AccListTests, FirstRichTest3) {
    // Arrange
    TT::ListAcc check;
    TT::Deposit Girl1("Ufhkbek Ifnjken Wdhfbh", 100000, 5);
    TT::Settlement Girl2("Wnjkv Parvew Sdjkksn", 430000);
    TT::Credit Girl3("Udpok Esjdvn Pdksvn", -30506, 10);
    check.add(make_shared < TT::Deposit>(Girl1));
    check.add(make_shared < TT::Settlement>(Girl2), 1);
    check.add(make_shared < TT::Credit>(Girl3), 2);
    TT::Deposit Girl4("Yvsdlvmk Ovdlv Tlfwmkvc", 430000, 56);
    check.add(make_shared < TT::Deposit>(Girl4), 3);
    TT::Settlement Girl5("Iveuhnk Yvkjn Rdjvlm", 1000);
    check.add(make_shared < TT::Settlement>(Girl5), 4);
    check.Del(1);
    // Act
    bool r = false;
    if (check.First_Rich() == 2) r = true;
    // Assert

    EXPECT_TRUE(r);
}
*/