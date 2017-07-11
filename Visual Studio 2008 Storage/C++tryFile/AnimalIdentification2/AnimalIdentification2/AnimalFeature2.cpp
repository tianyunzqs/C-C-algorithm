#include "StdAfx.h"
#include "AnimalFeature2.h"

AnimalFeature2::AnimalFeature2(void)
{
	for (int i=0; i<20; i++)
		UserInputFeature[i] = FALSE;
	for (int i=0; i<10; i++)
		InferenceFeature[i] = FALSE;
}

AnimalFeature2::~AnimalFeature2(void)
{
}
