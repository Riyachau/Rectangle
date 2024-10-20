#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" {
	int getPerimeter(int* length, int* width);
	int getArea(int* length, int* width);
	void setLength(int input, int* length);
	void setWidth(int input, int* width);
}

namespace RectangleTests
{
	TEST_CLASS(RectangleTests)
	{
	public:
		TEST_METHOD(TestGetPerimeter)
		{
			int length = 10;
			int width = 5;
			int expectedPerimeter = 2 * (length + width);
			int perimeter = getPerimeter(&length, &width);

			Assert::AreEqual(expectedPerimeter, perimeter);
		}

		TEST_METHOD(TestGetArea)
		{
			int length = 5;
			int width = 10;
			int expectedArea = length * width;
			int results = getArea(&length, &width);
			Assert::AreEqual(expectedArea, results);
		}
		// Test cases

		TEST_METHOD(TestSetLength_ValidInput)
		{
			int length = 0;
			setLength(40, &length);
			Assert::AreEqual(40, length); // Normal test case 
		}

		TEST_METHOD(TestSetLength_MinimumValidInput)
		{
			int length = 0;
			setLength(1, &length);
			Assert::AreEqual(1, length); // Test Lower edge case
		}
		TEST_METHOD(TestSetLength_InvalidInput)
		{
			int length = 0;
			setLength(100, &length);
			Assert::AreEqual(0, length); //Invalid input test case
		}

		TEST_METHOD(TestSetWidth_ValidInput)
		{
			int width = 0;
			setWidth(75, &width);
			Assert::AreEqual(0, width); //Normal test case
		}

		TEST_METHOD(TestSetWidth_NegativeInput)
		{
			int width = 0;
			setWidth(-20, &width);
			Assert::AreEqual(0, width); //Negative (Invalid) input case
		}

		TEST_METHOD(TestSetWidth_MaximumValidInput)
		{
			int width = 0;
			setWidth(99, &width);
			Assert::AreEqual(99, width); //Upper edge case
		}

	};
}
