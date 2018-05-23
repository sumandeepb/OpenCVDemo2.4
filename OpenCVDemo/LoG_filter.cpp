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

void LoG_filter_demo ()
{
	//declare image buffer pointers
	IplImage *pImage, *pLaplaceImage, *pOutImage;

	// create display windows
	cvNamedWindow ("Input");
	cvNamedWindow ("Output");

	// load image as grayscale
	pImage = cvLoadImage ("input/lena_grey.bmp", CV_LOAD_IMAGE_GRAYSCALE);
	cvShowImage ("Input", pImage);

	// allocate memory buffer for output of same size as input
	pOutImage = cvCreateImage (cvGetSize(pImage), pImage->depth, pImage->nChannels);
	
	// laplace operator may produce -ve pixel values, therefore it requires 32bit floating images for temporary storage
	pLaplaceImage = cvCreateImage (cvGetSize(pImage), IPL_DEPTH_32F, pImage->nChannels);

	// perform 3X3 gaussian smoothing
	cvSmooth (pImage, pOutImage, CV_GAUSSIAN, 3);
	// apply laplacian filter
	cvLaplace (pOutImage, pLaplaceImage, 3);

	// convert laplacian output back to 8bit grayscale image
	cvConvert (pLaplaceImage, pOutImage);

	// save output
	cvShowImage ("Output", pOutImage);
	cvSaveImage ("output/LoG.bmp", pOutImage);

	// wait till key press
	cvWaitKey (0);

	// release memory 
	cvReleaseImage (&pImage);
	cvReleaseImage (&pOutImage);
	cvReleaseImage (&pLaplaceImage);

	// destroy gui windows
	cvDestroyAllWindows ();
}
