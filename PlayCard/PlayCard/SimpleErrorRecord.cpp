// �򵥴����¼
// ����һ���򵥴����¼����Сģ�飬�ܹ���¼����Ĵ������ڵ��ļ����ƺ��кš� 
// ����:
// 1.��¼���8�������¼������ͬ�Ĵ����¼(���ļ����ƺ��к���ȫƥ��)ֻ��¼һ��������������ӣ�
//   (�ļ����ڵ�Ŀ¼��ͬ���ļ������к���ͬҲҪ�ϲ�)
// 2.����16���ַ����ļ����ƣ�ֻ��¼�ļ��������Ч16���ַ���
//   (����ļ�����ͬ����ֻ���ļ����ĺ�16���ַ����к���ͬ��Ҳ��Ҫ�ϲ�)
// 3.������ļ����ܴ�·������¼�ļ����Ʋ��ܴ�·��

// ��������:
// һ�л�����ַ�����ÿ�а�����·���ļ����ƣ��кţ��Կո������

//    �ļ�·��Ϊwindows��ʽ
//    �磺E:\V1R2\product\fpgadrive.c 1325

// �������:
// �����еļ�¼ͳ�Ʋ�������������ʽ���ļ�������������Ŀ��һ���ո��������: fpgadrive.c 1325 1 

//   ���������Ŀ�Ӷൽ��������Ŀ��ͬ������£����������һ�γ���˳������
//   �������8����¼����ֻ���ǰ8����¼.
//   ����ļ����ĳ��ȳ���16���ַ�����ֻ�����16���ַ�

// ��������:
// E:\V1R2\product\fpgadrive.c 1325

// �������:
// fpgadrive.c 1325 1

