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

void connected_comp_demo ()
{
	// declare pointer to input and output image buffers
	IplImage *pInput, *pLabelImage;

	// create display windows
	cvNamedWindow ("Input");
	cvNamedWindow ("Output");

	// load image as grayscale
	pInput = cvLoadImage ("output/adapthresh.bmp", CV_LOAD_IMAGE_GRAYSCALE);

	// create imagebuffer for label image
	pLabelImage = cvCreateImage (cvGetSize(pInput), pInput->depth, pInput->nChannels);

	// cleanup spurious noise using median filtering
	cvSmooth (pInput, pLabelImage, CV_MEDIAN, 5);

	// init label count
	int nLabelCount = 0;
	CvScalar pixel;
	// scan entire image pixel by pixel
	for (int row = 0; row < pInput->height; row++)
	{
		for (int col = 0; col < pInput->width; col++)
		{
			pixel = cvGet2D (pLabelImage, row, col);// get pixel data
			if (255.0 == pixel.val [0])				// if pixel is foreground
			{
				nLabelCount++;						// increase label count
				// mark object using label tag
				cvFloodFill (pLabelImage, cvPoint (col, row),
					cvScalar ((double)nLabelCount));
			}
		}
	}

	// print result
	printf ("Number of foreground objects = %d\n", nLabelCount);

	// display image buffer 
	cvShowImage ("Input", pInput);
	cvShowImage ("Output", pLabelImage);

	// save output to hard disk
	cvSaveImage ("output/connectedcomp.bmp", pLabelImage);

	// wait until user presses any key
	cvWaitKey (0);

	// deallocate image memory
	cvReleaseImage (&pInput);
	cvReleaseImage (&pLabelImage);

	// destroy all the display windows
	cvDestroyAllWindows ();
}
