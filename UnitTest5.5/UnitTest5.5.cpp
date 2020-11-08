#include "pch.h"
#include "CppUnitTest.h"
#include "../lab5.5/lab5_5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest55
{
	TEST_CLASS(UnitTest55)
	{
	public:
		
		TEST_METHOD(TestMethod5_5)
		{
			int t;
			int x = 100;
			 int y = 100;
			t = multiply(100, 100);
			Assert::AreEqual(t, 10000);
		}
	};
}