#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct ErrorInfo
{
	string FileName;
	int ErrorLineNo;
	int SumCount;
	int AppearRank;
};
void main()
{
	ErrorInfo Record[200];
	memset(Record, 0, sizeof(Record));
	string s[100];
	s[0] = "e:\\1\\aa3.txt 3";
	s[1] = "e:\\3\\aa1.txt 2";
	s[2] = "e:\\2\\aa2.txt 3";
	s[3] = "e:\\3\\aa1.txt 1";
	s[4] = "e:\\1\\aa1.txt 3";
	s[5] = "e:\\3\\aa1.txt 2";
	s[6] = "e:\\1\\aa3.txt 3";
	s[7] = "e:\\2\\aa3.txt 2";
	s[8] = "e:\\1\\aa1.txt 2";
	s[9] = "e:\\3\\aa3.txt 2";
	s[10] = "e:\\1\\aa2.txt 2";
	s[11] = "e:\\1\\aa3.txt 1";
	s[12] = "e:\\1\\aa3.txt 1";
	s[13] = "e:\\2\\aa3.txt 2";
	s[15-1] = "e:\\1\\aa2.txt 1";
	s[16-1] = "e:\\3\\aa1.txt 2";
	s[17-1] = "e:\\1\\aa1.txt 3";
	s[18-1] = "e:\\2\\aa1.txt 1";
	s[19-1] = "e:\\3\\aa3.txt 2";
	s[20-1] = "e:\\1\\aa1.txt 1";
	s[21-1] = "e:\\2\\aa2.txt 2";
	s[22-1] = "e:\\3\\aa3.txt 2";
	s[23-1] = "e:\\1\\aa2.txt 1";
	s[24-1] = "e:\\1\\aa3.txt 2";
	s[25-1] = "e:\\1\\aa3.txt 3";
	s[26-1] = "e:\\1\\aa2.txt 3";
	s[27-1] = "e:\\3\\aa1.txt 3";
	s[28-1] = "e:\\2\\aa2.txt 2";
	s[29-1] = "e:\\1\\aa1.txt 1";
	s[30-1] = "e:\\2\\aa3.txt 1";
	s[31-1] = "e:\\3\\aa1.txt 1";
	s[32-1] = "e:\\2\\aa1.txt 3";
	s[33-1] = "e:\\3\\aa3.txt 2";
	s[34-1] = "e:\\1\\aa3.txt 3";
	s[35-1] = "e:\\2\\aa3.txt 3";
	s[36-1] = "e:\\1\\aa2.txt 3";
	s[37-1] = "e:\\2\\aa2.txt 1";
	s[38-1] = "e:\\1\\aa3.txt 1";
	s[39-1] = "e:\\1\\aa3.txt 1";
	s[40-1] = "e:\\3\\aa3.txt 3";
	s[41-1] = "e:\\3\\aa3.txt 2";
	s[42-1] = "e:\\1\\aa2.txt 3";
	s[43-1] = "e:\\1\\aa2.txt 3";
	s[44-1] = "e:\\1\\aa2.txt 3";
	s[45-1] = "e:\\1\\aa1.txt 1";
	s[46-1] = "e:\\2\\aa3.txt 1";
	s[47-1] = "e:\\3\\aa3.txt 1";
	s[48-1] = "e:\\2\\aa3.txt 2";
	s[49-1] = "e:\\3\\aa1.txt 3";
	s[50-1] = "e:\\2\\aa2.txt 2";
	s[51-1] = "e:\\2\\aa2.txt 2";
	s[52-1] = "e:\\2\\aa3.txt 1";
	s[53-1] = "e:\\1\\aa3.txt 3";
	s[54-1] = "e:\\3\\aa1.txt 2";
	s[55-1] = "e:\\3\\aa2.txt 2";
	s[56-1] = "e:\\1\\aa2.txt 1";
	s[57-1] = "e:\\2\\aa2.txt 1";
	s[58-1] = "e:\\2\\aa1.txt 2";
	s[59-1] = "e:\\2\\aa2.txt 1";
	s[60-1] = "e:\\1\\aa2.txt 1";
	s[61-1] = "e:\\2\\aa3.txt 1";
	s[62-1] = "e:\\2\\aa2.txt 1";
	s[63-1] = "e:\\2\\aa1.txt 2";
	s[64-1] = "e:\\3\\aa2.txt 3";
	s[65-1] = "e:\\3\\aa1.txt 3";
	s[66-1] = "e:\\2\\aa2.txt 3";
	s[67-1] = "e:\\2\\aa3.txt 1";
	s[68-1] = "e:\\3\\aa3.txt 2";
	s[69-1] = "e:\\2\\aa3.txt 1";
	s[70-1] = "e:\\1\\aa1.txt 2";
	s[71-1] = "e:\\3\\aa3.txt 1";
	s[72-1] = "e:\\3\\aa1.txt 1";
	s[73-1] = "e:\\2\\aa2.txt 3";
	s[74-1] = "e:\\3\\aa3.txt 2";
	s[75-1] = "e:\\2\\aa1.txt 3";
	s[76-1] = "e:\\1\\aa3.txt 3";
	s[77-1] = "e:\\3\\aa2.txt 1";
	s[78-1] = "e:\\2\\aa1.txt 3";
	s[79-1] = "e:\\1\\aa3.txt 3";
	s[80-1] = "e:\\2\\aa2.txt 2";
	s[81-1] = "e:\\1\\aa1.txt 2";
	s[82-1] = "e:\\3\\aa1.txt 1";
	s[83-1] = "e:\\1\\aa3.txt 1";
	s[84-1] = "e:\\3\\aa1.txt 2";
	s[85-1] = "e:\\1\\aa1.txt 2";
	s[86-1] = "e:\\1\\aa1.txt 3";
	s[87-1] = "e:\\3\\aa1.txt 1";
	s[88-1] = "e:\\3\\aa1.txt 1";
	s[89-1] = "e:\\2\\aa3.txt 3";
	s[90-1] = "e:\\2\\aa2.txt 1";
	s[91-1] = "e:\\2\\aa1.txt 2";
	s[92-1] = "e:\\2\\aa2.txt 1";
	s[93-1] = "e:\\3\\aa2.txt 3";
	s[94-1] = "e:\\1\\aa2.txt 1";
	s[95-1] = "e:\\3\\aa2.txt 2";
	s[96-1] = "e:\\2\\aa1.txt 1";
	s[97-1] = "e:\\2\\aa3.txt 3";
	s[98-1] = "e:\\1\\aa1.txt 2";
	s[99-1] = "e:\\1\\aa1.txt 1";
	s[100-1] = "e:\\1\\aa1.txt 2";
	string str;
	int k=0, m=0;
	while(m<100)
	{
		str = s[m++];
		int FileNameStartLoc = str.find_last_of('\\');
		int FileNameEndLoc   = str.find_first_of(' ', FileNameStartLoc+1);
		Record[k].FileName    = str.substr(FileNameStartLoc+1, FileNameEndLoc-FileNameStartLoc-1);
		Record[k].ErrorLineNo = atoi(str.substr(FileNameEndLoc+1).c_str());
		Record[k].SumCount    = 1;
		Record[k].AppearRank  = k+1;		
		for(int i=0; i<k; ++i)
		{
			if(Record[k].FileName==Record[i].FileName && Record[k].ErrorLineNo==Record[i].ErrorLineNo)
			{
				Record[i].SumCount++;
				//Record[k].FileName    = "";
				//Record[k].ErrorLineNo = 0;
				//Record[k].SumCount    = 0;
				//Record[k].AppearRank  = 0;
				k--;
				break;
			}
		}
		k++;
	}
	// �������
	for(int i=0; i<k; ++i)
	{
		int exchange = 0;
		for(int j=1; j<k-i; ++j)
		{
			if(Record[j-1].SumCount > Record[j].SumCount)
			{
				ErrorInfo temp;
				temp = Record[j-1];
				Record[j-1] = Record[j];
				Record[j] = temp;
				exchange = 1;
			}
			else if(Record[j-1].SumCount==Record[j].SumCount && Record[j-1].AppearRank < Record[j].AppearRank)
			{
				ErrorInfo temp;
				temp = Record[j-1];
				Record[j-1] = Record[j];
				Record[j] = temp;
				exchange = 1;
			}
		}
		if(exchange == 0)
			break;
	}
	for(int i=k-1; i>=0 && i>k-9; --i)
	{
		if(Record[i].FileName.length() > 16)
			Record[i].FileName = Record[i].FileName.substr(Record[i].FileName.length()-16, 16);
		cout<<Record[i].FileName<<ends<<Record[i].ErrorLineNo<<ends<<Record[i].SumCount<<endl;
	}
}


