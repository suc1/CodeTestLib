#include <iostream>
#include <limits>
using namespace std;

#if 0   //分治法
//int a[16] = {13,-3,-25,20,-3,-16,-23, 18,20,-7,12 ,-5,-22,15,-4,7};  
int a[] = {2, 3, -1, 4};
 
int findCrossbigSubarray(int low,int mid,int high)		//和一定要包含a[mid]和a[mid+1] 
{
	int sum = 0;
	int left_big = std::numeric_limits<int>::min();
	for(int i=mid; i>=low; --i)							//mid属于左数组
	{
		sum += a[i];
		if(sum > left_big) left_big = sum;
	}
 
	sum = 0;
	int right_big = std::numeric_limits<int>::min();
	for(int i=mid+1; i<=high; ++i)						//mid+1属于右数组 
	{
		sum += a[i];
		if(sum > right_big) right_big = sum;
	}
	
	return right_big + left_big;
}
 
int findbigSubarray(int low, int high)
{
	cout << "findbigSubarray( " << low << ", " << high << endl;
    if(low == high) return a[low];
	int mid = (low + high) / 2;
 
	int left_big = findbigSubarray(low,mid);				//左数组的最大值
	int right_big = findbigSubarray(mid+1,high);			//右数组的最大值
	int cross_big = findCrossbigSubarray(low,mid,high);		//穿越数组的最大值
    cout << endl << "findbigSubarray-result( " << low << ", " << high << endl;
    cout << "left_big=" << left_big << endl;
    cout << "right_big=" << right_big << endl;
    cout << "cross_big=" << cross_big << endl;
 
	int big = max(left_big, right_big);
	if(cross_big > big) big = cross_big;
 
	return big;												//返回三者的最大值
}
 
int main()
{
	cout << findbigSubarray(0, sizeof(a)/sizeof(a[0])-1) << endl;
	return 0;
}

#else   //动态规划
//需要一个辅助数组sum，其中sum[i]为以a[i]为尾元素的最大子数列【精髓】，待sum数组全部完成后，找出sum数组里元素的最大值，即为答案
//动态转移方程: sum[i+1] = max(sum[i]+a[i+1], a[i+1])
#include <iostream>
using namespace std;
 
int a[16] = {13,-3,-25,20,-3,-16,-23, 18,20,-7,12 ,-5,-22,15,-4,7};
 
//sum = {13,10,-15,20,17, 1, -22, 18,38,31,43 ,38, 16,31,27,34};
int sum[16] = {a[0]};
 
int main()
{
	for(int i=0; i<16; ++i)
		sum[i+1] = max(sum[i]+a[i+1], a[i+1]); 
 
	//取sum中的最大值
	int Max = sum[0];
	for(int i=1; i<16; ++i)
		if(sum[i] > Max)
			Max = sum[i];
 
	cout<<Max;
	return 0;
}

#endif
