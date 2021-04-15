#include <iostream>
#include <vector>

using namespace std;

// main function -
// where the execution of program begins
int main()
{
    // we have two sorted vectors and we want to do some tasks
    vector<int> nums1, nums2;
    nums1.push_back(1);
    nums1.push_back(1);
    nums1.push_back(3);
    nums2.push_back(1);
    nums2.push_back(3);
    nums2.push_back(3);

    vector<int> smar, lgar;

    // First find the smaller vector
    if (nums1.size() > nums2.size())
    {
        smar = nums2;
        lgar = nums1;
    }
    else
    {
        smar = nums1;
        lgar = nums2;
    }

    int l,h,x,y;
    x = smar.size();
    y = lgar.size();

    // We are going to partion the smaller vector
    l = 0;
    h = x;

    while(l <= h) {
        int parX = (l + h) / 2;
        int parY = (x + y + 1) / 2 - parX;

        int leftX = std::numeric_limits<int>::min() ? parX == 0 : smar[parX - 1];
        int rightX = std::numeric_limits<int>::max() ? parX == x : smar[parX];

        int leftY = std::numeric_limits<int>::min() ? parY == 0 : lgar[parY - 1];
        int rightY = std::numeric_limits<int>::max() ? parY == x : lgar[parY];
        
        // check if the partition is at right place or not
        if (leftY < rightX && leftX < rightY) {
            // correct partition so return the median
            if( (x+y) % 2 == 0) return (max(leftX, leftY), min(rightX, rightY)) / 2
            else return max(leftX, leftY);

        } else if (leftX > rightY) {
            h = parX - 1;
        } else {
            l = parX + 1;
        }

    }

    return 0;
}