//#include <iostream>
//#include <vector>
//#include <string>
//#include <string.h>
//using namespace std;
//struct ErrorInfo
//{
//	string FileName;
//	int ErrorLineNo;
//	int SumCount;
//};
//int main()
//{
//	ErrorInfo Record;
//	vector<ErrorInfo> RS;
//	string s[100];
//	s[0] = "e:\\1\\aa3.txt 3";
//	s[1] = "e:\\3\\aa1.txt 2";
//	s[2] = "e:\\2\\aa2.txt 3";
//	s[3] = "e:\\3\\aa1.txt 1";
//	s[4] = "e:\\1\\aa1.txt 3";
//	s[5] = "e:\\3\\aa1.txt 2";
//	s[6] = "e:\\1\\aa3.txt 3";
//	s[7] = "e:\\2\\aa3.txt 2";
//	s[8] = "e:\\1\\aa1.txt 2";
//	s[9] = "e:\\3\\aa3.txt 2";
//	s[10] = "e:\\1\\aa2.txt 2";
//	s[11] = "e:\\1\\aa3.txt 1";
//	s[12] = "e:\\1\\aa3.txt 1";
//	s[13] = "e:\\2\\aa3.txt 2";
//	s[15-1] = "e:\\1\\aa2.txt 1";
//	s[16-1] = "e:\\3\\aa1.txt 2";
//	s[17-1] = "e:\\1\\aa1.txt 3";
//	s[18-1] = "e:\\2\\aa1.txt 1";
//	s[19-1] = "e:\\3\\aa3.txt 2";
//	s[20-1] = "e:\\1\\aa1.txt 1";
//	s[21-1] = "e:\\2\\aa2.txt 2";
//	s[22-1] = "e:\\3\\aa3.txt 2";
//	s[23-1] = "e:\\1\\aa2.txt 1";
//	s[24-1] = "e:\\1\\aa3.txt 2";
//	s[25-1] = "e:\\1\\aa3.txt 3";
//	s[26-1] = "e:\\1\\aa2.txt 3";
//	s[27-1] = "e:\\3\\aa1.txt 3";
//	s[28-1] = "e:\\2\\aa2.txt 2";
//	s[29-1] = "e:\\1\\aa1.txt 1";
//	s[30-1] = "e:\\2\\aa3.txt 1";
//	s[31-1] = "e:\\3\\aa1.txt 1";
//	s[32-1] = "e:\\2\\aa1.txt 3";
//	s[33-1] = "e:\\3\\aa3.txt 2";
//	s[34-1] = "e:\\1\\aa3.txt 3";
//	s[35-1] = "e:\\2\\aa3.txt 3";
//	s[36-1] = "e:\\1\\aa2.txt 3";
//	s[37-1] = "e:\\2\\aa2.txt 1";
//	s[38-1] = "e:\\1\\aa3.txt 1";
//	s[39-1] = "e:\\1\\aa3.txt 1";
//	s[40-1] = "e:\\3\\aa3.txt 3";
//	s[41-1] = "e:\\3\\aa3.txt 2";
//	s[42-1] = "e:\\1\\aa2.txt 3";
//	s[43-1] = "e:\\1\\aa2.txt 3";
//	s[44-1] = "e:\\1\\aa2.txt 3";
//	s[45-1] = "e:\\1\\aa1.txt 1";
//	s[46-1] = "e:\\2\\aa3.txt 1";
//	s[47-1] = "e:\\3\\aa3.txt 1";
//	s[48-1] = "e:\\2\\aa3.txt 2";
//	s[49-1] = "e:\\3\\aa1.txt 3";
//	s[50-1] = "e:\\2\\aa2.txt 2";
//	s[51-1] = "e:\\2\\aa2.txt 2";
//	s[52-1] = "e:\\2\\aa3.txt 1";
//	s[53-1] = "e:\\1\\aa3.txt 3";
//	s[54-1] = "e:\\3\\aa1.txt 2";
//	s[55-1] = "e:\\3\\aa2.txt 2";
//	s[56-1] = "e:\\1\\aa2.txt 1";
//	s[57-1] = "e:\\2\\aa2.txt 1";
//	s[58-1] = "e:\\2\\aa1.txt 2";
//	s[59-1] = "e:\\2\\aa2.txt 1";
//	s[60-1] = "e:\\1\\aa2.txt 1";
//	s[61-1] = "e:\\2\\aa3.txt 1";
//	s[62-1] = "e:\\2\\aa2.txt 1";
//	s[63-1] = "e:\\2\\aa1.txt 2";
//	s[64-1] = "e:\\3\\aa2.txt 3";
//	s[65-1] = "e:\\3\\aa1.txt 3";
//	s[66-1] = "e:\\2\\aa2.txt 3";
//	s[67-1] = "e:\\2\\aa3.txt 1";
//	s[68-1] = "e:\\3\\aa3.txt 2";
//	s[69-1] = "e:\\2\\aa3.txt 1";
//	s[70-1] = "e:\\1\\aa1.txt 2";
//	s[71-1] = "e:\\3\\aa3.txt 1";
//	s[72-1] = "e:\\3\\aa1.txt 1";
//	s[73-1] = "e:\\2\\aa2.txt 3";
//	s[74-1] = "e:\\3\\aa3.txt 2";
//	s[75-1] = "e:\\2\\aa1.txt 3";
//	s[76-1] = "e:\\1\\aa3.txt 3";
//	s[77-1] = "e:\\3\\aa2.txt 1";
//	s[78-1] = "e:\\2\\aa1.txt 3";
//	s[79-1] = "e:\\1\\aa3.txt 3";
//	s[80-1] = "e:\\2\\aa2.txt 2";
//	s[81-1] = "e:\\1\\aa1.txt 2";
//	s[82-1] = "e:\\3\\aa1.txt 1";
//	s[83-1] = "e:\\1\\aa3.txt 1";
//	s[84-1] = "e:\\3\\aa1.txt 2";
//	s[85-1] = "e:\\1\\aa1.txt 2";
//	s[86-1] = "e:\\1\\aa1.txt 3";
//	s[87-1] = "e:\\3\\aa1.txt 1";
//	s[88-1] = "e:\\3\\aa1.txt 1";
//	s[89-1] = "e:\\2\\aa3.txt 3";
//	s[90-1] = "e:\\2\\aa2.txt 1";
//	s[91-1] = "e:\\2\\aa1.txt 2";
//	s[92-1] = "e:\\2\\aa2.txt 1";
//	s[93-1] = "e:\\3\\aa2.txt 3";
//	s[94-1] = "e:\\1\\aa2.txt 1";
//	s[95-1] = "e:\\3\\aa2.txt 2";
//	s[96-1] = "e:\\2\\aa1.txt 1";
//	s[97-1] = "e:\\2\\aa3.txt 3";
//	s[98-1] = "e:\\1\\aa1.txt 2";
//	s[99-1] = "e:\\1\\aa1.txt 1";
//	s[100-1] = "e:\\1\\aa1.txt 2";
//	string str;
//	int k=0, m=0;
//	while(m<100)
//	{
//		str = s[m++];
		  // Ѱ�����һ��'\'��λ��
