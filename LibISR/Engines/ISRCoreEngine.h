#pragma once

#include "../Utils/ISRLibSettings.h"

#include "../Objects/Highlevel//ISRFrame.h"
#include "../Objects/Highlevel//ISRShapeUnion.h"
#include "../Objects/Highlevel//ISRTrackingState.h"

#include "Lowlevel/ISRLowlevelEngine.h"
#include "Lowlevel/ISRLowlevelEngine_DA.h"
#include "Lowlevel/ISRLowlevelEngine_CPU.h"

#include "Trackers/ISRRGBDTracker.h"
#include "Trackers/ISRRGBDTracker_DA.h"
#include "Trackers/ISRRGBDTracker_CPU.h"

#include "Visualization/ISRVisualisationEngine.h"
#include "Visualization/ISRVisualisationEngine_CPU.h"
#include "Visualization/ISRVisualisationEngine_DA.h"


namespace LibISR
{
	namespace Engine
	{

		class ISRCoreEngine
		{
		private:
			Objects::ISRLibSettings *settings;

			Engine::ISRLowlevelEngine* lowLevelEngine;
			Engine::ISRTracker* tracker;

		public:

			Objects::ISRFrame *frame;
			Objects::ISRShapeUnion *shapeUnion;
			Objects::ISRTrackingState *trackingState;

			Objects::ISRView *getView(){ return frame->view;};
			Objects::ISRImageHierarchy *getImageHierarchy(){ return frame->imgHierarchy; }
			Objects::ISRVisualisationState *getRenderingState(){ return frame->rendering; }

			void processFrame(void);

			ISRCoreEngine(const Objects::ISRLibSettings *settings, const Objects::ISRCalib *calib, Vector2i d_dize, Vector2i rgb_size);
			
			~ISRCoreEngine()
			{
				delete this->frame;
				delete this->shapeUnion;
			}
		};
	}
}

