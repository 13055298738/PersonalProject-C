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

