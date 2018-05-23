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

void freq_filter_demo (int nFilterType, char szOutFileName [])
{
	// declare pointer to input and output image buffers
	IplImage	*pInput, *pInput32F, *pOutput, *pOutput32F;
	CvMat	*pDFTIn, *pDFTOut;

	// create display windows
	cvNamedWindow ("Input");
	cvNamedWindow ("Output");

	// load image as grayscale
	pInput = cvLoadImage ("input/lena_grey.bmp", CV_LOAD_IMAGE_GRAYSCALE);

	// allocate 32 bit float image buffer for DFT processing
	pInput32F = cvCreateImage (cvGetSize(pInput), IPL_DEPTH_32F, pInput->nChannels);
	
	// allocate memory buffer for output of same size as input
	pOutput = cvCreateImage (cvGetSize(pInput), pInput->depth, pInput->nChannels);
	pOutput32F = cvCreateImage (cvGetSize(pInput), IPL_DEPTH_32F, pInput->nChannels);

	// allocate buffer for DFT coefficients, two channels for real and imaginary components
	pDFTIn = cvCreateMat (pInput->height, pInput->width, CV_32FC2);
	pDFTOut = cvCreateMat (pInput->height, pInput->width, CV_32FC2);

	// apply forward DFT
	cvConvert (pInput, pInput32F);
	cvDFT (pInput32F, pDFTIn, CV_DXT_FORWARD);

	// perform filtering
	cvCopy (pDFTIn, pDFTOut); // do nothing

	// apply inverse DFT
	cvDFT (pDFTOut, pOutput32F, CV_DXT_INVERSE);
	cvConvert (pOutput32F, pOutput);

	// display image buffer 
	cvShowImage ("Input", pInput);
	cvShowImage ("Output", pOutput);

	// save output to hard disk
	cvSaveImage (szOutFileName, pOutput);

	// wait until user presses any key
	cvWaitKey (0);

	// deallocate image memory
	cvReleaseImage (&pInput);
	cvReleaseImage (&pOutput);

	// destroy all the display windows
	cvDestroyAllWindows ();
}
