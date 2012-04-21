#pragma once

/*!
	\defgroup FeatureExtractor FeatureExtractor module.
*/

#include "Thread.h"

#include "opencv2/opencv.hpp"

//! Class for extracting SIFT features.
/*!
	\ingroup FeatureExtractor
*/
extern "C++" class __declspec(dllexport) SiftFeature : public Thread
{
public:
	//! Constructor.
	/*!
		\param id
		\param frame
	*/
	SiftFeature(int id, cv::Mat& frame);

	//! Destructor.
	~SiftFeature(void);

	//! Implemented thread main.
	/*!
		\sa Thread::Run()
	*/
	virtual void* Run();

	cv::Mat frame_;

private:
	int id_;
	//pthread_mutex_t updateMutex;
};
