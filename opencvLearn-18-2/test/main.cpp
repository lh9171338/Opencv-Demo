//-----------------------------------【程序说明】----------------------------------------------    
//      程序名称:：《【OpenCV入门教程之十八】OpenCV仿射变换 & SURF特征点描述合辑》 博文配套源码 之 仿射变换  
//      开发所用IDE版本：Visual Studio 2010    
//      开发所用OpenCV版本：   2.4.9    
//      2014年6月 Created by 浅墨    
//      浅墨的微博：@浅墨_毛星云 http://weibo.com/1723155442    
//      浅墨的知乎：http://www.zhihu.com/people/mao-xing-yun    
//      浅墨的豆瓣：http://www.douban.com/people/53426472/    
//----------------------------------------------------------------------------------------------  
  
//-----------------------------------【头文件包含部分】---------------------------------------  
//      描述：包含程序所依赖的头文件  
//----------------------------------------------------------------------------------------------  
#include <iostream>  
#include <opencv2/opencv.hpp> 
#include <opencv2/xfeatures2d.hpp>
  
  
//-----------------------------------【命名空间声明部分】--------------------------------------  
//      描述：包含程序所使用的命名空间  
//-----------------------------------------------------------------------------------------------  
using namespace std;  
using namespace cv;
using namespace cv::xfeatures2d;

  
//-----------------------------------【全局函数声明部分】--------------------------------------  
//      描述：全局函数的声明  
//-----------------------------------------------------------------------------------------------  
static void ShowHelpText( );//输出帮助文字  
  
  
//-----------------------------------【main( )函数】--------------------------------------------  
//      描述：控制台应用程序的入口函数，我们的程序从这里开始执行  
//-----------------------------------------------------------------------------------------------  
int main(  )  
{  
    //【0】改变console字体颜色  
    system("color 1A");   
  
    //【0】显示欢迎和帮助文字  
    ShowHelpText( );  
  
    //【1】载入素材图  
    Mat srcImage1 = imread("pic1.jpg",1);  
    Mat srcImage2 = imread("pic2.jpg",1);  
    if( !srcImage1.data || !srcImage2.data )  
    { printf("读取图片错误，请确定目录下是否有imread函数指定的图片存在~！ \n"); return false; }    
  
	imshow("原图1", srcImage1 );  
	imshow("原图2", srcImage2 );  

    //【2】使用SURF算子检测关键点  
    int minHessian = 700;//SURF算法中的hessian阈值  
    Ptr<SURF> detector = SURF::create( minHessian );//定义一个SurfFeatureDetector（SURF） 特征检测类对象    
    vector<KeyPoint> keyPoints1, keyPoints2;//vector模板类，存放任意类型的动态数组  
	Mat descriptors1, descriptors2;

    //【3】调用detect函数检测出SURF特征关键点，计算描述符（特征向量）  
    detector->detectAndCompute( srcImage1, noArray(), keyPoints1, descriptors1);
    detector->detectAndCompute( srcImage2, noArray(), keyPoints2, descriptors2);
  
    //【4】使用BruteForce进行匹配  
    // 实例化一个匹配器  
	Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce");
    vector< DMatch > matches;  
    //匹配两幅图中的描述子（descriptors）  
    matcher->match( descriptors1, descriptors2, matches );  
  
    //【5】绘制从两个图像中匹配出的关键点  
    Mat imgMatches;  
    drawMatches( srcImage1, keyPoints1, srcImage2, keyPoints2, matches, imgMatches );//进行绘制  
  
    //【6】显示效果图  
    imshow("匹配图", imgMatches );  
  
    waitKey(0);  
    return 0;  
}  
  
//-----------------------------------【ShowHelpText( )函数】----------------------------------    
//      描述：输出一些帮助信息    
//----------------------------------------------------------------------------------------------    
static void ShowHelpText()    
{    
    //输出一些帮助信息    
    printf(  "\n\n\n\t欢迎来到【SURF特征描述】示例程序~\n\n");    
    printf("\t当前使用的OpenCV版本为 OpenCV " CV_VERSION);    
}    