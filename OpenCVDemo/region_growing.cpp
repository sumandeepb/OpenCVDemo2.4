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

void region_grow_demo ()
{
	// declare pointer to input and output image buffers
	IplImage *pInput, *pLabelImage;

	// create display windows
	cvNamedWindow ("Input");
	cvNamedWindow ("Output");

	// load image as grayscale
	pInput = cvLoadImage ("input/lungCT.bmp", CV_LOAD_IMAGE_GRAYSCALE);

	// create imagebuffer for label image
	pLabelImage = cvCreateImage (cvGetSize(pInput), pInput->depth, 3);

	// Set seed pixel
	CvPoint		seedpoint = {265, 225};
	double		lowrelax = 4.0;
	double		hignrelax = 5.0;
	cvCvtColor (pInput, pLabelImage, CV_GRAY2BGR);
	cvFloodFill (pLabelImage, seedpoint, CV_RGB (192, 64, 0),
			cvScalar (lowrelax, lowrelax, lowrelax), 
			cvScalar (hignrelax, hignrelax, hignrelax));

	// display image buffer 
	cvShowImage ("Input", pInput);
	cvShowImage ("Output", pLabelImage);

	// save output to hard disk
	cvSaveImage ("output/regiongrow.bmp", pLabelImage);

	// wait until user presses any key
	cvWaitKey (0);

	// deallocate image memory
	cvReleaseImage (&pInput);
	cvReleaseImage (&pLabelImage);

	// destroy all the display windows
	cvDestroyAllWindows ();
}
