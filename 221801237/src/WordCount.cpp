#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>


using namespace std;
#define MAX_LENGTH 1<<10//���ʵ���󳤶�


typedef struct{
    string str;
    int wordcnt;
    int charcnt;
    int linecnt;
}word;


int number_of_words=0;//��¼����ͳ������
vector<string> raw_word;//��Դ�ı��еĵ��ʼ�
vector<word> word_statistics(10);//ͳ�ƽ����


/*�ֵ�����ȽϺ���*/
bool cmp_raw_word(const string &a,const string &b){
    return a<b;
	}


/*�ʻ���ִ�����������ȽϺ���*/
bool cmp_word_statistics(const word &a,const word &b){
    return a.wordcnt>b.wordcnt;
	}


/*���ȡ�Դ�����Դ�ļ�����Сд��ĸ������к��ּ��ַ�*/
bool skip(){
    scanf("%*[^a-z||A-Z]"); return true;
	}


int main(){

	
	/*���建��ռ�*/
	word w;
	char _word[MAX_LENGTH];
	
	
	vector<string>::iterator it,last;
	vector<word>::iterator wit;
	
	
	/*�ض����������� in.txt �ļ�,����ȡ in.txt �ļ�������Ӣ�ĵ���*/
	freopen("in.txt","r",stdin);
	while(skip()&&scanf("%[a-zA-Z]",_word)!=EOF){
	      number_of_words++;
	      /*��ֻ������ĸ��д�ĵ��ʵ�����ĸת����Сд*/
	    if(_word[1]!='\0'&&isupper(_word[0])&&islower(_word[1])) _word[0]|=1<<5;
	    raw_word.push_back(_word);
    }

    return 0; 
}
    
	 
