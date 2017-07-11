#include "StdAfx.h"
#include "AnimalFeature.h"

AnimalFeature::AnimalFeature(void)
{
	for (int i=0; i<20; i++)
		UserInputFeature[i] = FALSE;
	for (int i=0; i<4; i++)
		InferenceFeature[i] = FALSE;
	IdentificationResult = 0;
}

AnimalFeature::~AnimalFeature(void)
{
}

void AnimalFeature::IsMammal(BOOL a[])
{
	if (a[0] || a[1])  // 规则1、2
		InferenceFeature[0] = TRUE;	
}

void AnimalFeature::IsBird(BOOL a[])
{
	if (a[2] || (a[3]&&a[4])) // 规则3、4
		InferenceFeature[1] = TRUE;
}

void AnimalFeature::IsCarnivore(BOOL a[])
{
	if (a[5] || a[6]&&a[7]&&a[8]) // 规则5、6
		InferenceFeature[2] = TRUE;
}

void AnimalFeature::IsUngulate(BOOL a[], BOOL b[])
{
	if (b[0]&&a[9] || b[0]&&a[10])  // 规则7、8
		InferenceFeature[3] = TRUE;
}

/******************识别是哪个动物***********************/
void AnimalFeature::Identification(BOOL a[], BOOL b[])
{
	//if (b[0]&&b[2]&&a[11]&&a[15])   // 规则9	
	//	IdentificationResult = 1;
	//if (b[0]&&b[2]&&a[11]&&a[12])  // 规则10
	//	IdentificationResult = 2;
	//if (b[3]&&a[13]&&a[14]&&a[15])  // 规则11
	//	IdentificationResult = 3;
	//if (b[3]&&a[12])     // 规则12
	//	IdentificationResult = 4;
	//if (b[1]&&a[13]&&a[14]&&!a[3]&&a[16])  // 规则13
	//	IdentificationResult = 5;
	//if (b[1]&&a[17]&&!a[3]&&a[16])   // 规则14
	//	IdentificationResult = 6;
	//if (b[1]&&a[18])    // 规则15
	//	IdentificationResult = 7;

	if (IsLeopard(a,b))   // 规则9	
		IdentificationResult = 1;
	if (IsTiger(a,b))  // 规则10
		IdentificationResult = 2;
	if (IsGiraffe(a,b))  // 规则11
		IdentificationResult = 3;
	if (IsZebra(a,b))     // 规则12
		IdentificationResult = 4;
	if (IsOstrich(a,b))  // 规则13
		IdentificationResult = 5;
	if (IsPenguin(a,b))   // 规则14
		IdentificationResult = 6;
	if (IsAlbatross(a,b))    // 规则15
		IdentificationResult = 7;
}


BOOL AnimalFeature::IsLeopard(BOOL a[], BOOL b[])
{
	BOOL a0[20],b0[4],flag1=FALSE,flag=FALSE;
	for (int i=0; i<20;i++)
	{
		if (i<4)
			b0[i] = FALSE;
		a0[i] = FALSE;
	}
	b0[0] = TRUE; b0[2] = TRUE;
	a0[11] = TRUE; a0[15] = TRUE;

	for (int i=0; i<4; i++)
	{
		if(b[i]==b0[i])
			flag1 = TRUE;
		else
		{
			flag1 = FALSE;
			break;
		}
	}
	for (int j=0; j<20; j++)
	{
		if (a[j]==a0[j])
			flag = TRUE;
		else
		{
			flag = FALSE;
			break;
		}
	}
	return(flag);
}

BOOL AnimalFeature::IsTiger(BOOL a[], BOOL b[])
{
	BOOL a0[20],b0[4],flag1=FALSE,flag=FALSE;
	for (int i=0; i<20;i++)
	{
		if (i<4)
			b0[i] = FALSE;
		a0[i] = FALSE;
	}
	b0[0] = TRUE; b0[2] = TRUE;
	a0[11] = TRUE; a0[12] = TRUE;
	for (int i=0; i<4; i++)
	{
		if(b[i]==b0[i])
			flag1 = TRUE;
		else
		{
			flag1 = FALSE;
			break;
		}
	}
	for (int j=0; j<20; j++)
	{
		if (a[j]==a0[j])
			flag = TRUE;
		else
		{
			flag = FALSE;
			break;
		}
	}
	return(flag);
}

