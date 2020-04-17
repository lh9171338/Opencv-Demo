//-----------------------------------��ͷ�ļ��������֡�---------------------------------------  
//  ����������������������ͷ�ļ�  
//----------------------------------------------------------------------------------------------   
#include <iostream>  
#include <opencv2/opencv.hpp>  
  
//-----------------------------------�������ռ��������֡�---------------------------------------  
//  ����������������ʹ�õ������ռ�  
//-----------------------------------------------------------------------------------------------     
using namespace cv;  
using namespace std;  
  
//-----------------------------------��ȫ�ֺ����������֡�--------------------------------------  
//  ������ȫ�ֺ�������  
//-----------------------------------------------------------------------------------------------  
Mat img;  
int threshval = 160;            //�켣�������Ӧ��ֵ������ֵ160  
  
//-----------------------------��on_trackbar( )������------------------------------------  
//  �������켣���Ļص�����  
//-----------------------------------------------------------------------------------------------  
static void on_trackbar(int, void*)  
{  
    Mat bw = threshval < 128 ? (img < threshval) : (img > threshval);  
  
    //����������  
    vector<vector<Point> > contours;  
    vector<Vec4i> hierarchy;  
  
    //��������  
    findContours( bw, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);
    //��ʼ��dst  
    Mat dst = Mat::zeros(img.size(), CV_8UC3);  
    //��ʼ����  
    if( !contours.empty() && !hierarchy.empty() )  
    {  
        //�������ж������������������ɫֵ���Ƹ���������ɲ���  
        int idx = 0;  
        for( ; idx >= 0; idx = hierarchy[idx][0] )  
        {  
            Scalar color( (rand()&255), (rand()&255), (rand()&255) );  
            //�����������  
            drawContours( dst, contours, idx, color, FILLED, 8, hierarchy );  
        }  
    }  
    //��ʾ����  
    imshow( "Connected Components", dst );  
}  
  
  
//-----------------------------------��main( )������--------------------------------------------  
//  ����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼ  
//-----------------------------------------------------------------------------------------------  
int main(  )  
{  
    system("color 5F");    
    //����ͼƬ  
    img = imread("pic1.jpg", 0);  
    if( !img.data ) { printf("��ȡimgͼƬ�ļ�����\n"); return -1; }  
  
    //��ʾԭͼ  
    namedWindow( "Image", 1 );  
    imshow( "Image", img );  
  
    //����������  
    namedWindow( "Connected Components", 1 );  
    //�����켣��  
    createTrackbar( "Threshold", "Connected Components", &threshval, 255, on_trackbar );  
    on_trackbar(threshval, 0);//�켣���ص�����  
  
    waitKey(0);  
    return 0;  
} 