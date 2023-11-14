#include <gtest/gtest.h>

#include <D:\Lab1-AISD-Zabirov-6213\src\Vector.cc>

TEST(ConstructorRandom, MethodTests) {
    int i_min = -500, i_max = 500;
    double d_min = -500, d_max = 500;
    float f_min = -500, f_max = 500;
    std::complex<double> zd_min(-500, -500), zd_max(500, 500);
    std::complex<float> zf_min(-500, -500), zf_max(500, 500);
    Vector<int> Vi(5, i_min, i_max);
    Vector<double> Vd(5, d_min, d_max);
    Vector<float> Vf(5, f_min, f_max);
    Vector<complex<double>> Vcd(5, zd_min, zd_max);
    Vector<complex<float>> Vcf(5, zf_min, zf_max);
}





TEST(VectorTestsComplexDouble, MethodsTest) {
    std::complex<double> z1(0.34, 3.2);
    std::complex<double> z2(0.340000001, 3.2);
    std::complex<double> z3(0.25, 133.4);
    Vector<complex<double>> v1(1, z1);
    Vector<complex<double>> v2(1, z2);
    Vector<complex<double>> v3(v1);
    std::complex<double> z4(1, 0);
    Vector<complex<double>> v4(1, z4);
    cout << v4 + v1 << endl;
    v3.push_back(z3);
    cout << v1 <<endl;
    cout << v2 << endl;
    cout << v3 << endl;
    v3[1] = std::complex<double>(15, 0.15);
    cout << v3;
    std::complex<double> ans(0.68, 6.4);
    Vector<complex<double>> answer(1, ans);
    EXPECT_TRUE(v1 + v2 == answer);
    ans = std::complex<double>(0.0);
    answer[0] = ans;
    EXPECT_TRUE(v1 - v2 == answer);
}


TEST(VectorTestsComplexFloat, MethodsTest) {
    std::complex<float> z1(0.34, 3.2);
    std::complex<float> z2(0.340000001, 3.2);
    std::complex<float> z3(0.25, 133.4);
    Vector<complex<float>> v1(1, z1);
    Vector<complex<float>> v2(1, z2);
    Vector<complex<float>> v3(v1);
    v3.push_back(z3);
    cout << v1;
    cout << v2;
    EXPECT_TRUE(v1 == v2);
}

TEST(VectorTestsDouble, MethodsTest) {
    double d1 = 13.5;
    int i1 = 5;
    Vector<double> vd(1, d1);
    Vector<int> vi(1, i1);
    vi.push_back(25);
    vd.push_back(25);
    cout << vi;
}

TEST(VectorTestsRand, MethodsTest) {
    double max = 13.5;
    double low = 5;
    complex<double> max_com(max, max);
    complex<double> low_com(low, low);
    Vector<double> vd(10, low, max);
    Vector<complex<double>> vcomd(10, low_com, max_com);
    cout <<"random complex<double> vector" << vcomd << endl;
    cout << "random double vector:" << vd;
}

TEST(VectorTestsMath, MethodsTest) {
    std::complex<float> z1(0.34, 3.2);
    std::complex<float> z3(2, 2);
    Vector<complex<float>> v1(1, z1);
    Vector<complex<float>> v3(v1);
    cout << z3 * v3;
    
}

TEST(VectorTask, FuncTest) {
    int i1 = 0, i2 = 4, i3 = 6, i4 = 8;
    Vector<int> v(3, i1, i4);
    find_orthogonal(v);
    cout << v << endl;
    cout << "Just ortogona: " << find_orthogonal(v) << endl;
    cout << "Ortonorm: " << find_ortonarmal(v) << endl;
}

TEST(VectorTask2, FuncTest) {
    std::complex<double> z(4, 2256);
    std::complex<double> z1(0.34, 3.2);
    std::complex<double> z2(0.340000001, 3.2);
    std::complex<double> z3(2.5, 133.4);
    Vector<complex<double>> v(4,  z2, z3);
    cout << "First vector:" << v << endl;
    cout << "Just ortogona: " << find_orthogonal(v) << endl;
    cout << "Ortonorm: " << find_ortonarmal(v) << endl;
}
