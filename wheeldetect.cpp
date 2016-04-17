#include <opencv\cv.h>
#include <opencv\highgui.h>


int main(void)
{
 IplImage *image = cvLoadImage("D:/OpenCV/WheelChair/wheelphoto.jpg",CV_LOAD_IMAGE_GRAYSCALE);
 IplImage *detectimage = cvLoadImage("D:/OpenCV/WheelChair/wheelphoto.jpg",CV_LOAD_IMAGE_GRAYSCALE);

  
 CvMemStorage* storage = cvCreateMemStorage(0);
 //cvSmooth(detectimage, detectimage, CV_GAUSSIAN, 5, 5);
 CvSeq* results = cvHoughCircles(detectimage,storage,CV_HOUGH_GRADIENT,1,image->width/1,100,100,50,200);
 //CvSeq* results = cvHoughCircles(detectimage,storage,CV_HOUGH_GRADIENT,50,image->width/10);6
 for(int i = 0 ; i < results->total ; i++){
  float* p = (float*)cvGetSeqElem(results,i);
  CvPoint pt = cvPoint(cvRound(p[0]), cvRound(p[1]));
  //cvCircle(detectimage, pt, cvRound(p[2]),CV_RGB(0xff,0xff,0xff));
  cvCircle(detectimage, pt, cvRound(p[2])+20,CV_RGB(0xff,0xff,0xff));

 }
 
 cvNamedWindow("Image",1);
 cvShowImage("Image",image);
 cvShowImage("DetectImage",detectimage);
 cvWaitKey();
 cvReleaseImage(&image);
 cvReleaseMemStorage(&storage);
 cvDestroyWindow("ROI:");
 return 0;
}