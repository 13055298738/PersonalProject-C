#include"Lib.h"
using namespace std;
int number_of_words=0;//记录单词统计总数
vector<string> raw_word;//文本中的单词集
vector<word> word_statistics;//统计结果集
        
int main(){
	/*初始化时间*/
   clock_t start,finish;
   double totaltime;
   start=clock();


   printf("Wait for a moment please.\n");


   /*定义缓存空间*/
   word w;
   char _word[MAX_LENGTH];


   vector<string>::iterator it,last;
   vector<word>::iterator wit;
	wordCount();
	characterCount();
	lineCount();
	outPut();
}
