#include "SORT.H" 
#include "BDSCTEST.H"

main()
{
   
    START_TESTING("Merge Sort");

    TEST_CASE("Unsorted array");
    {
        int data[5];
        data[0] = 15; data[1] = 34; data[2] = 87; data[3] = 45; data[4] = 94;

        mergesort(data, 5);

        ASSERT_EQU(data[0], 15);
        ASSERT_EQU(data[1], 34);
        ASSERT_EQU(data[2], 45);
        ASSERT_EQU(data[3], 87);
        ASSERT_EQU(data[4], 94);
    }

    TEST_CASE("Sorted array");
    {
        int data2[3];
        data2[0] = 1; data2[1] = 2; data2[2] = 3;
        
        mergesort(data2, 3);
        
        ASSERT_EQU(data2[0], 1);
        ASSERT_EQU(data2[2], 3);
    }

    END_TESTING();
}