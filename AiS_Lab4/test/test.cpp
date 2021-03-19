#include "gtest.h"
#include "Polynom.h"

TEST(Polynom, can_create_polynom) {
	ASSERT_NO_THROW (Polynom p);
}

TEST(Polynom, can_create_polynom_with_int_coef) {
	ASSERT_NO_THROW(Polynom p("5"));
}

TEST(Polynom, can_create_hard_polynom_with_int) {
	ASSERT_NO_THROW(Polynom p("6x5y2z5-5x4y3z3+7x7y5z"));
}

TEST(Polynom, can_create_polynom_with_zero) {
	ASSERT_NO_THROW(Polynom p("0"));
}

TEST(Polynom, can_create_polynom_with_double_coef) {
	ASSERT_NO_THROW(Polynom p("7.0"));
}

TEST(Polynom, can_create_hard_polynom_with_double) {
	ASSERT_NO_THROW(Polynom p("6.0x5y2z5-5.9x4y3z3+7.3x7y5z"));
}

TEST(Polynom, can_copy_polynom) {
	Polynom p1("2x");
	Polynom p2;
	ASSERT_NO_THROW(p2 = p1);
}

TEST(Polynom, can_get_result_with_int) {
	Polynom p1("6x5y2z5-5x4y3z3+7x7y5z");
	ASSERT_NO_THROW(p1.result(1,1,1));
}

TEST(Polynom, can_get_result_with_double) {
	Polynom p1("6x5y2z5-5x4y3z3+7x7y5z");
	ASSERT_NO_THROW(p1.result(1.0, 1.0, 1.0));
}

TEST(Polynom, can_get_sum_polynoms) {
	Polynom p1("6x5y2z5");
	Polynom p2("7x7y5z");
	ASSERT_NO_THROW(p1 + p2);
}

TEST(Polynom, can_get_sum_polynoms_with_result_int) {
	Polynom p1("6x5y2z5");
	Polynom p2("7x7y5z");
	Polynom p3 = p1 + p2;
	EXPECT_EQ(p3.result(1, 1, 1), 13);
}

TEST(Polynom, can_get_sum_polynoms_with_result_double) {
	Polynom p1("6x");
	Polynom p2("8x2");
	Polynom p3 = p1 + p2;
	EXPECT_EQ(p3.result(0.5, 0.5, 0.5), 5);
}

TEST(Polynom, can_compare_polynoms_true) {
	Polynom p1("5x4y3z3");
	Polynom p2("5x4y3z3");
	ASSERT_TRUE(p1 == p2);
}

TEST(Polynom, can_compare_polynoms_false) {
	Polynom p1("6x5y2z5");
	Polynom p2("7x7y5z");
	ASSERT_FALSE(p1 == p2);
}

TEST(Polynom, can_copy_polynom_const) {
	Polynom p1("6x5y2z5");
	ASSERT_NO_THROW(Polynom p2(p1));
}

TEST(Polynom, can_get_sub_polynoms) {
	Polynom p1("6x5y2z5");
	Polynom p2("7x7y5z");
	ASSERT_NO_THROW(p1 - p2);
}

TEST(Polynom, can_get_sub_polynoms_with_result_int) {
	Polynom p1("6x5y2z5");
	Polynom p2("7x7y5z");
	Polynom p3 = p1 - p2;
	EXPECT_EQ(p3.result(1, 1, 1), -1);
}

TEST(Polynom, can_get_sub_polynoms_with_result_double) {
	Polynom p1("6x");
	Polynom p2("8x2");
	Polynom p3 = p1 - p2;
	EXPECT_EQ(p3.result(0.5, 0.5, 0.5), 1);
}

TEST(Polynom, can_multiply_polinoms) {
	Polynom p1("6x5y2z5");
	Polynom p2("7x7y5z");
	ASSERT_NO_THROW(p1 * p2);
}

TEST(Polynom, can_multiply_polinoms_with_result_int) {
	Polynom p1("6x5y2z5");
	Polynom p2("7x7y5z");
	Polynom p3 = p1 * p2;
	EXPECT_EQ(p3.result(1, 1, 1), 42);
}

TEST(Polynom, can_multiply_polinoms_with_result_double) {
	Polynom p1("6x");
	Polynom p2("8x3");
	Polynom p3 = p1 * p2;
	EXPECT_EQ(p3.result(0.5, 0.5, 0.5), 3);
}

TEST(Polynom, hard_operations) {
	Polynom p1("3x5y2z5-5x4y3z3+7x3y5z");
	Polynom p2("4x3y2z6-6x2yz8");
	Polynom p3 = p1 + p2;
	EXPECT_EQ(p3.result(10, 20, 5), p1.result(10, 20, 5)+p2.result(10, 20, 5));
}

TEST(Polynom, hard_operations_double) {
	Polynom p1("3x5y2z5-5x4y3z3+7x3y5z");
	Polynom p2("4x3y2z6-6x2yz8");
	Polynom p3 = p1 + p2;
	EXPECT_EQ(p3.result(10.1, 20.3, 5.1), p1.result(10.1, 20.3, 5.1) + p2.result(10.1, 20.3, 5.1));
}

TEST(Polynom, can_add_monom) {
	Polynom p1("3x5y2z5-5x4y3z3+7x3y5z");
	Monom m(2.1, 3);
	ASSERT_NO_THROW(p1.add(m));
}

TEST(Polynom, very_hard_operations) {
	Polynom p1("3x5y2z5-5x4y3z3+7x3y5z");
	Polynom p2("4x3y2z6-6x2yz8");
	Polynom p3("8x3");
	ASSERT_NO_THROW(p1+p2*p3);
}