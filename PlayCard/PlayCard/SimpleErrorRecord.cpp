// 简单错误记录
// 开发一个简单错误记录功能小模块，能够记录出错的代码坐在的文件名称和行号。 
// 处理:
// 1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；
//   (文件所在的目录不同，文件名和行号相同也要合并)
// 2.超过16个字符的文件名称，只记录文件的最后有效16个字符；
//   (如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
// 3.输入的文件可能带路径，记录文件名称不能带路径

// 输入描述:
// 一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

//    文件路径为windows格式
//    如：E:\V1R2\product\fpgadrive.c 1325

// 输出描述:
// 将所有的记录统计并将结果输出，格式：文件名代码行数数目，一个空格隔开，如: fpgadrive.c 1325 1 

//   结果根据数目从多到少排序，数目相同的情况下，按照输入第一次出现顺序排序。
//   如果超过8条记录，则只输出前8条记录.
//   如果文件名的长度超过16个字符，则只输出后16个字符

// 输入例子:
// E:\V1R2\product\fpgadrive.c 1325

// 输出例子:
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
	// 排序输出
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
		  // 寻找最后一个'\'的位置
//        int FileNameStartLoc = str.find_last_of('\\');
		  // 寻找第一个空格所在位置
//        int FileNameEndLoc   = str.find_first_of(' ', FileNameStartLoc+1);
		  // 获取文件名，最后一个'\'和第一个空格之间的字符为文件名
//        Record.FileName    = str.substr(FileNameStartLoc+1, FileNameEndLoc-FileNameStartLoc-1);		
		  // 获取行号，文件名后面的字符为行号（除去空格字符）
//        Record.ErrorLineNo = atoi(str.substr(FileNameEndLoc+1).c_str());
		  // 记录出现的次数
//        Record.SumCount=1;
// 		  RS.push_back(Record); // 将当前记录放入RS中
//        for(int i=0; i<k; ++i)  // 合并文件名和行号都相同的记录
//        {
//            if(RS[k].FileName==RS[i].FileName && RS[k].ErrorLineNo==RS[i].ErrorLineNo)
//            {
//                RS[i].SumCount++;
//                RS.pop_back();  // 将当前记录弹出，因为在RS中已存在该条记录
//                k--; // RS中记录个数减1
//                break; // 因为当前的记录，只可能会与RS中存储的某一条记录相同，所以只要匹配一条就跳出
//            }
//        }
//        k++; // 将RS中记录个数计数器增1，进行下一条记录的读取
//	}
//	// 排序输出
//	for(int i=0; i<k; ++i)
//	{
//		int exchange = 0;
//		for(int j=k-1; j>i; --j) // 倒序排序可以省略先后顺序的判断，因为在前面的记录总是先出现
//		{
//			if(RS[j-1].SumCount < RS[j].SumCount) // 只需比较出现次数，而不需比较先后顺序
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
//    if(k>8)  // 只取前8条记录
//        k = 8;
//	for(int i=0; i<k; ++i)
//	{
//		if(RS[i].FileName.length() > 16) // 如果文件名长度大于16，取后16个有效字符作为文件名
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
//                file.pop_back();//相同的记录不要
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
//			file[k].first.erase(0,pos-16);//超过16个字符的文件名除去
//    }
// 
//	for(int i=0;i<countA-1;++i)//逆序排，用的最原始的冒泡
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
//	// 排序输出
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


