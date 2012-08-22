#pragma once

#include "Feature.h"

//! Class for extracting SIFT features.
/*!
	\ingroup FeatureExtractor

	The class implements SIFT algorithm by D. Lowe.
*/
extern "C++" class __declspec(dllexport) SiftFeature : public Feature
{
public:
	//! Constructor.
	/*!
		\param name Name of the current feature extraction procedure.
	*/
	SiftFeature(const std::string& name);

	//! Destructor.
	~SiftFeature(void);

	//! Implemented virtual method for loading algorithm specific settings from the given storage.
	/*!
		\sa Feature::LoadSettingsFromFileStorage()
	*/
	void LoadSettingsFromFileStorage(void);

private:
	//! Implemented virtual method for the algorithm.
	/*!
		\sa Feature::Process()
	*/
	void Process(void);

	//! Implemented virtual method for displaying the output.
	/*!
		\sa Feature::Visualize()
	*/
	void Visualize(void);

	cv::SiftFeatureDetector* siftDetector_;	//!< Wrapped OpenCV SIFT object.

    cv::SIFT::DetectorParams    siftDetectorParams_;
    cv::SIFT::CommonParams      siftCommonParams_;
    cv::SIFT::DescriptorParams  siftDescriptorParams_;
};

