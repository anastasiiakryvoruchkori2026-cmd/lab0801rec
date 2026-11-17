#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../lab0801rec/lab0801.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest0801
{
	TEST_CLASS(UnitTest0801)
	{
	public:
		
		
		TEST_METHOD(TestMethod1)
		{
			bool t;

			char s1[] = "abc n1o def";
			t = includeNO(s1, 1);
			Assert::AreEqual(true, t);

			char s2[] = "hello world";
			t = includeNO(s2, 1);
			Assert::AreEqual(false, t);
		}
	};
}
