#include"Lib.h"
using namespace std;
int number_of_words=0;//��¼����ͳ������
vector<string> raw_word;//�ı��еĵ��ʼ�
vector<word> word_statistics;//ͳ�ƽ����
        
int main(){
	/*��ʼ��ʱ��*/
   clock_t start,finish;
   double totaltime;
   start=clock();


   printf("Wait for a moment please.\n");


   /*���建��ռ�*/
   word w;
   char _word[MAX_LENGTH];


   vector<string>::iterator it,last;
   vector<word>::iterator wit;
	wordCount();
	characterCount();
	lineCount();
	outPut();
}
