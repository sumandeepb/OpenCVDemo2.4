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
 
#include <stdio.h>
#include <opencv2\opencv.hpp>			//OpenCV library of IP functions

void load_image_demo ()
{
	// declare pointer to image buffer
	IplImage *pInput;

	// create display window
	cvNamedWindow ("Input");

	// allocate memory, load image from hard disk onto memory, return pointer to memory buffer
	pInput = cvLoadImage ("input/lena.bmp");

	// create data structure for pixel
	CvScalar	pixel;

	// loop through all rows and columns
	for (int row = 0; row < pInput->height; row++)
	{
		for (int col = 0; col < pInput->width; col++)
		{
			// get pixel data
			pixel = cvGet2D (pInput, row, col);
			// change pixel data for every color channel
			for (int color = 0; color < pInput->nChannels; color++)
			{
				pixel.val [color] = 255 - pixel.val [color];
			}
			// set new pixel data
			cvSet2D (pInput, row, col, pixel);
		}
	}

	// display image buffer 
	cvShowImage ("Input", pInput);

	// print essential details about the image
	printf ("Width = %d, Height %d\nNumber of Color Channels = %d\n", pInput->width, pInput->height, pInput->nChannels);

	// wait until user presses any key
	cvWaitKey (0);

	// deallocate image memory
	cvReleaseImage (&pInput);

	// destroy the display window
	cvDestroyAllWindows ();
}
