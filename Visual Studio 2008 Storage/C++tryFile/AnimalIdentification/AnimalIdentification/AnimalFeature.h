#pragma once

class AnimalFeature
{
public:
	AnimalFeature(void);
	~AnimalFeature(void);

public:
	BOOL UserInputFeature[20];
	BOOL InferenceFeature[4]; 

public:

	void IsMammal(BOOL a[]);  // 哺乳动物
	void IsBird(BOOL a[]);    // 鸟
	void IsCarnivore(BOOL a[]);  // 食肉动物
	void IsUngulate(BOOL a[], BOOL b[]);  // 有蹄类动物
	

	// 识别结果
	int IdentificationResult;

	void Identification(BOOL a[], BOOL b[]);


	BOOL IsLeopard(BOOL a[], BOOL b[]);   // 金钱豹
	BOOL IsTiger(BOOL a[], BOOL b[]);     // 老虎
	BOOL IsGiraffe(BOOL a[], BOOL b[]);   // 长颈鹿
	BOOL IsZebra(BOOL a[], BOOL b[]);     // 斑马
	BOOL IsOstrich(BOOL a[], BOOL b[]);   // 鸵鸟
	BOOL IsPenguin(BOOL a[], BOOL b[]);   // 企鹅
	BOOL IsAlbatross(BOOL a[], BOOL b[]); // 信天翁


};
