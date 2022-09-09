// tests.cpp
#include "LinkedList.h"
#include <gtest/gtest.h>


	void TestEmpty(ILinkedList& list)
	{
			ASSERT_TRUE(list.isEmpty());

			ASSERT_EQ(std::string(""), list.toString());

			list.clear();
			ASSERT_TRUE(list.isEmpty());

	}
		TEST(PointerBasedLinkedList,TestEmpy)
		{
			PointerBasedLinkedList linkedList = PointerBasedLinkedList();

			TestEmpty(linkedList);

		}
		
        TEST(ArrayBasedLinkedList, TestEmpy) 
		{           
			ArrayBasedLinkedList linkedList = ArrayBasedLinkedList();

			TestEmpty(linkedList);

		}

		void Test1Add(ILinkedList& list)
		{
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.add(1));

			ASSERT_FALSE(list.isEmpty());

			ASSERT_EQ(std::string("1"), list.toString());

			list.clear();
			ASSERT_TRUE(list.isEmpty());

		}

		TEST(ArrayBasedLinkedList, Test1Add)
		{
			ArrayBasedLinkedList linkedList =  ArrayBasedLinkedList();
			Test1Add(linkedList);
		}

		TEST(PointerBasedLinkedList,Test1Add)
		{
			PointerBasedLinkedList linkedList = PointerBasedLinkedList();
			Test1Add(linkedList);
		}

		void Test2Add(ILinkedList & list)
		{
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.add(1));
			ASSERT_TRUE(list.add(2));

			ASSERT_FALSE(list.isEmpty());

			ASSERT_EQ(std::string("1 2"), list.toString());

			list.clear();
			ASSERT_TRUE(list.isEmpty());
		}

		TEST(ArrayBasedLinkedList, Test2Add)
		{
			ArrayBasedLinkedList linkedList = ArrayBasedLinkedList();
			Test2Add(linkedList);

		}

		TEST(PointerBasedLinkedList,Test2Add)
		{
			PointerBasedLinkedList linkedList = PointerBasedLinkedList();
			Test2Add(linkedList);

		}

		void Test3Add(ILinkedList& list)
		{
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.add(1));
			ASSERT_TRUE(list.add(2));
			ASSERT_TRUE(list.add(3));

			ASSERT_FALSE(list.isEmpty());

			ASSERT_EQ(std::string("1 2 3"), list.toString());

			list.clear();
			ASSERT_TRUE(list.isEmpty());
		}

		TEST(ArrayBasedLinkedList, Test3Add)
		{
			ArrayBasedLinkedList linkedList = ArrayBasedLinkedList();
			Test3Add(linkedList);

		}


		TEST(PointerBasedLinkedList,Test3Add)
		{
			PointerBasedLinkedList linkedList = PointerBasedLinkedList();
			Test3Add(linkedList);

		}

		void Test11Add(ILinkedList& list, bool isPointerBased)
		{
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.add(1));
			ASSERT_TRUE(list.add(2));
			ASSERT_TRUE(list.add(3));
			ASSERT_TRUE(list.add(4));
			ASSERT_TRUE(list.add(5));
			ASSERT_TRUE(list.add(6));
			ASSERT_TRUE(list.add(7));
			ASSERT_TRUE(list.add(8));
			ASSERT_TRUE(list.add(9));
			ASSERT_TRUE(list.add(10));
			if(isPointerBased)
			{
				ASSERT_TRUE(list.add(11));
			}
			else
			{
				ASSERT_FALSE(list.add(11));//Capacity is 11 so won't add
			}

			ASSERT_FALSE(list.isEmpty());

			if(isPointerBased)
			{
				ASSERT_EQ(std::string("1 2 3 4 5 6 7 8 9 10 11"), list.toString());
			}
			else
			{
				ASSERT_EQ(std::string("1 2 3 4 5 6 7 8 9 10"), list.toString());//Capacity is 11 so won't add
			}

			list.clear();
			ASSERT_TRUE(list.isEmpty());
		}

		TEST(ArrayBasedLinkedList, Test11Add)
		{
			ArrayBasedLinkedList linkedList = ArrayBasedLinkedList();
			Test11Add(linkedList, false);
		}

		TEST(PointerBasedLinkedList, Test11Add)
		{
			PointerBasedLinkedList linkedList = PointerBasedLinkedList();
			Test11Add(linkedList, true);

		}

		void TestRemoveNonExistant(ILinkedList& list)
		{
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.add(1));
			ASSERT_TRUE(list.add(2));
			ASSERT_TRUE(list.add(3));

			ASSERT_FALSE(list.remove(4));

			ASSERT_FALSE(list.isEmpty());

			ASSERT_EQ(std::string("1 2 3"), list.toString());

			list.clear();
			ASSERT_TRUE(list.isEmpty());
		}

		TEST(ArrayBasedLinkedList, TestRemoveNonExistant)
		{
			ArrayBasedLinkedList linkedList = ArrayBasedLinkedList();
			TestRemoveNonExistant(linkedList);

		}

		TEST(PointerBasedLinkedList, TestRemoveNonExistant)
		{
			PointerBasedLinkedList linkedList = PointerBasedLinkedList();
			TestRemoveNonExistant(linkedList);

		}

		void TestBeginingRemove(ILinkedList& list)
		{
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.add(1));
			ASSERT_TRUE(list.add(2));
			ASSERT_TRUE(list.add(3));

			ASSERT_TRUE(list.remove(1));

			ASSERT_FALSE(list.isEmpty());

			ASSERT_EQ(std::string("2 3"), list.toString());
			
			list.clear();
			ASSERT_TRUE(list.isEmpty());
		}

		TEST(ArrayBasedLinkedList, TestBeginingRemove)
		{
			ArrayBasedLinkedList linkedList = ArrayBasedLinkedList();
			TestBeginingRemove(linkedList);

		}

		TEST(PointerBasedLinkedList, TestBeginingRemove)
		{
			PointerBasedLinkedList linkedList = PointerBasedLinkedList();
			TestBeginingRemove(linkedList);

		}

		void TestMiddleRemove(ILinkedList& list)
		{
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.add(1));
			ASSERT_TRUE(list.add(2));
			ASSERT_TRUE(list.add(3));

			ASSERT_TRUE(list.remove(2));

			ASSERT_FALSE(list.isEmpty());

			ASSERT_EQ(std::string("1 3"), list.toString());

			list.clear();
			ASSERT_TRUE(list.isEmpty());
		}

		TEST(PointerBasedLinkedList, TestMiddleRemove)
		{
			PointerBasedLinkedList linkedList = PointerBasedLinkedList();
			TestMiddleRemove(linkedList);

		}

		TEST(ArrayBasedLinkedList, TestMiddleRemove)
		{
			ArrayBasedLinkedList linkedList = ArrayBasedLinkedList();
			TestMiddleRemove(linkedList);

		}

		void TestEndRemove(ILinkedList& list)
		{
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.add(1));
			ASSERT_TRUE(list.add(2));
			ASSERT_TRUE(list.add(3));

			ASSERT_TRUE(list.remove(3));

			ASSERT_FALSE(list.isEmpty());

			ASSERT_EQ(std::string("1 2"), list.toString());

			list.clear();
			ASSERT_TRUE(list.isEmpty());
		}

		TEST(ArrayBasedLinkedList, TestEndRemove)
		{
			ArrayBasedLinkedList linkedList = ArrayBasedLinkedList();
			TestEndRemove(linkedList);

		}

		TEST(PointerBasedLinkedList, TestEndRemove)
		{
			PointerBasedLinkedList linkedList = PointerBasedLinkedList();
			TestEndRemove(linkedList);

		}

		void TestMultipleRemove(ILinkedList& list)
		{
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.add(1));
			ASSERT_TRUE(list.add(2));
			ASSERT_TRUE(list.add(3));
			ASSERT_TRUE(list.add(4));
			ASSERT_TRUE(list.add(5));
			ASSERT_TRUE(list.add(6));
			ASSERT_TRUE(list.add(7));
			ASSERT_TRUE(list.add(8));
			ASSERT_TRUE(list.add(9));
			ASSERT_TRUE(list.add(10));

			ASSERT_TRUE(list.remove(2));
			ASSERT_TRUE(list.remove(4));
			ASSERT_TRUE(list.remove(6));
			ASSERT_TRUE(list.remove(8));

			ASSERT_FALSE(list.remove(2));
			ASSERT_FALSE(list.remove(4));
			ASSERT_FALSE(list.remove(6));
			ASSERT_FALSE(list.remove(8));

			ASSERT_FALSE(list.isEmpty());

			ASSERT_EQ(std::string("1 3 5 7 9 10"), list.toString());

			list.clear();
			ASSERT_TRUE(list.isEmpty());
		}

		TEST(ArrayBasedLinkedList, TestMultipleRemove)
		{
			ArrayBasedLinkedList linkedList = ArrayBasedLinkedList();
			TestMultipleRemove(linkedList);

		}

		TEST(PointerBasedLinkedList, TestMultipleRemove)
		{
			PointerBasedLinkedList linkedList = PointerBasedLinkedList();
			TestMultipleRemove(linkedList);

		}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
