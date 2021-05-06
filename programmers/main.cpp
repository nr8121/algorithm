#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int make_SegmentTree(int start, int end, int nodeIndex, vector<int>& array, vector<int>& segmentTree)
{
    if(start == end) return segmentTree[nodeIndex] = array[start];

    int middle = (start+end)/2;
    
    int leftSum = make_SegmentTree(start, middle, nodeIndex*2, array, segmentTree);
    int rightSum = make_SegmentTree(middle, end, nodeIndex*2+1, array, segmentTree);
    segmentTree[nodeIndex] = leftSum+rightSum;

    return segmentTree[nodeIndex];
}
vector<int> init(vector<int> array)
{
    int height = ceil(log2(array.size()));
    int size = (1 << (height+1));
    vector<int> segmentTree(size);
    make_SegmentTree(0, array.size(), 1, array, segmentTree);

    return segmentTree;
}

int main()
{   
    vector<int> array = { 1, 3, 4, 6, 7};

    vector<int> segmentTree = init(array);

}   