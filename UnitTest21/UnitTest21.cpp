#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.2.it/Lab_07.2.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest21
{
	TEST_CLASS(UnitTest21)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int r0[3] = { 1, 5, 3 };
			int r1[3] = { 2, 8, 4 };
			int r2[3] = { 6, 1, 9 };
			int* mat[3] = { r0, r1, r2 };

			MoveMaxEvenRowsToDiagonal(mat, 3);

			Assert::AreEqual(5, r0[0]);
			Assert::AreEqual(9, r2[2]);
		}
	};
}
