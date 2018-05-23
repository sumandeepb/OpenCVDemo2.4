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

void sobel_edge_demo ()
{
	//declare image buffer pointers
	IplImage *pImage, *pSobelXImage, *pSobelYImage, *pOutXImage, *pOutYImage;

	// create display windows
	cvNamedWindow ("Input");
	cvNamedWindow ("Sobel X");
	cvNamedWindow ("Sobel Y");

	// load image as grayscale
	pImage = cvLoadImage ("input/lena_grey.bmp", CV_LOAD_IMAGE_GRAYSCALE);
	cvShowImage ("Input", pImage);

	// allocate memory buffer for output of same size as input
	pOutXImage = cvCreateImage (cvGetSize(pImage), pImage->depth, pImage->nChannels);
	pOutYImage = cvCreateImage (cvGetSize(pImage), pImage->depth, pImage->nChannels);

	// sobel operator may produce -ve pixel values, therefore it requires 32bit floating images for temporary storage
	pSobelXImage = cvCreateImage (cvGetSize(pImage), IPL_DEPTH_32F, pImage->nChannels);
	pSobelYImage = cvCreateImage (cvGetSize(pImage), IPL_DEPTH_32F, pImage->nChannels);

	// perform sobel edge detection
	cvSobel (pImage, pSobelXImage, 1, 0);
	cvSobel (pImage, pSobelYImage, 0, 1);

	// convert sobel output back to 8bit grayscale image
	cvConvert (pSobelXImage, pOutXImage);
	cvConvert (pSobelYImage, pOutYImage);

	// show output
	cvShowImage ("Sobel X", pOutXImage);
	cvShowImage ("Sobel Y", pOutYImage);

	// save output
	cvSaveImage ("output/sobelx.bmp", pOutXImage);
	cvSaveImage ("output/sobely.bmp", pOutYImage);

	// wait till key press
	cvWaitKey (0);

	// release memory 
	cvReleaseImage (&pImage);
	cvReleaseImage (&pOutXImage);
	cvReleaseImage (&pOutYImage);
	cvReleaseImage (&pSobelXImage);
	cvReleaseImage (&pSobelYImage);

	// destroy gui windows
	cvDestroyAllWindows ();
}
