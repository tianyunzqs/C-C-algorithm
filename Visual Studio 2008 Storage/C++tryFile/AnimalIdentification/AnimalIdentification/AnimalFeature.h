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

	void IsMammal(BOOL a[]);  // ���鶯��
	void IsBird(BOOL a[]);    // ��
	void IsCarnivore(BOOL a[]);  // ʳ�⶯��
	void IsUngulate(BOOL a[], BOOL b[]);  // �����ද��
	

	// ʶ����
	int IdentificationResult;

	void Identification(BOOL a[], BOOL b[]);


	BOOL IsLeopard(BOOL a[], BOOL b[]);   // ��Ǯ��
	BOOL IsTiger(BOOL a[], BOOL b[]);     // �ϻ�
	BOOL IsGiraffe(BOOL a[], BOOL b[]);   // ����¹
	BOOL IsZebra(BOOL a[], BOOL b[]);     // ����
	BOOL IsOstrich(BOOL a[], BOOL b[]);   // ����
	BOOL IsPenguin(BOOL a[], BOOL b[]);   // ���
	BOOL IsAlbatross(BOOL a[], BOOL b[]); // ������


};
