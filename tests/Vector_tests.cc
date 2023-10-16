#include <gtest/gtest.h>

#include <Vector\Vector.h>

TEST(VectorTests, MethodsTest) {

    std::complex<double> z2(0.34000000000001, 3.2);
    std::complex<double> z1(0.34, 3.2);
    Vector<complex<double>> v1(1, z1);
    Vector<complex<double>> v2(1, z2);

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