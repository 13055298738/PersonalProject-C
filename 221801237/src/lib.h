#pragma once
#ifndef LIB_H
#define LIB_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <ctime>
#include <cstdlib> 
#include <cmath>
#include <map>

using namespace std;
#define MAX_LENGTH 1<<10 //������󳤶�

class wordCount{
	public:
		
};
typedef struct{
	string str;
	int cnt;
}; word


int number_of_words=0;//��¼����ͳ������
vector<string> raw_word;//�ı��еĵ��ʼ�
vector<string> word_statistics;//ͳ�ƽ����


/*�ֵ�������*/
bool cmp_raw_word(const string &a,const string &b){
	return a<b;
}


/*���ʳ��ִ�������������*/
bool cmp_word_statistics(const word &a,const word &b){
	return a.cnt>b.cnt;
}


/*���ȡ�Դ�����Դ�ļ�����Сд��ĸ������к��ּ��ַ�*/
bool skip(){
    scanf("%*[^a-z||A-Z]"); return true;
}

#endif 
