/*
    Copyright 2012-2018 Sumandeep Banerjee, sumandeep.banerjee@gmail.com
    
    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at
    
    http://www.apache.org/licenses/LICENSE-2.0
    
    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/
 
#include <opencv2\opencv.hpp>			//OpenCV library of IP functions

void contours_demo ()
{
	// declare pointer to input and output image buffers
	IplImage *pInput, *pTempImage, *pContourImage;

	// create display windows
	cvNamedWindow ("Input");
	cvNamedWindow ("Output");

	// load image as grayscale
	pInput = cvLoadImage ("output/adapthresh.bmp", CV_LOAD_IMAGE_GRAYSCALE);

	// create intermediate temporary image buffer
	pTempImage = cvCreateImage (cvGetSize(pInput), pInput->depth, pInput->nChannels);

	// create imagebuffer for contour output
	pContourImage = cvCreateImage (cvGetSize(pInput), pInput->depth, 3);
	
	// cleanup spurious noise using median filtering
	cvSmooth (pInput, pTempImage, CV_MEDIAN, 5);

	// create data strucutres to store contour data
	CvMemStorage	*storage = cvCreateMemStorage(0);
	CvSeq			*contours = 0;

	// find contours
	cvFindContours (pTempImage, storage, &contours);

	// draw contours superimposed on input image
	cvCvtColor (pInput, pContourImage, CV_GRAY2BGR);
	cvDrawContours (pContourImage, contours, CV_RGB (255, 0, 0), CV_RGB (0, 255, 0), 1);

	// save contour data to hard disk
    const char* attrs[] = {"recursive", "1", 0};
    cvSave("output/contours.xml", contours, 0, 0, cvAttrList(attrs, 0));

	// display image buffer 
	cvShowImage ("Input", pInput);
	cvShowImage ("Output", pContourImage);

	// save output to hard disk
	cvSaveImage ("output/contours.bmp", pContourImage);

	// wait until user presses any key
	cvWaitKey (0);

	// deallocate image memory
	cvReleaseImage (&pInput);
	cvReleaseImage (&pTempImage);
	cvReleaseImage (&pContourImage);
	cvReleaseMemStorage (&storage);

	// destroy all the display windows
	cvDestroyAllWindows ();
}
