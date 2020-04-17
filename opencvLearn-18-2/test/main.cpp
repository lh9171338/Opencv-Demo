//-----------------------------------������˵����----------------------------------------------    
//      ��������:������OpenCV���Ž̳�֮ʮ�ˡ�OpenCV����任 & SURF�����������ϼ��� ��������Դ�� ֮ ����任  
//      ��������IDE�汾��Visual Studio 2010    
//      ��������OpenCV�汾��   2.4.9    
//      2014��6�� Created by ǳī    
//      ǳī��΢����@ǳī_ë���� http://weibo.com/1723155442    
//      ǳī��֪����http://www.zhihu.com/people/mao-xing-yun    
//      ǳī�Ķ��꣺http://www.douban.com/people/53426472/    
//----------------------------------------------------------------------------------------------  
  
//-----------------------------------��ͷ�ļ��������֡�---------------------------------------  
//      ����������������������ͷ�ļ�  
//----------------------------------------------------------------------------------------------  
#include <iostream>  
#include <opencv2/opencv.hpp> 
#include <opencv2/xfeatures2d.hpp>
  
  
//-----------------------------------�������ռ��������֡�--------------------------------------  
//      ����������������ʹ�õ������ռ�  
//-----------------------------------------------------------------------------------------------  
using namespace std;  
using namespace cv;
using namespace cv::xfeatures2d;

  
//-----------------------------------��ȫ�ֺ����������֡�--------------------------------------  
//      ������ȫ�ֺ���������  
//-----------------------------------------------------------------------------------------------  
static void ShowHelpText( );//�����������  
  
  
//-----------------------------------��main( )������--------------------------------------------  
//      ����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼִ��  
//-----------------------------------------------------------------------------------------------  
int main(  )  
{  
    //��0���ı�console������ɫ  
    system("color 1A");   
  
    //��0����ʾ��ӭ�Ͱ�������  
    ShowHelpText( );  
  
    //��1�������ز�ͼ  
    Mat srcImage1 = imread("pic1.jpg",1);  
    Mat srcImage2 = imread("pic2.jpg",1);  
    if( !srcImage1.data || !srcImage2.data )  
    { printf("��ȡͼƬ������ȷ��Ŀ¼���Ƿ���imread����ָ����ͼƬ����~�� \n"); return false; }    
  
	imshow("ԭͼ1", srcImage1 );  
	imshow("ԭͼ2", srcImage2 );  

    //��2��ʹ��SURF���Ӽ��ؼ���  
    int minHessian = 700;//SURF�㷨�е�hessian��ֵ  
    Ptr<SURF> detector = SURF::create( minHessian );//����һ��SurfFeatureDetector��SURF�� ������������    
    vector<KeyPoint> keyPoints1, keyPoints2;//vectorģ���࣬����������͵Ķ�̬����  
	Mat descriptors1, descriptors2;

    //��3������detect��������SURF�����ؼ��㣬����������������������  
    detector->detectAndCompute( srcImage1, noArray(), keyPoints1, descriptors1);
    detector->detectAndCompute( srcImage2, noArray(), keyPoints2, descriptors2);
  
    //��4��ʹ��BruteForce����ƥ��  
    // ʵ����һ��ƥ����  
	Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce");
    vector< DMatch > matches;  
    //ƥ������ͼ�е������ӣ�descriptors��  
    matcher->match( descriptors1, descriptors2, matches );  
  
    //��5�����ƴ�����ͼ����ƥ����Ĺؼ���  
    Mat imgMatches;  
    drawMatches( srcImage1, keyPoints1, srcImage2, keyPoints2, matches, imgMatches );//���л���  
  
    //��6����ʾЧ��ͼ  
    imshow("ƥ��ͼ", imgMatches );  
  
    waitKey(0);  
    return 0;  
}  
  
//-----------------------------------��ShowHelpText( )������----------------------------------    
//      ���������һЩ������Ϣ    
//----------------------------------------------------------------------------------------------    
static void ShowHelpText()    
{    
    //���һЩ������Ϣ    
    printf(  "\n\n\n\t��ӭ������SURF����������ʾ������~\n\n");    
    printf("\t��ǰʹ�õ�OpenCV�汾Ϊ OpenCV " CV_VERSION);    
}    