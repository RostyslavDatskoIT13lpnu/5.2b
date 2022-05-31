#include "pch.h"
#include "CppUnitTest.h"
#include "../5.2b/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student s;
			s.math = 5;
			s.physics = 5;
			s.progr = 5;
			Assert::AreEqual(check(s), true);

		}
	};
}
