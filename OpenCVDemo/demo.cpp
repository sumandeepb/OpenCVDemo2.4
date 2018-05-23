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

// demo function declarations
// day 1
void load_image_demo ();

// day 2
void gaussian_smooth_demo ();
void median_filter_demo ();
void laplacian_demo ();
void LoG_filter_demo ();
void sobel_edge_demo ();
void canny_edge_demo();
void custom_filter_demo ();

// day 3
void histogram_equalization_demo();
void thresholding_demo ();
void morphology_demo ();

// day 4
void connected_comp_demo ();
void contours_demo ();
void contours2_demo ();
void region_grow_demo ();
void freq_filter_demo (int nFilterType, char szOutFileName []);

void main ()
{
	// day 1
#if 1
	// image loading and gui display
	printf ("Loading Image...\n");
	printf ("\nPress any key to continue...\n");
	load_image_demo ();
#endif

	// day 2
#if 1
	// gaussian smoothing
	printf ("\nGaussian Smoothing\n");
	printf ("\nPress any key to continue...\n");
	gaussian_smooth_demo ();
#endif

#if 1
	// median filter
	printf ("\nMedian Filtering\n");
	printf ("\nPress any key to continue...\n");
	median_filter_demo ();
#endif

#if 1
	// laplacian filter
	printf ("\nLaplacian Filtering\n");
	printf ("\nPress any key to continue...\n");
	laplacian_demo ();
#endif

#if 1
	// laplacian of gaussian filter
	printf ("\LoG Filtering\n");
	printf ("\nPress any key to continue...\n");
	LoG_filter_demo ();
#endif

#if 1
	// sobel edge filter
	printf ("\nSobel Edge Detection\n");
	printf ("\nPress any key to continue...\n");
	sobel_edge_demo ();
#endif

#if 1
	// canny edge detector
	printf ("\nCanny Edge Detection\n");
	printf ("\nPress any key to continue...\n");
	canny_edge_demo ();
#endif

#if 1
	// custom filter
	printf ("\nCustom Filter\n");
	printf ("\nPress any key to continue...\n");
	custom_filter_demo ();
#endif

	// day 3
#if 1
	// histogram equalization
	printf ("\nHistogram Equalization\n");
	printf ("\nPress any key to continue...\n");
	histogram_equalization_demo ();
#endif

#if 1
	// binary thresholding
	printf ("\nBinary Thresholding\n");
	printf ("\nPress any key to continue...\n");
	thresholding_demo ();
#endif

#if 1
	// erosion / dilation / opening / closing
	printf ("\nMorphological Operators\n");
	printf ("\nPress any key to continue...\n");
	morphology_demo ();
#endif

	// day 4
#if 1
	// connected components
	printf ("\nConnected Components\n");
	printf ("\nPress any key to continue...\n");
	connected_comp_demo ();
#endif

#if 1
	// contours
	printf ("\nContours\n");
	printf ("\nPress any key to continue...\n");
	contours_demo ();
#endif

#if 1
	// region growing
	printf ("\nRegion Growing\n");
	printf ("\nPress any key to continue...\n");
	region_grow_demo ();
#endif

#if 1
	// digital fourier transform
	printf ("\nDigital Fourier Transform (DFT) based Frequency Domain Filters\n");
	printf ("\nPress any key to continue...\n");
	freq_filter_demo (0, "output/freq_ideal.bmp");
	//freq_filter_demo (1, "output/freq_gauss.bmp");
	//freq_filter_demo (2, "output/freq_butter.bmp");
#endif
}
