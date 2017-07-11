//#include <iostream>
//#include <string.h>
//using namespace std;
//void main()
//{
//	char a[] = "123456789";
//	char s[] = "123";
//	strcpy(s, a);
//	printf("%s\n%s\n", a, s);
//
//	int n=10, a[n];
//}


//#include <regex>
//#include <iostream>
//#include <string>
//
//bool is_email_valid(const std::string& email)
//{
//   const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
//   return std::regex_match(email, pattern);
//}
//
//int main()
//{
//   std::string email1 = "\marius.bancila@domain.com";
//   std::string email2 = "mariusbancila@domain.com";
//   std::string email3 = "marius_b@domain.co.uk";
//   std::string email4 = "marius@domain";
//
//   std::cout << email1 << " : " << (is_email_valid(email1) ?
//      "valid" : "invalid") << std::endl;
//   std::cout << email2 << " : " << (is_email_valid(email2) ?
//      "valid" : "invalid") << std::endl;
//   std::cout << email3 << " : " << (is_email_valid(email3) ?
//     "valid" : "invalid") << std::endl;
//   std::cout << email4 << " : " << (is_email_valid(email4) ?
//     "valid" : "invalid") << std::endl;
//   return 0;
//}


#include <regex>
#include <iostream>
#include <string>
using namespace std;
bool is_email_valid(const string& email)
{
   //const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	//const regex pattern("^[\\w-]+(\\.[\\w-]+)*@[\\w-]+(\\.[\\w-]+)+$");
	//const regex pattern("^(\\w+)(\\.(\\w+))?@(\\w+)(\\.(\\w+))+$");
	//const regex pattern("^(\\+86)?[ ]?1[0-9]{2}[ |-]?[0-9]{4}[ |-]?[0-9]{4}$");
	const regex pattern("^(http[s]?:\\/\\/)?(\\w+)(\\.(\\w+))+$");
    return regex_match(email, pattern);
}

int main()
{
   //string email1 = "marius.bancila@domain.com";
   //string email2 = "mariusbancila@domain.com";
   //string email3 = "_marius_b@domain.co.uk";
   //string email4 = "marius@domain";
	//string email1 = "18875208911";
	//string email2 = "188 7520 8911";
	//string email3 = "188-7520-8911";
	//string email4 = "+86 188 7520 8911";
	string email1 = "www.baidu.com";
	string email2 = "http://www.baidu.com";
	string email3 = "https://baidu.com";
	string email4 = "https://www.baidu.com";

   cout << email1 << " : " << (is_email_valid(email1) ?
      "valid" : "invalid") << endl;
   cout << email2 << " : " << (is_email_valid(email2) ?
      "valid" : "invalid") << endl;
   cout << email3 << " : " << (is_email_valid(email3) ?
     "valid" : "invalid") << endl;
   cout << email4 << " : " << (is_email_valid(email4) ?
     "valid" : "invalid") << endl;
   return 0;
}





//#include <regex>
//#include <iostream>
//#include <string>
//
//int main()
//{
//   // regular expression
//   //const std::regex pattern("\\w+day");
//	const std::regex pattern("\\w+\\.{3}");
//   // the source text
//   std::string weekend = "Saturday. and Sunday., but some Fridays also...";
//   const std::sregex_token_iterator end;  //需要注意一下这里
//   for (std::sregex_token_iterator i(weekend.begin(),weekend.end(), pattern); i != end ; ++i)
//   {
//      std::cout << *i << std::endl;
//   }
//   std::cout<<std::endl;
//   return 0;
//}



//#include <regex>
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//   // regular expression
//   //const std::regex pattern("\\w+day");
//	const regex pattern("a.[0-9]");
//   // the source text
//   string weekend = "a^0dfa";
//   const sregex_token_iterator end;  //需要注意一下这里
//   for(sregex_token_iterator i(weekend.begin(),weekend.end(), pattern); i != end ; ++i)
//   {
//      cout << *i << std::endl;
//   }
//   cout<<endl;
//   return 0;
//}