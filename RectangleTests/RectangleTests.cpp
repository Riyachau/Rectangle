#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" {
	int getPerimeter(int* length, int* width);
	int getArea(int* length, int* width);
}

namespace RectangleTests
{
	TEST_CLASS(RectangleTests)
	{
	public:
		TEST_METHOD(TestGetPerimeter_ValidInput)
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
	};
}
