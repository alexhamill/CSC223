#include "SORTT.C"
#include "BDSCTEST.H"




main()
{
   int data[5];
   int data2[3];
   int data3[1];
   int data4[5];


   START_TESTING("Merge Sort");


   TEST_CASE("Unsorted array");
   data[0] = 15; data[1] = 34; data[2] = 87; data[3] = 45; data[4] = 94;
   merge_sort(data, 0, 4);
   ASSERT_EQU(data[0], 15);
   ASSERT_EQU(data[1], 34);
   ASSERT_EQU(data[2], 45);
   ASSERT_EQU(data[3], 87);
   ASSERT_EQU(data[4], 94);


   TEST_CASE("Already sorted array");
   data2[0] = 1; data2[1] = 2; data2[2] = 3;
   merge_sort(data2, 0, 2);
   ASSERT_EQU(data2[0], 1);
   ASSERT_EQU(data2[1], 2);
   ASSERT_EQU(data2[2], 3);


   TEST_CASE("Single element");
   data3[0] = 42;
   merge_sort(data3, 0, 0);
   ASSERT_EQU(data3[0], 42);


   TEST_CASE("Reverse sorted array");
   data4[0] = 5; data4[1] = 4; data4[2] = 3; data4[3] = 2; data4[4] = 1;
   merge_sort(data4, 0, 4);
   ASSERT_EQU(data4[0], 1);
   ASSERT_EQU(data4[1], 2);
   ASSERT_EQU(data4[2], 3);
   ASSERT_EQU(data4[3], 4);
   ASSERT_EQU(data4[4], 5);


   END_TESTING();
}



