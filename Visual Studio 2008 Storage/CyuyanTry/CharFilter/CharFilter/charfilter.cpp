#include <stdio.h>
#include <string.h>
void main()
{
	long InputCharLen;    // �����û�������ַ����ĳ���
	char InputChar1[50];  // �����û�������ַ���
	char InputChar2[50];  // �����û�������ַ���
	char InputChar3[50];  // �����û�������ַ���
	char OutputChar1[50]; // ���澭���������ַ���
	char OutputChar2[50]; // ���澭���������ַ���
	char OutputChar3[50]; // ���澭���������ַ���
	// ��������
	void stringFilter(const char *pInputStr, long lInputLen, char *pOutputStr);
	void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr);
	void arithmetic(const char *pInputStr, long lInputLen, char *pOutputStr);
	printf("������a~z���ַ��������س����������룩��"); // ��ʾ�û������ַ���
	gets(InputChar1); // �����û�������ַ���
	strcpy(InputChar2, InputChar1); // ��������InputChar1�����е��ַ������Ƶ�InputChar2������
	strcpy(InputChar3, InputChar1); // ��������InputChar1�����е��ַ������Ƶ�InputChar3������
	InputCharLen = strlen(InputChar1); // �����û�������ַ����ĳ���
	stringFilter(InputChar1, InputCharLen, OutputChar1); // �����ַ������˺���
	stringZip(InputChar2, InputCharLen, OutputChar2);    // �����ַ���ѹ������
	arithmetic(InputChar3, InputCharLen, OutputChar3);
}

// ͨ����������һ��Сд��ĸ(a~z)��ɵ��ַ��������дһ���ַ������˳���
// ���ַ����г��ֶ����ͬ���ַ��������״γ��ֵ��ַ����˵���
// �����ַ�����abacacde�����˽��Ϊ��abcde����

/* Ҫ��ʵ�ֺ�����
void stringFilter(const char *pInputStr, long lInputLen, char *pOutputStr);
�����롿 pInputStr��  �����ַ���
         lInputLen��  �����ַ�������        
������� pOutputStr�� ����ַ������ռ��Ѿ����ٺã��������ַ����ȳ���
��ע�⡿ֻ��Ҫ��ɸú��������㷨���м䲻��Ҫ���κ�IO���������
ʾ��
���룺��deefd��        �������def��
���룺��afafafaf��     �������af��
���룺��pppppppp��     �������p��
*/

// main�����Ѿ����أ����ﱣ�����û��Ĳ�����ڣ�������������ʵ�ֺ��������Ե���printf��ӡ���
// ��ǰ�����ʹ�������������ԣ�ֻҪ��֤���ճ�������ȷִ�м���
// �ú���ʵ�ֿ��������޸ģ����ǲ�Ҫ�ı亯��ԭ�͡�һ��Ҫ��֤�������в���Ӱ��
void stringFilter(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	int i,j,count; // ����ѭ������
	int tarlen = 1; // ��������ַ���ָ������ĳ��ȣ�Ŀ���ַ����ĳ��ȣ�

	*pOutputStr = *pInputStr; // ���û�����ĵ�һ���ַ�����������ַ�ָ���ַ��
	for(i=1; i<lInputLen; i++)
	{
		count = 0; // ÿ��ȫ���Ƚ���ϣ��ͽ��Ƚϴ�������������
		// ���û�����ĵ�i���ַ�������ַ�ָ���е��ַ�����Ƚϣ��������ַ�ָ�����Ƿ���ڸ��ַ�
		// �����ڣ����������ַ����������ڣ��Ƚϴ�����������һ�������������ֵ�����ָ�����ַ�������
		// ��ȣ�������ʱ��������ַ���ȫ���Ƚ���ϣ���������ַ�����û�и��ַ������򽫸��ַ�д�����
		// �ַ���ָ���С�
		for(j=0; j<tarlen; j++)		
		{
			if(*(pInputStr+i) == *(pOutputStr+j)) // ����
				break;
			else  // ������
				count++; // �Ƚϼ�������һ
		}
		if(count == tarlen) // ����Ƚϼ�������ֵ��������ַ������ȣ��򽫴˴αȽϵ��ַ�д������ַ�ָ����
		{
			*(pOutputStr+tarlen) = *(pInputStr+i); // ���˴αȽϵ��ַ�д������ַ�ָ����
			tarlen++; // ����ַ����ĳ��ȼ�һ
		}
	}
	// ��ӡ���˺���ַ���
	printf("���˺���ַ�����");
	for(j=0; j<tarlen; j++)
		printf("%c",*(pOutputStr+j));
	printf("\n");
}


