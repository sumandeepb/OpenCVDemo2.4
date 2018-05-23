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

void median_filter_demo ()
{
	//declare image buffer pointers
	IplImage *pImage, *pOutImage;

	// create display windows
	cvNamedWindow ("Input");
	cvNamedWindow ("Output");

	// load image
	pImage = cvLoadImage ("input/lena_random.bmp");
	cvShowImage ("Input", pImage);

	// allocate memory buffer for output of same size as input
	pOutImage = cvCreateImage (cvGetSize(pImage), pImage->depth, pImage->nChannels);

	// perform 3X3 median filtering
	cvSmooth (pImage, pOutImage, CV_MEDIAN, 3);

	// save output
	cvShowImage ("Output", pOutImage);
	cvSaveImage ("output/median.bmp", pOutImage);

	// wait till key press
	cvWaitKey (0);

	// release memory 
	cvReleaseImage (&pImage);
	cvReleaseImage (&pOutImage);

	// destroy gui windows
	cvDestroyAllWindows ();	
}		
