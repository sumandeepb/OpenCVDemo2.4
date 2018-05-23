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

void thresholding_demo ()
{
	// declare pointer to input and output image buffers
	IplImage *pInput, *pBinOutput, *pOtsuOutput;
	IplImage *pAdapThresh;

	// create display windows
	cvNamedWindow ("Input");
	cvNamedWindow ("Output - Binary Thresholding");
	cvNamedWindow ("Output - Otsu Thresholding");
	cvNamedWindow ("Output - Adaptive Thresholding");

	// load image as grayscale
	pInput = cvLoadImage ("input/rice.bmp", CV_LOAD_IMAGE_GRAYSCALE);

	// allocate memory buffer for output of same size as input
	pBinOutput = cvCreateImage (cvGetSize(pInput), pInput->depth, pInput->nChannels);
	pOtsuOutput = cvCreateImage (cvGetSize(pInput), pInput->depth, pInput->nChannels);
	pAdapThresh = cvCreateImage (cvGetSize(pInput), pInput->depth, pInput->nChannels);

	// perform binary thresholding - uses fixed threshold value
	cvThreshold (pInput, pBinOutput, 127.0, 255.0, 
						CV_THRESH_BINARY);

	// perform otsu thresholding - calculates threshold value using bimodal histogram
	int thresh = (int) cvThreshold (pInput, pOtsuOutput, 
		0.0, 255.0, CV_THRESH_BINARY | CV_THRESH_OTSU);
	printf ("Otsu threshold = %d\n", thresh);

	// local adaptive thresholding
	cvAdaptiveThreshold (pInput, pAdapThresh, 255.0,
		CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 51, -20.0);

	// display image buffer 
	cvShowImage ("Input", pInput);
	cvShowImage ("Output - Binary Thresholding", pBinOutput);
	cvShowImage ("Output - Otsu Thresholding", pOtsuOutput);
	cvShowImage ("Output - Adaptive Thresholding", pAdapThresh);

	// save output to hard disk
	cvSaveImage ("output/binthresh.bmp", pBinOutput);
	cvSaveImage ("output/otsuthresh.bmp", pOtsuOutput);
	cvSaveImage ("output/adapthresh.bmp", pAdapThresh);

	// wait until user presses any key
	cvWaitKey (0);

	// deallocate image memory
	cvReleaseImage (&pInput);
	cvReleaseImage (&pBinOutput);
	cvReleaseImage (&pOtsuOutput);
	cvReleaseImage (&pAdapThresh);

	// destroy all the display windows
	cvDestroyAllWindows ();
}