// ͨ����������һ��Сд��ĸ(a~z)��ɵ��ַ�����
// ���дһ���ַ���ѹ�����򣬽��ַ�����������ϯ���ظ���ĸ����ѹ���������ѹ������ַ�����
// ѹ������
// 1. ��ѹ�������ظ����ֵ��ַ��������ַ���"abcbc"�����������ظ��ַ���ѹ������ַ�������"abcbc".
// 2. ѹ���ֶεĸ�ʽΪ"�ַ��ظ��Ĵ���+�ַ�"�����磺�ַ���"xxxyyyyyyz"ѹ����ͳ�Ϊ"3x6yz"
/* Ҫ��ʵ�ֺ�����
void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr);
�����롿 pInputStr��  �����ַ���
         lInputLen��  �����ַ�������        
������� pOutputStr�� ����ַ������ռ��Ѿ����ٺã��������ַ����ȳ���
��ע�⡿ֻ��Ҫ��ɸú��������㷨���м䲻��Ҫ���κ�IO���������
ʾ��
���룺��cccddecc��   �������3c2de2c��
���룺��adef��     �������adef��
���룺��pppppppp�� �������8p��
*/
void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	int i,j,k,count; // ����ѭ������
	char *temp, b[50]; // ����һ���ַ���ָ�뼰�ַ�����
	count = 1; // ������ͬ�ַ���������ʼ��
	j = 1; // ����pInputStr�е�ǰ�����ַ�ָʾ����j-1����ʾ��ǰ�������ַ�
	k = 0; // ���pOutputStr���ַ����ĳ���
	temp = b; // ���ַ�ָ��ָ���ַ�������׵�ַ�����������һ���ַ����飬���ַ�ָ����ָ����ַ�û�ڴ�ռ䣩
	*temp = *pInputStr; // ȡ�������ַ����ĵ�һ���ַ���������b[0]�У�

	// ����ȡ�������ַ����е�ÿһ���ַ��������м�ָ��temp��ָ��ĵ�ַ�У�,Ȼ�������ַ������ڸ��ַ�����
	// �������ַ�����ַ���Ƚϣ�����ͬ����������ͬ�ַ���������һ�������Ƚϣ�������ͬ�����ж�
	// ������ͬ�ַ�����������ֵ��Ϊ1˵�����ַ���������ֱ��д�����������1��˵�����ַ���������Ҫд��������
	// �ַ���
	while(1)
	{
		for(i=j; i<=lInputLen; i++)
		{
			// ��ǰ����ָ��ָ����ַ���*temp�б�����ַ�����ͬ
			// ����i == lInputLen˵�������ַ������ַ���ȫ���Ƚ����
			if(*(pInputStr+i) != *temp || i == lInputLen)
			{
				// ���������ͬ�ַ�����������ֵΪ1��˵�����ַ���������ֱ��д�����
				if(count == 1)
					*(pOutputStr+k++) = *temp;
				// ����1��˵�����ַ���������Ҫд���������ַ�
				else
				{
					*(pOutputStr+k++) = 48+count; // ������ת��Ϊ�ַ����ͣ������ַ������Ϊ9��
					*(pOutputStr+k++) = *temp;
				}
				j = j + count; // ������һ�������ַ���ʼ�Ƚϵ�λ��
				*temp = *(pInputStr+j-1); // ȡ�������ַ�������һ�������ַ�
				count = 1; // ������ͬ�ַ���������һ���൱����������ã�
				break; // �����ַ��ѱȽ���ϣ������˴������ַ��ıȽϣ�������һ�������ַ��ıȽ�
			}	
			else // ��ǰ����ָ��ָ����ַ���*temp�б�����ַ���ͬ��˵�����ַ���2�����������ַ�
				count++; // ������ͬ�ַ���������һ
		}
		// �����һ�������ַ���ʼ�Ƚϵ�λ���������ַ�����ĩβ����˵����ȫ���Ƚ����
		if(j >= lInputLen)
		{
			*(pOutputStr+k) = *temp; // ���ĩβ�ַ�����������ֱ��д��
			break; // ȫ���Ƚ����
		}
	}
	// ��ӡѹ������ַ���
	printf("ѹ������ַ�����");
	for(i=0; i<=k; i++)
		printf("%c",*(pOutputStr+i));
	printf("\n");
}


// ͨ����������100�����������ļӡ�������ʽ�����дһ����������������ַ�����
// �����ַ����ĸ�ʽΪ����������1 ����� ������2���������������롰�������֮����һ���ո������
// ����˵����
// 1. ������Ϊ������������Ҫ���Ǽ���������������
// 2. ��������ʽ��ʽ����������Ϊ��0����
/* Ҫ��ʵ�ֺ�����
void arithmetic(const char *pInputStr, long lInputLen, char *pOutputStr);
�����롿 pInputStr��  �����ַ���
         lInputLen��  �����ַ�������        
������� pOutputStr�� ����ַ������ռ��Ѿ����ٺã��������ַ����ȳ���
��ע�⡿ֻ��Ҫ��ɸú��������㷨���м䲻��Ҫ���κ�IO���������
ʾ��
���룺��4 + 7��  �������11��
���룺��4 - 7��  �������-3��
���룺��9 ++ 7��  �������0�� ע����ʽ����*/

void arithmetic(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	int i,j,k,count,flag,PlusLocation; // ����
	char c[50];
	int num[5];
	char *tp;
	tp = c;
	j = 0;
	k = 0;
	flag = 0;
	count = 0;
	for(i=0; i<lInputLen; i++)
	{
		if(*(pInputStr+i) == '+' || *(pInputStr+i) == '-')
		{				
			k++;
			if(k>1)
			{	
				flag = 1;
				printf("0 ע����ʽ����\n");
				break;
			}
			else
				PlusLocation = i;
		}
	}
	if(!flag)
	{
		for(i=0; i<PlusLocation-1; i++)
		{
			*(tp+i) = *(pInputStr+i);
			count++;
		}
		if(count<2)
			num[0] = *(tp) - 48;
		else
			num[0] = (*(tp)-48)*10 + (*(tp+1)-48);

		count = 0;
		for(i=PlusLocation+2; i<lInputLen; i++)
		{
			*(tp+i) = *(pInputStr+i);
			count++;
		}
		if(count<2)
			num[1] = *(tp+PlusLocation+2) - 48;
		else
			num[1] = (*(tp+PlusLocation+2)-48)*10 + (*(tp+PlusLocation+2+1)-48);
		printf("%d %c %d����������",num[0], *(pInputStr+PlusLocation), num[1]);
		if(*(pInputStr+PlusLocation) == '+')
			printf("%d\n", num[0]+num[1]);
		else
			printf("%d\n", num[0]-num[1]);
	}
}