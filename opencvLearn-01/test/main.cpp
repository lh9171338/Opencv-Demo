#include<iostream>  
#include <opencv2/opencv.hpp>  
  

using namespace cv;  

  
int main()  
{  
    // ����һ��ͼƬ����Ϸԭ����  
	Mat img=imread("src.jpg");		//ע��·��
    // ����һ����Ϊ "��Ϸԭ��"����  
    namedWindow("��Ϸԭ��");  
    // �ڴ�������ʾ��Ϸԭ��  
    imshow("��Ϸԭ��",img);  
    // �ȴ�6000 ms�󴰿��Զ��ر�  
    waitKey(6000);  
	return 0;
}