//        int FileNameStartLoc = str.find_last_of('\\');
		  // Ѱ�ҵ�һ���ո�����λ��
//        int FileNameEndLoc   = str.find_first_of(' ', FileNameStartLoc+1);
		  // ��ȡ�ļ��������һ��'\'�͵�һ���ո�֮����ַ�Ϊ�ļ���
//        Record.FileName    = str.substr(FileNameStartLoc+1, FileNameEndLoc-FileNameStartLoc-1);		
		  // ��ȡ�кţ��ļ���������ַ�Ϊ�кţ���ȥ�ո��ַ���
//        Record.ErrorLineNo = atoi(str.substr(FileNameEndLoc+1).c_str());
		  // ��¼���ֵĴ���
//        Record.SumCount=1;
// 		  RS.push_back(Record); // ����ǰ��¼����RS��
//        for(int i=0; i<k; ++i)  // �ϲ��ļ������кŶ���ͬ�ļ�¼
//        {
//            if(RS[k].FileName==RS[i].FileName && RS[k].ErrorLineNo==RS[i].ErrorLineNo)
//            {
//                RS[i].SumCount++;
//                RS.pop_back();  // ����ǰ��¼��������Ϊ��RS���Ѵ��ڸ�����¼
//                k--; // RS�м�¼������1
//                break; // ��Ϊ��ǰ�ļ�¼��ֻ���ܻ���RS�д洢��ĳһ����¼��ͬ������ֻҪƥ��һ��������
//            }
//        }
//        k++; // ��RS�м�¼������������1��������һ����¼�Ķ�ȡ
//	}
//	// �������
//	for(int i=0; i<k; ++i)
//	{
//		int exchange = 0;
//		for(int j=k-1; j>i; --j) // �����������ʡ���Ⱥ�˳����жϣ���Ϊ��ǰ��ļ�¼�����ȳ���
//		{
//			if(RS[j-1].SumCount < RS[j].SumCount) // ֻ��Ƚϳ��ִ�����������Ƚ��Ⱥ�˳��
//			{
//				ErrorInfo temp;
//				temp = RS[j-1];
//				RS[j-1] = RS[j];
//				RS[j] = temp;
//				exchange = 1;
//			}
//		}
//		if(exchange == 0)
//			break;
//	}
//    if(k>8)  // ֻȡǰ8����¼
//        k = 8;
//	for(int i=0; i<k; ++i)
//	{
//		if(RS[i].FileName.length() > 16) // ����ļ������ȴ���16��ȡ��16����Ч�ַ���Ϊ�ļ���
//			RS[i].FileName = RS[i].FileName.substr(RS[i].FileName.length()-16, 16);
//		cout<<RS[i].FileName<<" "<<RS[i].ErrorLineNo<<" "<<RS[i].SumCount<<endl;
//	}
//    return 0;
//}



