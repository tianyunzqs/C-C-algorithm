#include "StdAfx.h"
#include "AnimalFeature.h"

AnimalFeature::AnimalFeature(void)
{
	for (int i=0; i<30; i++)
		UserInputFeature[i] = FALSE;
}

AnimalFeature::~AnimalFeature(void)
{
}

void AnimalFeature::Clear()
{
	for (int i=19; i<30; i++)
		UserInputFeature[i] = FALSE;
}

void AnimalFeature::Rule1(BOOL a[])
{
	if (a[0])
		UserInputFeature[19] = TRUE;
}

void AnimalFeature::Rule2(BOOL a[])
{
	if (a[1])
		UserInputFeature[19] = TRUE;
}

void AnimalFeature::Rule3(BOOL a[])
{
	if (a[2])
		UserInputFeature[20] = TRUE;
}

void AnimalFeature::Rule4(BOOL a[])
{
	if (a[3]&&a[4])
		UserInputFeature[20] = TRUE;
}

void AnimalFeature::Rule5(BOOL a[])
{
	if (a[5])
		UserInputFeature[21] = TRUE;
}

void AnimalFeature::Rule6(BOOL a[])
{
	if (a[6]&&a[7]&&a[8])
		UserInputFeature[21] = TRUE;
}

void AnimalFeature::Rule7(BOOL a[])
{
	if (a[19]&&a[9])
		UserInputFeature[22] = TRUE;
}

void AnimalFeature::Rule8(BOOL a[])
{
	if (a[19]&&a[10])
		UserInputFeature[22] = TRUE;
}

void AnimalFeature::Rule9(BOOL a[])
{
	if (a[19]&&a[21]&&a[11]&&a[15])
		UserInputFeature[23] = TRUE;
}

void AnimalFeature::Rule10(BOOL a[])
{
	if (a[19]&&a[21]&&a[11]&&a[12])
		UserInputFeature[24] = TRUE;
}

void AnimalFeature::Rule11(BOOL a[])
{
	if (a[22]&&a[13]&&a[14]&&a[15])
		UserInputFeature[25] = TRUE;
}

void AnimalFeature::Rule12(BOOL a[])
{
	if (a[22]&&a[12])
		UserInputFeature[26] = TRUE;
}

void AnimalFeature::Rule13(BOOL a[])
{
	if (a[20]&&a[13]&&a[14]&&!a[3]&&a[16])
		UserInputFeature[27] = TRUE;
}

void AnimalFeature::Rule14(BOOL a[])
{
	if (a[20]&&a[17]&&!a[3]&&a[16])
		UserInputFeature[28] = TRUE;
}

void AnimalFeature::Rule15(BOOL a[])
{
	if (a[20]&&a[18])
		UserInputFeature[29] = TRUE;
}