BOOL AnimalFeature::IsGiraffe(BOOL a[], BOOL b[])
{
	BOOL a0[20],b0[4],flag1=FALSE,flag=FALSE;
	for (int i=0; i<20;i++)
	{
		if (i<4)
			b0[i] = FALSE;
		a0[i] = FALSE;
	}
	b0[3] = TRUE; 
	a0[13] = TRUE; a0[14] = TRUE; a0[15] = TRUE;
	for (int i=0; i<4; i++)
	{
		if(b[i]==b0[i])
			flag1 = TRUE;
		else
		{
			flag1 = FALSE;
			break;
		}
	}
	for (int j=0; j<20; j++)
	{
		if (a[j]==a0[j])
			flag = TRUE;
		else
		{
			flag = FALSE;
			break;
		}
	}
	return(flag);
}

BOOL AnimalFeature::IsZebra(BOOL a[], BOOL b[])
{
	BOOL a0[20],b0[4],flag1=FALSE,flag=FALSE;
	for (int i=0; i<20;i++)
	{
		if (i<4)
			b0[i] = FALSE;
		a0[i] = FALSE;
	}
	b0[3] = TRUE; 
	a0[12] = TRUE;
	for (int i=0; i<4; i++)
	{
		if(b[i]==b0[i])
			flag1 = TRUE;
		else
		{
			flag1 = FALSE;
			break;
		}
	}
	for (int j=0; j<20; j++)
	{
		if (a[j]==a0[j])
			flag = TRUE;
		else
		{
			flag = FALSE;
			break;
		}
	}
	return(flag);
}

BOOL AnimalFeature::IsOstrich(BOOL a[], BOOL b[])
{
	BOOL a0[20],b0[4],flag1=FALSE,flag=FALSE;
	for (int i=0; i<20;i++)
	{
		if (i<4)
			b0[i] = FALSE;
		a0[i] = FALSE;
	}
	b0[1] = TRUE; 
	a0[13] = TRUE; a0[14] = TRUE; a0[16] = TRUE;
	for (int i=0; i<4; i++)
	{
		if(b[i]==b0[i])
			flag1 = TRUE;
		else
		{
			flag1 = FALSE;
			break;
		}
	}
	for (int j=0; j<20; j++)
	{
		if (a[j]==a0[j])
			flag = TRUE;
		else
		{
			flag = FALSE;
			break;
		}
	}
	return(flag);
}

BOOL AnimalFeature::IsPenguin(BOOL a[], BOOL b[])
{
	BOOL a0[20],b0[4],flag1=FALSE,flag=FALSE;
	for (int i=0; i<20;i++)
	{
		if (i<4)
			b0[i] = FALSE;
		a0[i] = FALSE;
	}
	b0[1] = TRUE; 
	a0[16] = TRUE; a0[17] = TRUE;
	for (int i=0; i<4; i++)
	{
		if(b[i]==b0[i])
			flag1 = TRUE;
		else
		{
			flag1 = FALSE;
			break;
		}
	}
	for (int j=0; j<20; j++)
	{
		if (a[j]==a0[j])
			flag = TRUE;
		else
		{
			flag = FALSE;
			break;
		}
	}
	return(flag);
}

BOOL AnimalFeature::IsAlbatross(BOOL a[], BOOL b[])
{
	BOOL a0[20],b0[4],flag1=FALSE,flag=FALSE;
	for (int i=0; i<20;i++)
	{
		if (i<4)
			b0[i] = FALSE;
		a0[i] = FALSE;
	}
	b0[1] = TRUE; 
	a0[18] = TRUE;
	for (int i=0; i<4; i++)
	{
		if(b[i]==b0[i])
			flag1 = TRUE;
		else
		{
			flag1 = FALSE;
			break;
		}
	}
	for (int j=0; j<20; j++)
	{
		if (a[j]==a0[j])
			flag = TRUE;
		else
		{
			flag = FALSE;
			break;
		}
	}
	return(flag);
}