//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//struct pair1{
//   string first;
//     int  second;
//     };
//int main()
//{
//    vector<pair1>file;
//    pair1 str;
//    int nub;
//    int countA=0;
//    char c='\\';
//    string temp;
//    int length;
//    while(getline(cin,temp))
//    {
// 
//        int j=temp.rfind(c,string::npos);
//        str.first=temp.substr(j+1,string::npos);
//        str.second=1;
//        file.push_back(str);
//        int count1=countA;
//        for(int i=0;i<count1;++i)
//		{
//            if(file[i].first==file[count1].first)
//            {
//				file[i].second++;
//                file.pop_back();//��ͬ�ļ�¼��Ҫ
//                countA--;
//            }
//		}
//       countA++;
//    }
// 
//    for(int k=0;k<countA;k++)
//    {
//        int pos=file[k].first.find(' ',0);
//        if(pos>16)
//			file[k].first.erase(0,pos-16);//����16���ַ����ļ�����ȥ
//    }
// 
//	for(int i=0;i<countA-1;++i)//�����ţ��õ���ԭʼ��ð��
//	{
//		for(int j=countA-1;j>i;--j)
//			if(file[j-1].second<file[j].second)
//			{
//				temp=file[j].first;
//				nub=file[j].second;
//				file[j].first=file[j-1].first;
//				file[j].second=file[j-1].second;
//				file[j-1].first=temp;
//				file[j-1].second=nub;
// 
//			}
//	}
//	if(countA>=8)
//		countA=8;
//	for(int i=0;i<countA;++i)
//	{
//		cout<<file[i].first<<" "<<file[i].second<<endl;
//	}
// 
//	return 0;
//}








//#include <iostream>
//#include <vector>
//#include <string>
//#include <string.h>
//using namespace std;
//struct ErrorInfo
//{
//	string FileName;
//	int ErrorLineNo;
//	int SumCount;
//	int AppearRank;
//};
//int main()
//{
////	ErrorInfo Record[8];
//	vector<ErrorInfo> Record;
////	memset(Record, 0, sizeof(Record));
//	string str;
//	int k=0;
//	while(getline(cin, str))
//	{
//		if(k<8)
//        {
//            int FileNameStartLoc = str.find_last_of('\\');
//            int FileNameEndLoc   = str.find_first_of(' ', FileNameStartLoc+1);
//            Record[k].FileName    = str.substr(FileNameStartLoc+1, FileNameEndLoc-FileNameStartLoc);
//            Record[k].ErrorLineNo = atoi(str.substr(FileNameEndLoc+1).c_str());
//            Record[k].SumCount++;
//            Record[k].AppearRank  = k+1;		
//            for(int i=0; i<k; ++i)
//            {
//                if(Record[k].FileName==Record[i].FileName && Record[k].ErrorLineNo==Record[i].ErrorLineNo)
//                {
//                    Record[i].SumCount++;
//                    Record[k].FileName    = "";
//                    Record[k].ErrorLineNo = 0;
//                    Record[k].SumCount    = 0;
//                    Record[k].AppearRank  = 0;
//                    k--;
//                    break;
//                }
//            }
//            k++;
//        }
//	}
//	// �������
//	for(int i=0; i<k; ++i)
//	{
//		int exchange = 0;
//		for(int j=1; j<k-i; ++j)
//		{
//			if(Record[j-1].SumCount > Record[j].SumCount)
//			{
//				ErrorInfo temp;
//				temp = Record[j-1];
//				Record[j-1] = Record[j];
//				Record[j] = temp;
//				exchange = 1;
//			}
//			else if(Record[j-1].SumCount==Record[j].SumCount && Record[j-1].AppearRank < Record[j].AppearRank)
//			{
//				ErrorInfo temp;
//				temp = Record[j-1];
//				Record[j-1] = Record[j];
//				Record[j] = temp;
//				exchange = 1;
//			}
//		}
//		if(exchange == 0)
//			break;
//	}
//	for(int i=k-1; i>=0; --i)
//	{
//		if(Record[i].FileName.length() > 16)
//			Record[i].FileName = Record[i].FileName.substr(Record[i].FileName.length()-17, 16);
//		cout<<Record[i].FileName<<" "<<Record[i].ErrorLineNo<<" "<<Record[i].SumCount<<endl;
//	}
//    return 0;
//}


